#include "Client.h"

#include <omnetpp/clog.h>
#include <omnetpp/cmessage.h>
#include <omnetpp/cownedobject.h>
#include <omnetpp/cpar.h>
#include <omnetpp/csimulation.h>
#include <omnetpp/simtime.h>
#include <iostream>

#include "inet/common/packet/chunk/SequenceChunk.h"
#include "inet/common/packet/Packet.h"
#include "inet/common/Ptr.h"
#include "inet/common/Units.h"
#include "inet/networklayer/common/L3Address.h"
#include "inet/networklayer/common/L3AddressResolver.h"



#define MSGKIND_CONNECT    0
#define MSGKIND_SEND       1


void Client::initialize(int numstage){
    if(numstage == inet::INITSTAGE_LOCAL){
        updateRate = par("updateRate");
        sendPacketEvent = new cMessage("Client - send event");
        sendResources = new cMessage("Client - send resources");
    }

    if (numstage == inet::INITSTAGE_APPLICATION_LAYER){
        const char *remoteAddress= par("connectAddress");
        int remotePort = par("connectPort");
        clientSocket.setOutputGate(gate("socketOut"));
        clientSocket.setCallback(this);
        clientSocket.connect(inet::L3AddressResolver().resolve(remoteAddress), remotePort);
    }


    if (numstage == inet::INITSTAGE_LAST) {
        scheduleAt(simTime() + par("startTime"), sendResources);
    }
}

void Client::socketDataArrived(inet::TcpSocket *socket){

    auto socketQueue = socket->getReceiveQueue();
    //EV << packet->peekData() << endl;
    EV << simTime() << " CLIENT - Queue length " << socketQueue->getLength() << endl;
    while (socketQueue->has<MecControlMessage>()){
        auto message = socketQueue->pop<MecControlMessage>();
        EV << "CLIENT riceve - "
                << "    Msg Timestamp:" << message->getTimestamp()
                << "    Message ID:" << message->getMessageId()
                << "    Type:" << message->getCtlMsgType()
                << endl;
    }
    scheduleAt(simTime()+1, sendPacketEvent);
}


void Client::socketPeerClosed(inet::TcpSocket *socket) {
}

void Client::socketClosed(inet::TcpSocket *socket) {
}

void Client::socketFailure(inet::TcpSocket *socket, int code) {
}

void Client::socketAvailable(inet::TcpSocket *socket, inet::TcpAvailableInfo *availableInfo) {
    EV << "Client::socketAvailable" << endl;
}

void Client::socketStatusArrived(inet::TcpSocket *socket, inet::TcpStatusInfo *status) {
}

void Client::socketDeleted(inet::TcpSocket *socket) {
}

void Client::socketEstablished(inet::TcpSocket *socket) {
}


void Client::handleMessage(cMessage *msg){

    if (msg->isSelfMessage()){
        if(msg == sendResources){
            auto controlMessage = inet::makeShared<MecHelloMessage>();
            controlMessage->setSourceHost("MecHost1");
            controlMessage->setMessageId(messageId++);
            controlMessage->setTimestamp(simTime().dbl());

            auto cap = Resources();
            cap.setCpu(10);
            cap.setRam(20);
            cap.setDisk(30);
            cap.setNetwork(40);

            controlMessage->setCapabilities(cap);

            auto dataPacket = new inet::Packet("MEC HOST hello", controlMessage);
            clientSocket.send(dataPacket);
        }
        if(msg == sendPacketEvent){
            auto controlMessage = inet::makeShared<MecUpdateMessage>();
            controlMessage->setSourceHost("MecHost1");
            controlMessage->setMessageId(messageId++);
            controlMessage->setTimestamp(simTime().dbl());

            auto dataPacket = new inet::Packet("CLIENT->SERVER", controlMessage);
            clientSocket.send(dataPacket);
        }
    }
    else{
        if (clientSocket.belongsToSocket(msg)){ // match message and socket
            clientSocket.processMessage(msg); // invoke callback interface
        }
    }
}

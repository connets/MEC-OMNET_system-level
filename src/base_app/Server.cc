#include "Server.h"
#include "inet/networklayer/common/L3AddressResolver.h"


using namespace omnetpp;
using namespace inet;
using namespace std;

void Server::initialize(int numstage){
    if (numstage == INITSTAGE_LOCAL){
        //serverSocket= TcpSocket();
        //socketMap = SocketMap();
        sendPacketEvent = new cMessage("Send event");
    }

    if (numstage == INITSTAGE_APPLICATION_LAYER){
        // setup server socket
        int listeningPort = par("listeningPort");

        serverSocket.setOutputGate(gate("socketOut"));
        serverSocket.bind(L3AddressResolver().resolve(this->getParentModule()->getName()), listeningPort);
        serverSocket.setCallback(this);
        serverSocket.listen();
    }

}


void Server::socketDataArrived(TcpSocket *socket){

    auto socketQueue = socket->getReceiveQueue();
    //EV << packet->peekData() << endl;
    EV << simTime() << " SERVER - Queue length " << socketQueue->getLength() << endl;
    while (socketQueue->has<MecControlMessage>()){

        auto message = socketQueue->peek<MecControlMessage>();
        EV << "SERVER riceve - "
                << "    MsgTimestamp:" << message->getTimestamp()
                << "    Message ID:" << message->getMessageId()
                << "    Type:" << message->getCtlMsgType()
                << endl;

        auto controlMessage = inet::makeShared<MecUpdateMessage>();
        controlMessage->setSourceHost("MecOrchestrator");
        controlMessage->setTimestamp(simTime().dbl());
        Packet *dataPacket;
        //Ptr<const MecHostHelloMessage> helloMessage;

        switch(message->getCtlMsgType()){
//        case MEC_HOST_STATUS_UPDATE:
//            break;
        case MEC_HELLO_MESSAGE:{
            auto helloMessage = socketQueue->pop<MecHelloMessage>();
            auto cap = helloMessage->getCapabilities();
            EV << "Rilevato MEC HOST:" << helloMessage->getSourceHost()
                                               << "     CPU:" << cap.getCpu()
                                               << "     RAM:" << cap.getRam()
                                               << "     Disk:" << cap.getDisk()
                                               << "     Network:" << cap.getNetwork()
                                               << endl;
            dataPacket = new inet::Packet("MEC Orchestrator hello", controlMessage);

            auto newHost = new Host(helloMessage->getSourceHost(),cap);
            MECHosts.emplace(helloMessage->getSourceHost(), newHost);
            break;
        }
        default:
            socketQueue->pop<MecControlMessage>();
            dataPacket = new inet::Packet("SERVER->CLIENT", controlMessage);
            EV << "MEC Hosts registered: " << endl;
            for (auto i : MECHosts){
                EV << "Key: " << i.first << "\t";
                EV << "Value: " << i.second << endl;
            }
        }

        socket->send(dataPacket);

    }
}


void Server::socketAvailable(TcpSocket *socket, TcpAvailableInfo *availableInfo) {
    auto newSocket = new TcpSocket(availableInfo);
    newSocket->setCallback(this);
    newSocket->setOutputGate(gate("socketOut"));
    socketMap.addSocket(newSocket);
    serverSocket.accept(availableInfo->getNewSocketId());

}


void Server::handleMessage(cMessage *msg){
    if (msg->isSelfMessage()){

    }
    else{
        TcpSocket *socket = check_and_cast_nullable<TcpSocket*>(socketMap.findSocketFor(msg));
        if (socket){
            socket->processMessage(msg);
        }
        else{
            if (serverSocket.belongsToSocket(msg)) {
                serverSocket.processMessage(msg); // invoke callback interface
            }
            else{
                EV_ERROR << "Message " <<msg << " arrived, but it does not belong to any socket!" << endl;
            }
        }
    }


}

#include "MecApp.h"
#include "inet/networklayer/common/L3AddressResolver.h"

using namespace omnetpp;
using namespace inet;
using namespace std;

void MecApp::initialize (int numstage) {
    if (numstage == INITSTAGE_APPLICATION_LAYER) {
        hostName = getParentModule()->getName();
    }
}

void MecApp::sendMecControlMessage(inet::Ptr<const MecControlMessage> message) {

    auto dataPacket = new inet::Packet("MEC Control Message", message);
    orchestratorSocket.send(dataPacket);
}

void MecApp::socketDataArrived (TcpSocket *socket) {

    auto socketQueue = socket->getReceiveQueue();

    while (socketQueue->has<MecControlMessage>()) {

        auto message = socketQueue->peek<MecControlMessage>();

        switch (message->getCtlMsgType()) {

        case MEC_SERVICE_STARTED_MESSAGE:{
            auto message = socketQueue->pop<MecServiceStartedMessage>();
            processMecServiceStartedMessage(message);
            break;
        }
        default:{
            // non ci entra mai
        }
        }
    }
}

void MecApp::handleMessage (cMessage *msg) {

    // self message
    if (msg->isSelfMessage()){
        processSelfMessage(msg);
    }
    else{
        // orchestratorSocket
        if (orchestratorSocket.belongsToSocket(msg)) {
            orchestratorSocket.processMessage(msg);
        }
        else{
            throw invalid_argument( "msg arrived, but it does not belong to any socket!" );
        }

    }
}

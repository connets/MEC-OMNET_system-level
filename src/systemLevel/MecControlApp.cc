#include "../systemLevel/MecControlApp.h"

#include "inet/networklayer/common/L3AddressResolver.h"

using namespace omnetpp;
using namespace inet;
using namespace std;

void MecControlApp::initialize (int numstage) {
    if(numstage==INITSTAGE_LOCAL){
        hostName = internalGetHostName();
       // modulePathForResolve = internalGetModulePathForResolve();
    }
    if (numstage == INITSTAGE_APPLICATION_LAYER) {

           // setup serverSocket
           int listeningPort = par("listeningPort");
           serverSocket.setOutputGate(gate("socketOut"));
           serverSocket.bind(internalGetModulePathForResolve(), listeningPort);
           serverSocket.setCallback(this);
           serverSocket.listen();
       }
}

void MecControlApp::sendMecControlMessage(const char *dest, inet::Ptr<const MecControlMessage> message) {

    auto dataPacket = new inet::Packet("MEC Control Message", message);
    clientSocketMap[dest]->send(dataPacket);
}

void MecControlApp::socketDataArrived (TcpSocket *socket) {

    auto socketQueue = socket->getReceiveQueue();

    while (socketQueue->has<MecControlMessage>()) {

        auto message = socketQueue->peek<MecControlMessage>();

        switch (message->getCtlMsgType()) {

        case MEC_STATUS_UPDATE:{
            auto message = socketQueue->pop<MecUpdateMessage>();
            processMecUpdateMessage(message, socket);
            break;
        }
        case MEC_HELLO_MESSAGE:{
            auto message = socketQueue->pop<MecHelloMessage>();
            processMecHelloMessagge(message, socket);
            break;
        }
        case MEC_WELCOME_MESSAGE:{
            auto message = socketQueue->pop<MecWelcomeMessage>();
            processMecWelcomeMessage(message);
            break;
        }
        case MEC_REQUEST_SERVICE_MESSAGE:{
            auto message = socketQueue->pop<MecRequestServiceMessage>();
            processMecRequestServiceMessage(message);
            break;
        }
        case MEC_START_MEC_APP_MESSAGE:{
            auto message = socketQueue->pop<MecStartMecAppMessage>();
            processMecStartMecAppMessage(message);
            break;
        }
        case MEC_APP_STARTED_MESSAGE:{
            auto message = socketQueue->pop<MecAppStartedMessage>();
            processMecAppStartedMessage(message);
            break;
        }
        case MEC_APP_MIGRATION_MESSAGE:{
                    auto message = socketQueue->pop<MecAppMigrationMessage>();
                    processMecAppMigrationMessage(message);
                    break;
                }
        case MEC_APP_TRANSFERT_MESSAGE:{
                    auto message = socketQueue->pop<MecAppTransfertMessage>();
                    processMecAppTransfertMessage(message);
                    break;
                }
        default:{
            // non ci entra mai
        }
        }
    }
}


void MecControlApp::socketAvailable (TcpSocket *socket, TcpAvailableInfo *availableInfo) {
    auto newSocket = new TcpSocket(availableInfo);
    newSocket->setCallback(this);
    newSocket->setOutputGate(gate("socketOut"));
    auto module = L3AddressResolver().findHostWithAddress(availableInfo->getRemoteAddr());
    const char * sourceHost;
    string s(module->getName());
    //if necassario in quanto la mappa viene formata da <address,socket> ma dato che l' address viene preso dalla socket si crea ambiguita di nomi
    //dato che in entrambe i mec-host si ha la MecPlatform quindi serve distinguerli per il "parent"
    if(  s != "MecPlatform"){
          sourceHost = module->getName();
    }else{
       sourceHost =  module->getParentModule()->getName();
    }
    addClientSocketToMap(newSocket, sourceHost);
    serverSocket.accept(availableInfo->getNewSocketId());
}

void MecControlApp::handleMessage (cMessage *msg) {

    // self message
    if (msg->isSelfMessage()){
        processSelfMessage(msg);
    }
    else{
        // socketMap (client or server)
        TcpSocket *socket = check_and_cast_nullable<TcpSocket*>(socketMap.findSocketFor(msg));
        if (socket){
            socket->processMessage(msg);
        }
        else{
            // serverSocket
            if (serverSocket.belongsToSocket(msg)) {
                serverSocket.processMessage(msg);
            }
            else{
                throw invalid_argument( "msg arrived, but it does not belong to any socket!" );
            }
        }
    }
}

void MecControlApp::addClientSocketToMap (TcpSocket *newSocket, const char *dest){

    socketMap.addSocket(newSocket);
    clientSocketMap.insert(pair<const char *,TcpSocket *>(dest, newSocket));
}

void MecControlApp::connectClientSocket(const char *address, int port){

    auto clientSocket = new inet::TcpSocket();
    clientSocket->setOutputGate(gate("socketOut"));
    clientSocket->setCallback(this); // TODO risolvere adress da trovare
    clientSocket->connect(inet::L3AddressResolver().resolve(address), port);

    addClientSocketToMap(clientSocket, address);
}

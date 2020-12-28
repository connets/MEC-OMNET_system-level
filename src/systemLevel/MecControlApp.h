#include <stdio.h>
#include <string.h>
#include <stdexcept>
#include <omnetpp.h>

#include <omnetpp/cobjectfactory.h>
#include <omnetpp/csimplemodule.h>
#include <omnetpp/regmacros.h>

#include "../control_plane/messages/MecControlMessages_m.h"
#include "inet/common/InitStages.h"
#include "inet/common/socket/SocketMap.h"
#include "inet/transportlayer/contract/tcp/TcpSocket.h"
#include "inet/networklayer/common/L3AddressResolver.h"

using namespace omnetpp;
using namespace std;

class Host {

    protected:
        const char *mecHostId;
        Resources cap;

    public:

        Host(const char *mecHostId, Resources cap){
            this->mecHostId = mecHostId;
            this->cap = cap;
        }

        friend ostream & operator << (ostream &out, const Host &obj) {
            return out << "ID: " << obj.mecHostId << "\tCPU: " << obj.cap.getCpu() << endl;
        }
};

class MecControlApp : public cSimpleModule, public inet::TcpSocket::ReceiveQueueBasedCallback{

private:

protected:
    const char *hostName;
    //const char *modulePathForResolve;
    inet::TcpSocket serverSocket;
    inet::SocketMap socketMap;                          // < id, socket > used for incoming messages
    map<string, inet::TcpSocket *> clientSocketMap;     // < hostName, socket > used for outgoing messages


    virtual int numInitStages() const override { return inet::NUM_INIT_STAGES; }
    virtual void initialize(int numstage) override;
    virtual const char *internalGetHostName() const { return getParentModule()->getName(); }
    virtual inet::L3Address internalGetModulePathForResolve() const { return inet::L3AddressResolver().resolve(getParentModule()->getName()); }


    virtual void socketDataArrived(inet::TcpSocket *socket) override;
    virtual void socketAvailable(inet::TcpSocket *socket, inet::TcpAvailableInfo *availableInfo) override;
    virtual void socketEstablished(inet::TcpSocket *socket) override {};
    virtual void socketPeerClosed(inet::TcpSocket *socket) override {};
    virtual void socketClosed(inet::TcpSocket *socket) override {};
    virtual void socketFailure(inet::TcpSocket *socket, int code) override  {};
    virtual void socketStatusArrived(inet::TcpSocket *socket, inet::TcpStatusInfo *status) override  {};
    virtual void socketDeleted(inet::TcpSocket *socket) override  {};

    virtual void handleMessage(cMessage *msg) override;

    virtual void addClientSocketToMap (inet::TcpSocket *newSocket, const char *dest);
    virtual void connectClientSocket(const char *address, int port);
    virtual void sendMecControlMessage(const char *dest, inet::Ptr<const MecControlMessage> message);

    template <typename T> inet::Ptr<T> createMecControlMessage(){
        static_assert(std::is_base_of<MecControlMessage, T>::value, "Not derived from MecControlMessage");
        auto message = inet::makeShared<T>();
        message->setSourceHost(hostName);
        message->setTimestamp(simTime().dbl());

        return message;
    }

    virtual void processMecUpdateMessage(inet::Ptr<const MecUpdateMessage> message, inet::TcpSocket *socket){
        throw invalid_argument( "MecControlApp can't process Mec Host Update Messages" );
    }
    virtual void processMecHelloMessagge(inet::Ptr<const MecHelloMessage> message, inet::TcpSocket *socket){
        throw invalid_argument( "MecControlApp can't process Mec Host Hello Messages" );
    }
    virtual void processMecWelcomeMessage(inet::Ptr<const MecWelcomeMessage> message){
        throw invalid_argument( "MecControlApp can't process Mec Orchestrator Welcome Messages" );
    }
    virtual void processMecRequestServiceMessage(inet::Ptr<const MecRequestServiceMessage> message){
        throw invalid_argument( "MecControlApp can't process Mec Request Service Messages" );
    }
    virtual void processMecStartMecAppMessage(inet::Ptr<const MecStartMecAppMessage> message){
        throw invalid_argument( "MecControlApp can't process Mec Start MecApp Messages" );
    }
    virtual void processMecAppStartedMessage(inet::Ptr<const MecAppStartedMessage> message){
        throw invalid_argument( "MecControlApp can't process Mec App Started Messages" );
    }
    virtual void processSelfMessage(cMessage *msg){
        throw invalid_argument( "MecControlApp can't process a self message" );
    }
    virtual void processMecAppTransfertMessage(inet::Ptr<const MecAppTransfertMessage> message){
           throw invalid_argument( "MecControlApp can't process App transfert Messages" );
       }
    virtual void processMecAppMigrationMessage(inet::Ptr<const MecAppMigrationMessage> message){
           throw invalid_argument( "MecControlApp can't process App migrate Messages" );
       }

    //friend std::ostream& operator<<(std::ostream&, const A&);

public:
};

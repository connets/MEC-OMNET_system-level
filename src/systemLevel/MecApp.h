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

#include "inet/common/scenario/IScriptable.h"


using namespace omnetpp;
using namespace std;

class MecApp : public cSimpleModule, public inet::TcpSocket::ReceiveQueueBasedCallback, public inet::IScriptable{

private:

protected:
    inet::TcpSocket orchestratorSocket;
    const char *hostName;

    virtual int numInitStages() const override { return inet::NUM_INIT_STAGES; }
    virtual void initialize(int numstage) override;


    virtual void socketDataArrived(inet::TcpSocket *socket) override;
    virtual void socketAvailable(inet::TcpSocket *socket, inet::TcpAvailableInfo *availableInfo) override {};
    virtual void socketEstablished(inet::TcpSocket *socket) override {};
    virtual void socketPeerClosed(inet::TcpSocket *socket) override {};
    virtual void socketClosed(inet::TcpSocket *socket) override {};
    virtual void socketFailure(inet::TcpSocket *socket, int code) override  {};
    virtual void socketStatusArrived(inet::TcpSocket *socket, inet::TcpStatusInfo *status) override  {};
    virtual void socketDeleted(inet::TcpSocket *socket) override  {};

    virtual void handleMessage(cMessage *msg) override;





    virtual void sendMecControlMessage(inet::Ptr<const MecControlMessage> message);

    template <typename T> inet::Ptr<T> createMecControlMessage(){
        static_assert(std::is_base_of<MecControlMessage, T>::value, "Not derived from MecControlMessage");
        auto message = inet::makeShared<T>();
        message->setSourceHost(hostName);
        message->setTimestamp(simTime().dbl());

        return message;
    }

    virtual void processMecServiceStartedMessage(inet::Ptr<const MecServiceStartedMessage> message){
        throw invalid_argument( "MecApp can't process Mec Service Started Messages" );
    }
    virtual void processSelfMessage(cMessage *msg){
        throw invalid_argument( "MecApp can't process a self message" );
    }

/*
    virtual void process_orch_msg (inet::Ptr<const MecUpdateMessage> message, inet::TcpSocket *socket){
        throw invalid_argument( "MecControlApp can't process Mec Host Update Messages" );
    }
*/

public:
    virtual void processCommand(const cXMLElement& node) override{};
};

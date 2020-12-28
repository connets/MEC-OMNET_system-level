#include <omnetpp/cobjectfactory.h>
#include <omnetpp/csimplemodule.h>
#include <omnetpp/regmacros.h>

#include "../control_plane/messages/MecControlMessages_m.h"
#include "inet/common/InitStages.h"
#include "inet/transportlayer/contract/tcp/TcpSocket.h"


using namespace omnetpp;

class Client: public cSimpleModule, public inet::TcpSocket::ReceiveQueueBasedCallback
{
private:
    cMessage *sendResources;
    cMessage *sendPacketEvent;
    long messageId = 0;

protected:
    inet::TcpSocket clientSocket;

    double updateRate;

    virtual int numInitStages() const override { return inet::NUM_INIT_STAGES; }
    virtual void initialize(int numstage) override;

    virtual void socketDataArrived(inet::TcpSocket *socket) override;
    virtual void socketPeerClosed(inet::TcpSocket *socket) override;
    virtual void socketClosed(inet::TcpSocket *socket) override;
    virtual void socketFailure(inet::TcpSocket *socket, int code) override;
    virtual void socketAvailable(inet::TcpSocket *socket, inet::TcpAvailableInfo *availableInfo) override;
    virtual void socketStatusArrived(inet::TcpSocket *socket, inet::TcpStatusInfo *status) override;
    virtual void socketDeleted(inet::TcpSocket *socket) override;
    virtual void socketEstablished(inet::TcpSocket *socket) override;


    virtual void handleMessage(cMessage *msg) override;
};

Define_Module(Client);

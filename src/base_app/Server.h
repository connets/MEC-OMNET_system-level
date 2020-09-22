#include <stdio.h>
#include <string.h>
#include <omnetpp.h>

#include <omnetpp/cobjectfactory.h>
#include <omnetpp/csimplemodule.h>
#include <omnetpp/regmacros.h>

#include "inet/common/InitStages.h"
#include "inet/common/socket/SocketMap.h"
#include "inet/transportlayer/contract/tcp/TcpSocket.h"

//#include "inet/common/packet/Message.h"
//#include "inet/common/packet/chunk/ByteCountChunk.h"
//#include "inet/common/TimeTag_m.h"
//#include "inet/networklayer/common/L3AddressResolver.h"
//#include "inet/transportlayer/contract/tcp/TcpCommand_m.h"

#include "../control_plane/MecControlMessages_m.h"
#include <vector>

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



class Server : public cSimpleModule, public inet::TcpSocket::ReceiveQueueBasedCallback{

private:


protected:
    inet::TcpSocket serverSocket;
    inet::SocketMap socketMap;
    cMessage *sendPacketEvent;

    map<const char *, Host*> MECHosts;

    virtual int numInitStages() const override { return inet::NUM_INIT_STAGES; }
    virtual void initialize(int numstage) override;


    virtual void socketDataArrived(inet::TcpSocket *socket) override;
    virtual void socketAvailable(inet::TcpSocket *socket, inet::TcpAvailableInfo *availableInfo) override;
    virtual void socketEstablished(inet::TcpSocket *socket) override {};
    virtual void socketPeerClosed(inet::TcpSocket *socket) override {};
    virtual void socketClosed(inet::TcpSocket *socket) override {};
    virtual void socketFailure(inet::TcpSocket *socket, int code) override  {};
    virtual void socketStatusArrived(inet::TcpSocket *socket, inet::TcpStatusInfo *status) override  {};
    virtual void socketDeleted(inet::TcpSocket *socket) override  {};

    virtual void handleMessage(cMessage *msg) override;

public:
};

Define_Module(Server);

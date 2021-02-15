#include "../systemLevel/MecControlApp.h"

using namespace omnetpp;
using namespace std;

class MecOrchestratorApp: public MecControlApp{

private:

    map<const char *, Host*> MECHosts;
    int maxAppContainers;
    int actualContainers;
    cMessage* migrate;
protected:
    virtual void initialize(int numstage) override;
    virtual void processMecUpdateMessage(inet::Ptr<const MecUpdateMessage> message, inet::TcpSocket *socket) override;
    virtual void processMecHelloMessagge(inet::Ptr<const MecHelloMessage> message, inet::TcpSocket *socket) override;
    virtual void processMecRequestServiceMessage(inet::Ptr<const MecRequestServiceMessage> message) override;
    virtual void processMecAppStartedMessage(inet::Ptr<const MecAppStartedMessage> message) override;
    virtual void processSelfMessage(cMessage *msg) override;
    virtual void handleApplication(MecAppDescription application, const char *serviceName,const char *containerName);

public:

};

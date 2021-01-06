#include "../systemLevel/MecControlApp.h"
#include "inet/common/XMLUtils.h"

using namespace omnetpp;
using namespace std;
using namespace inet;

class MecPlatformApp: public MecControlApp{

private:

    cMessage *sendUpdate;
    cMessage *sendResources;
    int updateRate;
    int mecHostLspid;
    //void spawnAndConnectApp(string appName);
    void disconnectApp(string appName);
    void connectApp(string appName,bool migration=false);
    void route_label(string appName,bool migration);
    int readElementFromXml(const cXMLElement *fec,string dest,string element);
protected:

    virtual void initialize(int numstage) override;
    virtual const char *internalGetHostName() const override { return getParentModule()->getParentModule()->getName(); }
    virtual inet::L3Address internalGetModulePathForResolve() const override { return inet::L3AddressResolver().resolve(getParentModule()->getFullPath().c_str()); }
    virtual void processSelfMessage(cMessage *msg) override;
    virtual void processMecWelcomeMessage(inet::Ptr<const MecWelcomeMessage> message) override;
    virtual void processMecStartMecAppMessage(inet::Ptr<const MecStartMecAppMessage> message) override;
    virtual void processMecAppTransfertMessage(inet::Ptr<const MecAppTransfertMessage> message) override;
    virtual void processMecAppMigrationMessage(inet::Ptr<const MecAppMigrationMessage> message) override;

public:

};

#include "MecControlApp.h"

using namespace omnetpp;
using namespace std;

class MecPlatformApp: public MecControlApp{

private:

    cMessage *sendUpdate;
    cMessage *sendResources;
    int updateRate;

protected:

    virtual void initialize(int numstage) override;
    virtual void processSelfMessage(cMessage *msg) override;
    virtual void processMecWelcomeMessage(inet::Ptr<const MecWelcomeMessage> message) override;
    virtual void processMecStartMecAppMessage(inet::Ptr<const MecStartMecAppMessage> message) override;

public:

};

#include "../systemLevel/MecApp.h"

using namespace omnetpp;
using namespace std;

class MecUser: public MecApp{

private:

    cMessage *requestService;

protected:

    virtual void initialize(int numstage) override;
    virtual void processSelfMessage(cMessage *msg) override;
    virtual void processMecServiceStartedMessage (inet::Ptr<const MecServiceStartedMessage> message) override;

public:

};

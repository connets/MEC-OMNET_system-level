#include "../systemLevel/MecApp.h"

using namespace omnetpp;
using namespace std;
using namespace inet;

class MecUser: public MecApp{

private:

    cMessage *requestService;
    vector<inet::Ptr<MecRequestServiceMessage>> requestServiceQueue;

protected:

    virtual void initialize(int numstage) override;
    virtual void processSelfMessage(cMessage *msg) override;
    virtual void processMecServiceStartedMessage (inet::Ptr<const MecServiceStartedMessage> message) override;


public:
    virtual void processCommand(const cXMLElement& node) override;
};

#include "MecPlatformApp.h"

#include "inet/networklayer/common/L3AddressResolver.h"

Define_Module(MecPlatformApp);

void MecPlatformApp::initialize (int numstage) {

    MecControlApp::initialize(numstage);

    if (numstage == inet::INITSTAGE_LOCAL) {
        sendUpdate = new cMessage("Send event");
        sendResources = new cMessage("Send resources");
    }
    if (numstage == inet::INITSTAGE_APPLICATION_LAYER) {
       connectClientSocket(par("orchestratorAddress"), par("orchestratorPort"));
    }
    if (numstage == inet::INITSTAGE_LAST) {
        scheduleAt(simTime() + par("startTime"), sendResources);
    }
}

// da sistemare il modo in cui accedo alla clientSocketMap in base alla chiave
void MecPlatformApp::processSelfMessage(cMessage *msg){

    if(msg == sendResources){

        auto message = createMecControlMessage<MecHelloMessage>();

        auto cap = Resources();
        cap.setCpu(10);
        cap.setRam(20);
        cap.setDisk(30);
        cap.setNetwork(40);

        message->setCapabilities(cap);

        sendMecControlMessage(par("orchestratorAddress"), message);

        EV << "MEC PLATFORM send resources" << endl;
    }
    if(msg == sendUpdate){
        //delete msg;

        auto updateMsg = createMecControlMessage<MecUpdateMessage>();
        sendMecControlMessage(par("orchestratorAddress"), updateMsg);

        EV << "MEC PLATFORM send update message" << endl;

        scheduleAt(simTime() + updateRate, sendUpdate);
    }
}

void MecPlatformApp::processMecWelcomeMessage(inet::Ptr<const MecWelcomeMessage> message){

    updateRate = message->getUpdateRate();

    EV << "MEC PLATFORM: received welcome message from orchestrator" << endl;
    EV << "MEC PLATFORM: received updateRate of: " << updateRate << "s"<< endl;

    scheduleAt(simTime() + updateRate, sendUpdate);
}

void MecPlatformApp::processMecStartMecAppMessage(inet::Ptr<const MecStartMecAppMessage> message){

    EV << "MEC PLATFORM has received the mec start mecapp message" << endl;

    // do something to make the istance of the app working

    auto answerMessage = createMecControlMessage<MecAppStartedMessage>();
    answerMessage->setServiceName(message->getServiceName());
    answerMessage->setAppName(message->getMecApplication().getAppName());

    sendMecControlMessage(par("orchestratorAddress"), answerMessage);
}

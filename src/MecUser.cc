#include "MecUser.h"

#include "inet/networklayer/common/L3AddressResolver.h"

Define_Module(MecUser);

void MecUser::initialize (int numstage) {

    MecApp::initialize(numstage);

    if (numstage == inet::INITSTAGE_LOCAL) {
        requestService = new cMessage("Request Service");
    }
    if (numstage == inet::INITSTAGE_APPLICATION_LAYER) {
       const char *orchestratorAddress= par("orchestratorAddress");
       int orchestratorPort = par("orchestratorPort");
       orchestratorSocket.setOutputGate(gate("socketOut"));
       orchestratorSocket.setCallback(this);
       orchestratorSocket.connect(inet::L3AddressResolver().resolve(orchestratorAddress), orchestratorPort);
    }
    if (numstage == inet::INITSTAGE_LAST) {
        scheduleAt(simTime() + par("startTime"), requestService);
    }
}

// now the array of requested app has size 1
void MecUser::processSelfMessage(cMessage *msg){

    if(msg == requestService){

        auto application = MecAppDescription();

        const char *appName = "Application";
        auto res = Resources();
        res.setCpu(10);
        res.setRam(20);
        res.setDisk(30);
        res.setNetwork(40);
        auto qos = QoSRequirements();
        qos.setExpectedDelay(0.1);
        qos.setBandwidth(10.0);
        qos.setProcessingTime(0.2);

        application.setAppName(appName);
        application.setRequiredResources(res);
        application.setQosRequirements(qos);

        auto message = createMecControlMessage<MecRequestServiceMessage>();
        message->setMecApplicationsArraySize(1);
        message->setMecApplications(0, application);
        message->setServiceName("Service");

        sendMecControlMessage(message);

        EV << "USER requires service" << endl;
    }
}


void MecUser::processMecServiceStartedMessage (inet::Ptr<const MecServiceStartedMessage> message){
    EV << "USER got that the service with name " << message->getServiceName() << " has been started" << endl;
}


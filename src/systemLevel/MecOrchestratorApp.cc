#include "../systemLevel/MecOrchestratorApp.h"

#include "inet/networklayer/common/L3AddressResolver.h"

Define_Module(MecOrchestratorApp);

void MecOrchestratorApp::initialize (int numstage) {

    MecControlApp::initialize(numstage);
    if (numstage == inet::INITSTAGE_LAST) {
        maxAppContainers = par("maxAppNumber");
        actualContainers = 0;
        migrate = new cMessage("Migrate App");
        scheduleAt(simTime() +par("startTime"), migrate);
    }
// TODO schedulare messaggio per far partire la migrazione aggiustare tempo
}

void MecOrchestratorApp::processMecUpdateMessage(inet::Ptr<const MecUpdateMessage> message, inet::TcpSocket *socket){

    EV << "MEC ORCHESTRATOR: received update" << endl;
}

void MecOrchestratorApp::processMecHelloMessagge(inet::Ptr<const MecHelloMessage> message, inet::TcpSocket *socket){

    auto cap = message->getCapabilities();
    EV << "Rilevato MEC HOST: " << message->getSourceHost()
       << "     CPU:" << cap.getCpu()
       << "     RAM:" << cap.getRam()
       << "     Disk:" << cap.getDisk()
       << "     Network:" << cap.getNetwork()
       << endl;

    auto newHostname = message->getSourceHost();
    auto newHost = new Host(newHostname,cap);
    MECHosts.emplace(newHostname, newHost);

    auto welcomeMsg = createMecControlMessage<MecWelcomeMessage>();
    welcomeMsg->setUpdateRate(par("updateRate"));

    sendMecControlMessage(message->getSourceHost(), welcomeMsg);

    EV << "MEC ORCHESTRATOR send welcome message" << endl;
}

void MecOrchestratorApp::processMecRequestServiceMessage(inet::Ptr<const MecRequestServiceMessage> message){

    auto service = message->getServiceName();
    EV << "Service Required by User: " << service << endl;

    auto size = message->getMecApplicationsArraySize();

    for(int i=0;i<size;i++){
        actualContainers++;
        auto app = message->getMecApplications(i);
        auto appName = app.getAppName();
        auto res = app.getRequiredResources();
        auto qos = app.getQosRequirements();
        auto sContainerName = ("mecContainerApp[" + to_string(actualContainers-1)+"]");
        auto containerAppName = sContainerName.c_str();

        EV << "Application Name: " << appName << endl;
        EV << "Required Resources: "
           << "     CPU:" << res.getCpu()
           << "     RAM:" << res.getRam()
           << "     Disk:" << res.getDisk()
           << "     Network:" << res.getNetwork()
           << endl;
        EV << "Required QoS: "
           << "     Expected Delay: " << qos.getExpectedDelay()
           << "     Bandwidth: " << qos.getBandwidth()
           << "     Processing Time: " << qos.getProcessingTime()
           << endl;
        handleApplication(app,service,containerAppName);
    }
}

// TODO: how does the orchestrator choose the mec host?
void MecOrchestratorApp::handleApplication(MecAppDescription application, const char *serviceName,const char *containerName){

    if(!MECHosts.empty()){

        auto startMecAppMessage = createMecControlMessage<MecStartMecAppMessage>();
        startMecAppMessage->setServiceName(serviceName);
        startMecAppMessage->setMecApplication(application);
        startMecAppMessage->setContainerName(containerName);

        sendMecControlMessage("mecHost1", startMecAppMessage); // to fix

        EV << "MEC ORCHESTRATOR has sent a mec start mecapp message to mec host" << endl;
    }
}

// TODO:
// 1) the orchestrator has received that one app of the service has been started, but others app could exist
// 2) how does the orchestrator know that the service belongs to a specific user?
void MecOrchestratorApp::processMecAppStartedMessage(inet::Ptr<const MecAppStartedMessage> message){

    EV << "MEC ORCHESTRATOR got that the MecApp has been started" << endl;

    auto forwardMessage = createMecControlMessage<MecServiceStartedMessage>();
    forwardMessage->setServiceName(message->getServiceName());

    sendMecControlMessage("user", forwardMessage); // to fix
}


void MecOrchestratorApp::processSelfMessage(cMessage *msg){
    if(msg == migrate){
            EV << "MEC Orchestrator migrate app" << endl;
            auto message = createMecControlMessage<MecAppMigrationMessage>();
            message->setContainerAppName("mecContainerApp[0]");
            message->setDest("mecHost2");
            sendMecControlMessage("mecHost1", message);


        }
}

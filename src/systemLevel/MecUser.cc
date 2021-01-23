#include "../systemLevel/MecUser.h"
#include <any>
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

        const char *appName = "TcpEchoApp";
        auto res = Resources();
        res.setCpu(10);
        res.setRam(20);
        res.setDisk(30);
        res.setNetwork(40);
        auto qos = QoSRequirements();
        qos.setExpectedDelay(0.1);
        qos.setBandwidth(10.0);
        qos.setProcessingTime(0.2);
        auto parameters = parameterMap();
        //parameters.anymap.emplace("PARAM",new Any<int>(5));
        //int value = dynamic_cast<Any<int>&>(*parameters.anymap["PARAM"]).data;
        //EV << "VALUEEEEEEEEEEEE        " << value << endl;
        auto localport = new cIntParImpl();
        localport->setIntValue(1000);
        parameters.emplace("localPort",localport);
        auto echodelay = new cDoubleParImpl();
        echodelay->setDoubleValue(0.0);
        parameters.emplace("echoDelay",echodelay);
        auto echofactor = new cDoubleParImpl();
        echofactor->setDoubleValue(2.0);
        parameters.emplace("echoFactor",echofactor);
//        if(parameters.anymap["PAraAM"]->getType()== cParImpl::Type::BOOL)
//          EV<< "VALOREEEE SALVATOOO    " << parameters.anymap["PAraAM"]->boolValue(NULL) << endl;
        application.setAppName(appName);
        application.setRequiredResources(res);
        application.setQosRequirements(qos);
        application.setParameters(parameters);

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


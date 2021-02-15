#include "../systemLevel/MecUser.h"
#include <any>
#include "inet/networklayer/common/L3AddressResolver.h"
#include "inet/common/XMLUtils.h"



Define_Module(MecUser);
using namespace xmlutils;

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

        // scheduleAt(simTime() + par("startTime"), requestService);
    }
}

// now the array of requested app has size 1
void MecUser::processSelfMessage(cMessage *msg){

    if(msg == requestService){
        EV<< "LUNGHEZZA QUEUE::: SELFMESSAGE  " << requestServiceQueue.size() << endl;
        while (!requestServiceQueue.empty())
        {
            auto message = requestServiceQueue.back();
            requestServiceQueue.pop_back();
            sendMecControlMessage(message);
        }

        //        auto application = MecAppDescription();
        //
        //        const char *appName = "inet.applications.tcpapp.TcpEchoApp";
        //        auto res = Resources();
        //        res.setCpu(10);
        //        res.setRam(20);
        //        res.setDisk(30);
        //        res.setNetwork(40);
        //        auto qos = QoSRequirements();
        //        qos.setExpectedDelay(0.1);
        //        qos.setBandwidth(10.0);
        //        qos.setProcessingTime(0.2);
        //        auto parameters = parameterMap();
        //        //parameters.anymap.emplace("PARAM",new Any<int>(5));
        //        //int value = dynamic_cast<Any<int>&>(*parameters.anymap["PARAM"]).data;
        //        //EV << "VALUEEEEEEEEEEEE        " << value << endl;
        //        auto localport = new cIntParImpl();
        //        localport->setIntValue(1000);
        //        parameters.emplace("localPort",localport);
        //        auto echodelay = new cDoubleParImpl();
        //        echodelay->setDoubleValue(0.0);
        //        parameters.emplace("echoDelay",echodelay);
        //        auto echofactor = new cDoubleParImpl();
        //        echofactor->setDoubleValue(2.0);
        //        parameters.emplace("echoFactor",echofactor);
        //        //        if(parameters.anymap["PAraAM"]->getType()== cParImpl::Type::BOOL)
        //        //          EV<< "VALOREEEE SALVATOOO    " << parameters.anymap["PAraAM"]->boolValue(NULL) << endl;
        //        application.setAppName(appName);
        //        application.setRequiredResources(res);
        //        application.setQosRequirements(qos);
        //        application.setParameters(parameters);
        //
        //        auto message = createMecControlMessage<MecRequestServiceMessage>();
        //        message->setMecApplicationsArraySize(1);
        //        message->setMecApplications(0, application);
        //        message->setServiceName("Service");
        //        sendMecControlMessage(message);
        //
        //        EV << "USER requires service" << endl;
    }
}


void MecUser::processMecServiceStartedMessage (inet::Ptr<const MecServiceStartedMessage> message){
    EV << "USER got that the service with name " << message->getServiceName() << " has been started" << endl;
}





void MecUser::processCommand(const cXMLElement& node){
    int componentnumber = 0;
    auto message = createMecControlMessage<MecRequestServiceMessage>();
    const char *modulePath = getMandatoryAttribute(node, "module");
    //cModule *module = getSimulation()->getSystemModule()->getModuleByPath(modulePath);
    //MecUser *target = check_and_cast<MecUser *>(module);
    //EV << "modulo:"<< module << endl;
    auto serviceName = getMandatoryAttribute(node, "name");
    auto components = node.getFirstChild();
    cXMLElementList componentList = components->getChildrenByTagName("component");
    for (auto & cElem : componentList){
        auto application = MecAppDescription();
        componentnumber = componentnumber + 1;
        message->setMecApplicationsArraySize(componentnumber);
        auto componentName = cElem->getAttribute("name");
        EV << "COMPONENETE:"<< componentName << endl;
        auto moduleName = cElem->getFirstChildWithTag("module")->getAttribute("name");
        EV << "modulo:"<< moduleName << endl;
        auto res = Resources();
        auto resources = cElem->getFirstChildWithTag("resources");
        cXMLElementList resourceList = resources->getChildrenByTagName("resource");
        for (auto & resource : resourceList){
            auto str = resource->getAttribute("name");
            if(strcmp(str,"cpu") == 0)
                res.setCpu(stoi(resource->getAttribute("value")));
            else
                if(strcmp(str,"ram") == 0)
                    res.setRam(stoi(resource->getAttribute("value")));
                else
                    if(strcmp(str,"disk") == 0)
                        res.setDisk(stoi(resource->getAttribute("value")));
                    else
                        if(strcmp(str,"network") == 0)
                            res.setNetwork(stoi(resource->getAttribute("value")));

        }
        auto qos = QoSRequirements();
        auto requirements = cElem->getFirstChildWithTag("requirements");
        cXMLElementList requirementsList = requirements->getChildrenByTagName("required");
        for (auto & required : requirementsList){
            auto str = required->getAttribute("name");
            if(strcmp(str,"expectedDelay") == 0)
                qos.setExpectedDelay(stod(required->getAttribute("value")));
            else
                if (strcmp(str,"bandwith") == 0)
                    qos.setBandwidth(stod(required->getAttribute("value")));
                else
                    if (strcmp(str,"processingTime") == 0)
                        qos.setProcessingTime(stod(required->getAttribute("value")));

        }
        auto parameters = parameterMap();
        auto xmlParameters = cElem->getFirstChildWithTag("parameters");
        cXMLElementList parameterList = xmlParameters->getChildrenByTagName("param");
        for (auto & param : parameterList){
            auto str = param->getAttribute("type");
            if (strcmp(str,"int") == 0){
                auto parametro = new cIntParImpl();
                parametro->setIntValue(stoi(param->getAttribute("value")));
                parameters.emplace(param->getAttribute("name"),parametro);
            }else

                if (strcmp(str,"double") == 0){
                    auto parametro = new cDoubleParImpl();
                    parametro->setDoubleValue(stod(param->getAttribute("value")));
                    parameters.emplace(param->getAttribute("name"),parametro);
                }else
                    if (strcmp(str,"bool") == 0){
                        auto parametro = new cBoolParImpl();
                        auto bToCast = param->getAttribute("value");
                        bool value;
                        if(strcmp(bToCast, "1"))
                            value = true;
                        else if(strcmp(bToCast, "1"))
                            value = false;
                        parametro->setBoolValue(value);
                        parameters.emplace(param->getAttribute("name"),parametro);
                    }else
                        if (strcmp(str,"string") == 0){
                            auto parametro = new cStringParImpl();
                            parametro->setStringValue(param->getAttribute("value"));
                            parameters.emplace(param->getAttribute("name"),parametro);
                        }
        }
        application.setAppName(moduleName);
        application.setRequiredResources(res);
        application.setQosRequirements(qos);
        application.setParameters(parameters);
        message->setMecApplications(componentnumber - 1, application);

    }

    message->setServiceName(serviceName);
    requestServiceQueue.push_back(message);
    if(!requestService->isScheduled())
        scheduleAt(simTime(),requestService);


    //Enter_Method("sendMecControlMessage(message)");
    //take(message);
    EV<< "LUNGHEZZA QUEUE:::" << requestServiceQueue.size() << endl;
    EV << "USER requires service" << endl;
}


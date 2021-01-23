#include "../systemLevel/MecPlatformApp.h"

#include "../hostLevel/Arp_public.h"
#include "../hostLevel/MecAppDispatcher.h"
#include "../hostLevel/MecRsvpClassifier.h"
#include "inet/linklayer/ppp/Ppp.h"
#include "inet/networklayer/common/InterfaceEntry.h"
#include "inet/networklayer/ipv4/Ipv4RoutingTable.h"
#include "inet/networklayer/contract/ipv4/Ipv4Address.h"
#include "inet/networklayer/common/InterfaceTable.h"
#include "inet/networklayer/arp/ipv4/Arp.h"
#include "inet/networklayer/common/L3AddressResolver.h"

Define_Module(MecPlatformApp);

using namespace xmlutils;

void MecPlatformApp::initialize (int numstage) {

    //    if (numstage == inet::INITSTAGE_APPLICATION_LAYER) {
    //        hostName = (getParentModule()->getParentModule()->getName());
    //        // setup serverSocket
    //        int listeningPort = par("listeningPort");
    //        serverSocket.setOutputGate(gate("socketOut"));
    //        serverSocket.bind(inet::L3AddressResolver().resolve((this->getParentModule()->getFullPath()).c_str()), listeningPort);
    //        serverSocket.setCallback(this);
    //        serverSocket.listen();
    //    }
    //    EV <<  "MEC PLATFORM: " << internalGetModulePathForResolve()<< endl;
    MecControlApp::initialize(numstage);

    if (numstage == inet::INITSTAGE_LOCAL) {
        sendUpdate = new cMessage("Send event");
        sendResources = new cMessage("Send resources");
        string sHostName(hostName);
        string myName = sHostName + ".MecPlatform";
        mecHostLspid = readElementFromXml(par("fecFile"),myName,"lspid");
    }
    if (numstage == inet::INITSTAGE_APPLICATION_LAYER) {
        connectClientSocket(par("orchestratorAddress"), par("orchestratorPort"));
    }
    if (numstage == inet::INITSTAGE_LAST) {

        scheduleAt(simTime() + par("startTime"), sendResources);
    }
}





// da sistemare il modo in cui accedoXMLUtils alla clientSocketMap in base alla chiave
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
    auto appNamec = message->getMecApplication().getAppName();
    string appName(appNamec);
    string containerName = message->getContainerName();
    connectApp(containerName);
    createAppModule(appNamec, containerName,message->getMecApplication().getParameters());
    auto answerMessage = createMecControlMessage<MecAppStartedMessage>();
    answerMessage->setServiceName(message->getServiceName());
    answerMessage->setAppName(appNamec);

    sendMecControlMessage(par("orchestratorAddress"), answerMessage);
}
void MecPlatformApp::processMecAppMigrationMessage(inet::Ptr<const MecAppMigrationMessage> message){
    //per poter inviare il messaggio alll' altra platmorf mi serve piu del semplice nome uso connoct client socket
    EV << "MEC PLATFORM has received the mec migrate message" << endl;
    disconnectApp(message->getAppName());
    EV << "Applicazione disconessa invio messaggio alla platform destinazione" << endl;
    auto portDest  = 50002;
    string sDest(message->getDest());
    string sMecPlatformDest(sDest+".MecPlatform");
    connectClientSocket(sMecPlatformDest.c_str(), portDest);
    auto outmessage = createMecControlMessage<MecAppTransfertMessage>();
    outmessage->setAppName(message->getAppName());
    outmessage->setSourceHost(sMecPlatformDest.c_str());
    sendMecControlMessage(sMecPlatformDest.c_str(), outmessage);
}

void MecPlatformApp::processMecAppTransfertMessage(inet::Ptr<const MecAppTransfertMessage> message){
    EV << "MEC PLATFORM has received the mec transfert message" << endl;
    connectApp(message->getAppName(),true);
    EV << "Migrazione completata" << endl;
}

int MecPlatformApp::readElementFromXml(const cXMLElement *fec,string dest , string element){
    cXMLElementList list = fec->getChildrenByTagName("fecentry");
    for (auto & elem : list){
        string destination = getParameterStrValue(elem, "destination");
        if (destination == dest ){
            return getParameterIntValue(elem,element.c_str());
        }
    }
    return -1;
}

void MecPlatformApp::processAndAssignParameter(cPar &moduleParameter,cParImpl * parameterValue){
    switch(parameterValue->getType()){
    case cParImpl::Type::BOOL:
        moduleParameter =  parameterValue->boolValue(NULL);
        break;
    case cParImpl::Type::DOUBLE:
        moduleParameter =  parameterValue->doubleValue(NULL);
        break;
    case cParImpl::Type::INT:
        moduleParameter =  parameterValue->intValue(NULL);
        break;
    case cParImpl::Type::XML:
        moduleParameter =  parameterValue->xmlValue(NULL);
        break;
    case cParImpl::Type::STRING:
        moduleParameter =  parameterValue->stringValue(NULL);
        break;
    }
}

/**void MecPlatformApp::spawnAndConnectApp(string appName){
    const char * c0 = appName.c_str();
    string mecHostString(this->getParentModule()->getParentModule()->getFullName());
    const char * mecHost = mecHostString.c_str();
    string mecHostMadString = mecHostString + ".mad";
    const char * mecHostMad = mecHostMadString.c_str();

    cModule *mecAppToSpawn = getModuleByPath(c0);
    cModule *vSwitchMod = getModuleByPath(mecHost);
    cModule *vSwitchMadMod = getModuleByPath(mecHostMad);
    EV << "Current app gates " << vSwitchMod->gateSize("vEthInt")<< endl;
    vSwitchMod->setGateSize("vEthInt", vSwitchMod->gateSize("vEthInt") + 1);
    vSwitchMadMod->setGateSize("toApps", vSwitchMadMod->gateSize("toApps") +1);

    cGate *madGate_out= vSwitchMadMod->gate("toApps$o", vSwitchMadMod->gateSize("toApps")-1); //the last created gate
    cGate *madGate_in= vSwitchMadMod->gate("toApps$i", vSwitchMadMod->gateSize("toApps")-1); //the last created gate

    cGate *vSwitchGate_out =vSwitchMod->gate("vEthInt$o", vSwitchMod->gateSize("vEthInt")-1); //the last created gate
    cGate *vSwitchGate_in =vSwitchMod->gate("vEthInt$i", vSwitchMod->gateSize("vEthInt")-1); //the last created gate

    cGate *appGate_out = mecAppToSpawn->gate("vEth$o");
    cGate *appGate_in = mecAppToSpawn->gate("vEth$i");

    // internal vSwitch connections
    madGate_out->connectTo(vSwitchGate_out);
    vSwitchGate_in->connectTo(madGate_in);

    appGate_out->connectTo(vSwitchGate_in);
    vSwitchGate_out->connectTo(appGate_in);

    // Adding on MecAppDispatcher map the app.
    // NumApp -- GateOutMecAppDispatcher
    // TODO qui prende gate id metterlo in connect poi è ugulae

    MecAppDispatcher *madModule = check_and_cast<MecAppDispatcher*>(vSwitchMadMod);

    string mecAppAddr = appName + ".vm.eth[0]";
    const char * macAddr = mecAppAddr.c_str();

    inet::InterfaceEntry *ethApp = check_and_cast<inet::InterfaceEntry*>(getModuleByPath(macAddr));
    inet::MacAddress addr = ethApp->getMacAddress();

    madModule->addMap(addr,madGate_out->getId());
    EV << "Inserted in MecAppDispatcher address: " << addr << " ; gate: " << madGate_out->getId() <<endl;
    // end here
    // update routing table
    string mecAppRT = appName + ".vm.ipv4.routingTable";
    const char * c1 = mecAppRT.c_str();
    inet::Ipv4RoutingTable *vm_routing_table = check_and_cast<inet::Ipv4RoutingTable*>(getModuleByPath(c1));

    vector<inet::Ipv4Address> vm_external_addr  = vector<inet::Ipv4Address>();
    for (auto addr : vm_routing_table->gatherAddresses())
        if (! (addr.getAddressCategory() == inet::Ipv4Address::AddressCategory::LOOPBACK))
            vm_external_addr.push_back(addr);

    string mecAppIT = appName + ".vm.interfaceTable";
    const char * c2 = mecAppIT.c_str();

    inet::InterfaceEntry *vm_eth_interface = check_and_cast<inet::InterfaceTable*>(getModuleByPath(c2))->findInterfaceByName("eth0");
    inet::Ipv4Route *vm_tableEntry = new inet::Ipv4Route();
    vm_tableEntry->setInterface(vm_eth_interface);
    vm_routing_table->addRoute(vm_tableEntry);

}
 */
void MecPlatformApp::createAppModule(string appName,string containerName,map<std::string, omnetpp::cParImpl *> parameter){
    cModuleType *moduleType = cModuleType::get("inet.applications.tcpapp.TcpEchoApp");
    const char * parentName = (containerName + ".vm").c_str();
    cModule *module = moduleType->create(appName.c_str(), getModuleByPath(parentName));
    auto it = parameter.begin();
    while (it != parameter.end())
    {
        // Accessing KEY from element pointed by it.
        string sParam = it->first;
        // Accessing VALUE from element pointed by it.

        processAndAssignParameter(module->par(sParam.c_str()), it->second);

        // Increment the Iterator to point to next entry
        it++;
    }
    module->finalizeParameters();
    //mpls_network2.mecApp[0].vm.at.out[0]--> app[0].socketIn
    //mpls_network2.mecApp[0].vm.app[0].socketOut--> at.in[0]
    cModule *at = getModuleByPath((containerName + ".vm.at").c_str());
    numGate++;
    at->setGateSize("out", numGate);
    at->setGateSize("in", numGate);
    at->gate("out",(numGate-1))->connectTo(module->gate("socketIn"));
    module->gate("socketOut")->connectTo(at->gate("in",(numGate-1)));
    module->buildInside();
    module->scheduleStart(simTime()+1);
    for(int i = 0;i < 15;i++){
        module->callInitialize(i);
    }
}



void MecPlatformApp::disconnectApp(string appName){
    const char * mecApp = appName.c_str();

    cModule *appToMigrate = getModuleByPath(mecApp);
    cModule *macHost = this->getParentModule()->getParentModule();
    string macHostName(macHost->getFullName());  //name o fullname ??
    cModule *mecHostFrom = (macHost);

    //Scollegala
    cGate *appGate_out = appToMigrate->gate("vEth$o");  //portare fuori queste 2 var

    //the correct created gate della mecapp -> appGateMap[mecApp[0]]

    const char * dispatcher = (macHostName + ".mad").c_str();
    MecAppDispatcher *dispFrom = check_and_cast<MecAppDispatcher*>(getModuleByPath(dispatcher));


    string macAddrApp = appName + ".vm.eth[0]";
    const char * macAddr = macAddrApp.c_str();
    inet::InterfaceEntry *ethApp = check_and_cast<inet::InterfaceEntry*>(getModuleByPath(macAddr));
    inet::MacAddress addr = ethApp->getMacAddress();

    int gateId = dispFrom->findGateId(addr); //gate id da portare fuori (fino a qui)
    cGate *vSwitchSource_out = mecHostFrom->gate(gateId);
    dispFrom->eraseMap(addr);

    // GATE MAD DA DISCONNETTERE (?) SI

    appGate_out->disconnect();
    //    vSwitchSource_out->getNextGate()->disconnect();
    vSwitchSource_out->getPreviousGate()->disconnect();
    vSwitchSource_out->disconnect();

}
void MecPlatformApp::connectApp(string appName,bool migration){
    string mecHostDestName(this->getParentModule()->getParentModule()->getFullName());
    cModule *mecHostDest = getModuleByPath(mecHostDestName.c_str());
    cModule *mecHostMadDest = getModuleByPath((mecHostDestName + ".mad").c_str());

    mecHostDest->setGateSize("vEthInt", mecHostDest->gateSize("vEthInt") + 1);
    mecHostMadDest->setGateSize("toApps", mecHostMadDest->gateSize("toApps") +1);


    string macAddrApp = appName + ".vm.eth[0]";
    const char * macAddr = macAddrApp.c_str();
    const char * mecApp = appName.c_str();
    cModule *appMigrating = getModuleByPath(mecApp);
    inet::InterfaceEntry *ethApp = check_and_cast<inet::InterfaceEntry*>(getModuleByPath(macAddr));
    inet::MacAddress addr = ethApp->getMacAddress();



    cGate *appGate_out = appMigrating->gate("vEth$o");
    cGate *appGate_in = appMigrating->gate("vEth$i");

    cGate *madGate_out= mecHostMadDest->gate("toApps$o", mecHostMadDest->gateSize("toApps")-1); //the last created gate
    cGate *madGate_in= mecHostMadDest->gate("toApps$i", mecHostMadDest->gateSize("toApps")-1); //the last created gate

    cGate *mecHostGate_out = mecHostDest->gate("vEthInt$o", mecHostDest->gateSize("vEthInt")-1); //the last created gate
    cGate *mecHostGate_in = mecHostDest->gate("vEthInt$i", mecHostDest->gateSize("vEthInt")-1); //the last created gate



    MecAppDispatcher *madModule = check_and_cast<MecAppDispatcher*>(mecHostMadDest);
    madModule->addMap(addr,madGate_out->getId());
    //SIGNALS

    //    cModule *vm = getModuleByPath((mecAppString + ".vm.ppp[0].ppp").c_str());
    //    inet::Ppp * pppggate = check_and_cast<inet::Ppp *> (vm);
    //    EV << "modulo ppp subscribed: "<< isSubscribed(POST_MODEL_CHANGE, pppggate) << endl;
    //    unsubscribe(POST_MODEL_CHANGE, pppggate);

    //

    madGate_out->connectTo(mecHostGate_out);
    mecHostGate_in->connectTo(madGate_in);
    appGate_out->connectTo(mecHostGate_in);
    mecHostGate_out->connectTo(appGate_in);

    //Aggiorna il router esterno

    route_label(appName,migration);
}

void MecPlatformApp::route_label(string appName,bool migration){
    //solo post migrazione
    //    EV << "Aggiungo la route..." << "router_ext.classifier" << endl;
    //  EV << "Aggiungo la route..." << "router_"<< to <<".classifier" << endl;
    //const char * router_dest = ("router_"+ to + ".classifier").c_str(); // non dovrebbe cambaire, vengono aggiunte in tutti
    //if necessario per cambiare le route solo nel caso della migrazione
    if(migration == true){
        string router_dest = "router_ext.classifier";
        MecRsvpClassifier *userClassifier = check_and_cast<MecRsvpClassifier*>(getModuleByPath(router_dest.c_str()));

        //    userClassifier->add_in_table(3, 3, 300, "user");

        int id = readElementFromXml(par("fecFile"), appName + ".vm", "id");
        int tunnel_id = readElementFromXml(par("fecFile"), appName + ".vm", "tunnel_id");
        const char * dest = (appName + ".vm").c_str();
        //    userClassifier->remove_from_table(4);
        userClassifier->add_in_table(id,tunnel_id, mecHostLspid, dest);
        EV<<"Aggiunto bind con corretta label switch path verso " << dest << endl;
    }
    // AGGIUNGO COSE CHE MI TOGLIE QUESTO PROCEDIMENTO copia incolla dalla spawn

    string mecAppRT = appName + ".vm.ipv4.routingTable";
    const char * c1 = mecAppRT.c_str();
    inet::Ipv4RoutingTable *vm_routing_table = check_and_cast<inet::Ipv4RoutingTable*>(getModuleByPath(c1));

    std::vector<inet::Ipv4Address> vm_external_addr  = std::vector<inet::Ipv4Address>();
    for (auto addr : vm_routing_table->gatherAddresses())
        if (! (addr.getAddressCategory() == inet::Ipv4Address::AddressCategory::LOOPBACK))
            vm_external_addr.push_back(addr);

    std::string mecAppIT = appName + ".vm.interfaceTable";
    const char * c2 = mecAppIT.c_str();

    inet::InterfaceEntry *vm_eth_interface = check_and_cast<inet::InterfaceTable*>(getModuleByPath(c2))->findInterfaceByName("eth0");
    inet::Ipv4Route *vm_tableEntry = new inet::Ipv4Route();
    vm_tableEntry->setInterface(vm_eth_interface);
    vm_routing_table->addRoute(vm_tableEntry);



    //const char * arp_module_string = ("mecApp["+ std::to_string(numMecApp)+ "].vm.ipv4.arp").c_str();
    //solo post migrazione
    std::string arp_module_string = appName + ".vm.ipv4.arp";
    Arp_public *arp_module = check_and_cast<Arp_public*>(getModuleByPath(arp_module_string.c_str()));

    arp_module->flush_public();

}



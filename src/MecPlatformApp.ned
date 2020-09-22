package mec_simple;

simple MecPlatformApp like IMecControlApp
{
    parameters:
        
        @class(MecPlatformApp);
        
        int listeningPort = default(1000);
        
        string orchestratorAddress = default("MEC_orchestrator");
        int orchestratorPort = default(1000);
        double startTime @unit(s) = default(0s);
 	
    gates:
        input socketIn @labels(Server/up);
        output socketOut @labels(Server/down);
}




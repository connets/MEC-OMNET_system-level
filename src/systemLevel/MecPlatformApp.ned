package mec_simple.systemLevel;

simple MecPlatformApp like IMecControlApp
{
    parameters:
        
        @class(MecPlatformApp);
        
        int listeningPort = default(1000);
        
        string orchestratorAddress = default("mecOrchestrator");
        int orchestratorPort = default(1000);
        double startTime @unit(s) = default(10s);
        xml fecFile;
 	
    gates:
        input socketIn @labels(Server/up);
        output socketOut @labels(Server/down);
}




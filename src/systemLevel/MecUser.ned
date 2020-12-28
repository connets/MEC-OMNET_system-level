package mec_simple.systemLevel;

import inet.applications.contract.IApp;

simple MecUser like IApp{
    
    parameters:
        
        @class(MecUser);
        
        string orchestratorAddress = default("mecOrchestrator");
        int orchestratorPort = default(1000);
        double startTime @unit(s) = default(30s);
 	
    gates:
        input socketIn;
        output socketOut;    
}

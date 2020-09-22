package mec_simple;

import inet.applications.contract.IApp;

simple MecUser like IApp{
    
    parameters:
        
        @class(MecUser);
        
        string orchestratorAddress = default("MEC_orchestrator");
        int orchestratorPort = default(1000);
        double startTime @unit(s) = default(0s);
 	
    gates:
        input socketIn;
        output socketOut;    
}

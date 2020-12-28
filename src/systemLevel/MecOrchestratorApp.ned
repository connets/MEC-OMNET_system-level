package mec_simple.systemLevel;

simple MecOrchestratorApp like IMecControlApp
{
    parameters:
        
        @class(MecOrchestratorApp);
        
        int listeningPort = default(1000);
        
        string connectAddress = default("");  // server address (may be symbolic)
        int connectPort = default(1000); // port number to connect to
        double updateRate @unit(s) = default(0s);
 		int maxAppNumber = default(1);
 		double startTime @unit(s) = default(90s);
    gates:
        input socketIn @labels(Server/up);
        output socketOut @labels(Server/down);
}

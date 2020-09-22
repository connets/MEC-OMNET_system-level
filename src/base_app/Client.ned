package mec_simple.base_app;

import inet.applications.contract.IApp;


simple Client like IApp
{
    parameters:
        string connectAddress = default("");  // server address (may be symbolic)
        int connectPort = default(1000); // port number to connect to
        double startTime @unit(s) = default(1s); // time first session begins
        double updateRate @unit(hz) = default(10hz);
    gates:
        input socketIn @labels(Client/up);
        output socketOut @labels(Client/down);

}

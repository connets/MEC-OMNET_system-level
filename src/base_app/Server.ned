package mec_simple.base_app;

import inet.applications.contract.IApp;

simple Server like IApp
{
    parameters:
        int listeningPort = default(1000);
    gates:
        input socketIn @labels(Server/up);
        output socketOut @labels(Server/down);
}

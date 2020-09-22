package mec_simple;

import inet.networklayer.configurator.ipv4.Ipv4NetworkConfigurator;
import inet.node.ethernet.EtherSwitch;
import inet.node.inet.Router;
import inet.node.inet.StandardHost;
import inet.node.inet.WirelessHost;
import inet.physicallayer.contract.packetlevel.IRadioMedium;
import inet.visualizer.contract.IIntegratedVisualizer;


network MEC
{
    @display("bgb=757.03754,462.7525");
    @figure[title](type=label; pos=0,-1; anchor=sw; color=darkblue);

    types:
        channel Channel extends ned.DatarateChannel
        {
            delay = 1ms;
            datarate = 10Mbps;
        }

        channel ChannelBackbone extends ned.DatarateChannel
        {
            delay = 10ms;
            datarate = 100Mbps;
        }

    submodules:

        MEC_orchestrator: StandardHost {
            @display("p=628.02124,104.4925");
        }
        MEC_host: StandardHost {
            @display("p=538.45624,411.5725");
        }
        Mec_User: WirelessHost {
            @display("p=278.29126,89.565");
        }

        configurator: Ipv4NetworkConfigurator {
            @display("p=40.60875,52.0625");
        }
        visualizer: <default("IntegratedVisualizer")> like IIntegratedVisualizer {

            @display("p=40.60875,137.445");
        }
        radioMedium: <default("UnitDiskRadioMedium")> like IRadioMedium {
            @display("p=40.60875,220.74501");
        }

        switch1: EtherSwitch {
            @display("p=458.48752,155.6725");
        }
        switch2: EtherSwitch {
            @display("p=339.0675,346.53125");
        }
        router1: Router {
            @display("p=339.0675,236.7075");
        }
        router2: Router {
            @display("p=548.0525,287.8875");
        }
    connections:
        MEC_orchestrator.ethg++ <--> Channel <--> switch1.ethg++;
        switch1.ethg++ <--> Channel <--> router1.ethg++;
        router1.pppg++ <--> ChannelBackbone <--> router2.pppg++;
        router2.ethg++ <--> Channel <--> switch2.ethg++;
        switch2.ethg++ <--> Channel <--> MEC_host.ethg++;
}

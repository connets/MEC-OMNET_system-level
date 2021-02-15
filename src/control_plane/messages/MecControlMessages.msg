//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
//

import inet.common.INETDefs;
import inet.common.packet.chunk.Chunk;

cplusplus {{
        #include <map>
        #include <omnetpp.h>
        //        //typedef std::map<std::string, std::string> stringMap;  //secondo parametro template c++ 
        ////        class AnyBase
        ////        {
        ////                public:
        ////                virtual ~AnyBase() = 0;
        ////                virtual getData
        ////        };
        ////        inline AnyBase::~AnyBase() {}
        //        
        //        template<class T>
        //        class Any //: public AnyBase
        //        {
        //                public:
        //                typedef T Type;
        //                explicit Any(const Type& data) : data(data) {}
        //                Any() {}
        //                Type data;
        //        };
        //        
        //        
        //        template<typename T>
        
        typedef std::map<std::string, omnetpp::cParImpl *> parameterMap;
        
        //std::map<std::string, std::unique_ptr<AnyBase>> anymap;

}}

enum ControlMessageType{
        MEC_HELLO_MESSAGE = 0;
        MEC_STATUS_UPDATE = 1;
        MEC_WELCOME_MESSAGE = 2;
        MEC_REQUEST_SERVICE_MESSAGE = 3;	// user -> orchestrator
        MEC_START_MEC_APP_MESSAGE = 4;		// orchestrator -> platform
        MEC_APP_STARTED_MESSAGE = 5; 		// platform -> orchestrator
        MEC_SERVICE_STARTED_MESSAGE = 6; 	// orchestrator -> user
        MEC_APP_TRANSFERT_MESSAGE = 7;       // platform -> platform
        MEC_APP_MIGRATION_MESSAGE = 8;      // orchestrator -> platform
}

class parameterMap{
        @existingClass;
}

//struct stringMap{
//        @existingClass;
//}

class Resources {
        int cpu;
        int ram;
        int disk;
        int network;
}

class QoSRequirements {
        double expectedDelay;
        double bandwidth;
        double processingTime;
}

class MecAppDescription {
        string appName;
        Resources requiredResources;
        QoSRequirements qosRequirements;
        parameterMap parameters;
}

class MecControlMessage extends inet::FieldsChunk{
        long messageId;
        string sourceHost;
        ControlMessageType ctlMsgType;
        double timestamp;
}

class MecUpdateMessage extends MecControlMessage{
        chunkLength = inet::B(400);
        ctlMsgType = MEC_STATUS_UPDATE;
        double memoryCapacityUsed;
        double computationalCapacityUsed;
        double storageCapacityUsed;
        double networkCapacityUsed;
};

class MecHelloMessage extends MecControlMessage{
        chunkLength = inet::B(200);
        ctlMsgType = MEC_HELLO_MESSAGE;
        Resources capabilities;
}

class MecWelcomeMessage extends MecControlMessage{
        chunkLength = inet::B(200);
        ctlMsgType = MEC_WELCOME_MESSAGE;
        double updateRate;
}

// user -> orchestrator
class MecRequestServiceMessage extends MecControlMessage{
        chunkLength = inet::B(200);
        ctlMsgType = MEC_REQUEST_SERVICE_MESSAGE;
        string serviceName;
        MecAppDescription mecApplications[];
}

// orchestrator -> platform
class MecStartMecAppMessage extends MecControlMessage{
        chunkLength = inet::B(200);
        ctlMsgType = MEC_START_MEC_APP_MESSAGE;
        string serviceName;
        MecAppDescription mecApplication;
        string containerName;
}

// platform -> orchestrator
class MecAppStartedMessage extends MecControlMessage{
        chunkLength = inet::B(200);
        ctlMsgType = MEC_APP_STARTED_MESSAGE;
        string serviceName;
        string appName;
}

// orchestrator -> user 	probably to change something, for example insert the qos and resources parameters
class MecServiceStartedMessage extends MecControlMessage{
        chunkLength = inet::B(200);
        ctlMsgType = MEC_SERVICE_STARTED_MESSAGE;
        string serviceName;
}
//platform->platform
class MecAppTransfertMessage extends MecControlMessage{
        chunkLength = inet::B(5*1024);
        ctlMsgType = MEC_APP_TRANSFERT_MESSAGE;
        string containerAppName;
}
//orchestrator->platform
class MecAppMigrationMessage extends MecControlMessage{
        chunkLength = inet::B(200);
        ctlMsgType = MEC_APP_MIGRATION_MESSAGE;
        string containerAppName;
        string dest;
        
}

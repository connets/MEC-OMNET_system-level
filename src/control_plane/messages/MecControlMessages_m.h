//
// Generated file, do not edit! Created by nedtool 5.6 from control_plane/messages/MecControlMessages.msg.
//

#ifndef __MECCONTROLMESSAGES_M_H
#define __MECCONTROLMESSAGES_M_H

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0506
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif



class Resources;
class QoSRequirements;
class MecAppDescription;
class MecControlMessage;
class MecUpdateMessage;
class MecHelloMessage;
class MecWelcomeMessage;
class MecRequestServiceMessage;
class MecStartMecAppMessage;
class MecAppStartedMessage;
class MecServiceStartedMessage;
class MecAppTransfertMessage;
class MecAppMigrationMessage;
#include "inet/common/INETDefs_m.h" // import inet.common.INETDefs

#include "inet/common/packet/chunk/Chunk_m.h" // import inet.common.packet.chunk.Chunk

// cplusplus {{
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
// }}

/**
 * Enum generated from <tt>control_plane/messages/MecControlMessages.msg:50</tt> by nedtool.
 * <pre>
 * enum ControlMessageType
 * {
 *     MEC_HELLO_MESSAGE = 0;
 *     MEC_STATUS_UPDATE = 1;
 *     MEC_WELCOME_MESSAGE = 2;
 *     MEC_REQUEST_SERVICE_MESSAGE = 3;	// user -> orchestrator
 *     MEC_START_MEC_APP_MESSAGE = 4;		// orchestrator -> platform
 *     MEC_APP_STARTED_MESSAGE = 5; 		// platform -> orchestrator
 *     MEC_SERVICE_STARTED_MESSAGE = 6; 	// orchestrator -> user
 *     MEC_APP_TRANSFERT_MESSAGE = 7;       // platform -> platform
 *     MEC_APP_MIGRATION_MESSAGE = 8;      // orchestrator -> platform
 * }
 * </pre>
 */
enum ControlMessageType {
    MEC_HELLO_MESSAGE = 0,
    MEC_STATUS_UPDATE = 1,
    MEC_WELCOME_MESSAGE = 2,
    MEC_REQUEST_SERVICE_MESSAGE = 3,
    MEC_START_MEC_APP_MESSAGE = 4,
    MEC_APP_STARTED_MESSAGE = 5,
    MEC_SERVICE_STARTED_MESSAGE = 6,
    MEC_APP_TRANSFERT_MESSAGE = 7,
    MEC_APP_MIGRATION_MESSAGE = 8
};

/**
 * Class generated from <tt>control_plane/messages/MecControlMessages.msg:70</tt> by nedtool.
 * <pre>
 * class Resources
 * {
 *     int cpu;
 *     int ram;
 *     int disk;
 *     int network;
 * }
 * </pre>
 */
class Resources
{
  protected:
    int cpu = 0;
    int ram = 0;
    int disk = 0;
    int network = 0;

  private:
    void copy(const Resources& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const Resources&);

  public:
    Resources();
    Resources(const Resources& other);
    virtual ~Resources();
    Resources& operator=(const Resources& other);
    virtual void parsimPack(omnetpp::cCommBuffer *b) const;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b);

    // field getter/setter methods
    virtual int getCpu() const;
    virtual void setCpu(int cpu);
    virtual int getRam() const;
    virtual void setRam(int ram);
    virtual int getDisk() const;
    virtual void setDisk(int disk);
    virtual int getNetwork() const;
    virtual void setNetwork(int network);
};

/**
 * Class generated from <tt>control_plane/messages/MecControlMessages.msg:77</tt> by nedtool.
 * <pre>
 * class QoSRequirements
 * {
 *     double expectedDelay;
 *     double bandwidth;
 *     double processingTime;
 * }
 * </pre>
 */
class QoSRequirements
{
  protected:
    double expectedDelay = 0;
    double bandwidth = 0;
    double processingTime = 0;

  private:
    void copy(const QoSRequirements& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const QoSRequirements&);

  public:
    QoSRequirements();
    QoSRequirements(const QoSRequirements& other);
    virtual ~QoSRequirements();
    QoSRequirements& operator=(const QoSRequirements& other);
    virtual void parsimPack(omnetpp::cCommBuffer *b) const;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b);

    // field getter/setter methods
    virtual double getExpectedDelay() const;
    virtual void setExpectedDelay(double expectedDelay);
    virtual double getBandwidth() const;
    virtual void setBandwidth(double bandwidth);
    virtual double getProcessingTime() const;
    virtual void setProcessingTime(double processingTime);
};

/**
 * Class generated from <tt>control_plane/messages/MecControlMessages.msg:83</tt> by nedtool.
 * <pre>
 * class MecAppDescription
 * {
 *     string appName;
 *     Resources requiredResources;
 *     QoSRequirements qosRequirements;
 *     parameterMap parameters;
 * }
 * </pre>
 */
class MecAppDescription
{
  protected:
    omnetpp::opp_string appName;
    Resources requiredResources;
    QoSRequirements qosRequirements;
    parameterMap parameters;

  private:
    void copy(const MecAppDescription& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const MecAppDescription&);

  public:
    MecAppDescription();
    MecAppDescription(const MecAppDescription& other);
    virtual ~MecAppDescription();
    MecAppDescription& operator=(const MecAppDescription& other);
    virtual void parsimPack(omnetpp::cCommBuffer *b) const;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b);

    // field getter/setter methods
    virtual const char * getAppName() const;
    virtual void setAppName(const char * appName);
    virtual const Resources& getRequiredResources() const;
    virtual Resources& getRequiredResourcesForUpdate() { return const_cast<Resources&>(const_cast<MecAppDescription*>(this)->getRequiredResources());}
    virtual void setRequiredResources(const Resources& requiredResources);
    virtual const QoSRequirements& getQosRequirements() const;
    virtual QoSRequirements& getQosRequirementsForUpdate() { return const_cast<QoSRequirements&>(const_cast<MecAppDescription*>(this)->getQosRequirements());}
    virtual void setQosRequirements(const QoSRequirements& qosRequirements);
    virtual const parameterMap& getParameters() const;
    virtual parameterMap& getParametersForUpdate() { return const_cast<parameterMap&>(const_cast<MecAppDescription*>(this)->getParameters());}
    virtual void setParameters(const parameterMap& parameters);
};

/**
 * Class generated from <tt>control_plane/messages/MecControlMessages.msg:90</tt> by nedtool.
 * <pre>
 * class MecControlMessage extends inet::FieldsChunk
 * {
 *     long messageId;
 *     string sourceHost;
 *     ControlMessageType ctlMsgType;
 *     double timestamp;
 * }
 * </pre>
 */
class MecControlMessage : public ::inet::FieldsChunk
{
  protected:
    long messageId = 0;
    omnetpp::opp_string sourceHost;
    ControlMessageType ctlMsgType = static_cast<ControlMessageType>(-1);
    double timestamp = 0;

  private:
    void copy(const MecControlMessage& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const MecControlMessage&);

  public:
    MecControlMessage();
    MecControlMessage(const MecControlMessage& other);
    virtual ~MecControlMessage();
    MecControlMessage& operator=(const MecControlMessage& other);
    virtual MecControlMessage *dup() const override {return new MecControlMessage(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual long getMessageId() const;
    virtual void setMessageId(long messageId);
    virtual const char * getSourceHost() const;
    virtual void setSourceHost(const char * sourceHost);
    virtual ControlMessageType getCtlMsgType() const;
    virtual void setCtlMsgType(ControlMessageType ctlMsgType);
    virtual double getTimestamp() const;
    virtual void setTimestamp(double timestamp);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const MecControlMessage& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, MecControlMessage& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>control_plane/messages/MecControlMessages.msg:97</tt> by nedtool.
 * <pre>
 * class MecUpdateMessage extends MecControlMessage
 * {
 *     chunkLength = inet::B(400);
 *     ctlMsgType = MEC_STATUS_UPDATE;
 *     double memoryCapacityUsed;
 *     double computationalCapacityUsed;
 *     double storageCapacityUsed;
 *     double networkCapacityUsed;
 * }
 * </pre>
 */
class MecUpdateMessage : public ::MecControlMessage
{
  protected:
    double memoryCapacityUsed = 0;
    double computationalCapacityUsed = 0;
    double storageCapacityUsed = 0;
    double networkCapacityUsed = 0;

  private:
    void copy(const MecUpdateMessage& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const MecUpdateMessage&);

  public:
    MecUpdateMessage();
    MecUpdateMessage(const MecUpdateMessage& other);
    virtual ~MecUpdateMessage();
    MecUpdateMessage& operator=(const MecUpdateMessage& other);
    virtual MecUpdateMessage *dup() const override {return new MecUpdateMessage(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual double getMemoryCapacityUsed() const;
    virtual void setMemoryCapacityUsed(double memoryCapacityUsed);
    virtual double getComputationalCapacityUsed() const;
    virtual void setComputationalCapacityUsed(double computationalCapacityUsed);
    virtual double getStorageCapacityUsed() const;
    virtual void setStorageCapacityUsed(double storageCapacityUsed);
    virtual double getNetworkCapacityUsed() const;
    virtual void setNetworkCapacityUsed(double networkCapacityUsed);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const MecUpdateMessage& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, MecUpdateMessage& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>control_plane/messages/MecControlMessages.msg:106</tt> by nedtool.
 * <pre>
 * class MecHelloMessage extends MecControlMessage
 * {
 *     chunkLength = inet::B(200);
 *     ctlMsgType = MEC_HELLO_MESSAGE;
 *     Resources capabilities;
 * }
 * </pre>
 */
class MecHelloMessage : public ::MecControlMessage
{
  protected:
    Resources capabilities;

  private:
    void copy(const MecHelloMessage& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const MecHelloMessage&);

  public:
    MecHelloMessage();
    MecHelloMessage(const MecHelloMessage& other);
    virtual ~MecHelloMessage();
    MecHelloMessage& operator=(const MecHelloMessage& other);
    virtual MecHelloMessage *dup() const override {return new MecHelloMessage(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual const Resources& getCapabilities() const;
    virtual Resources& getCapabilitiesForUpdate() { handleChange();return const_cast<Resources&>(const_cast<MecHelloMessage*>(this)->getCapabilities());}
    virtual void setCapabilities(const Resources& capabilities);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const MecHelloMessage& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, MecHelloMessage& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>control_plane/messages/MecControlMessages.msg:112</tt> by nedtool.
 * <pre>
 * class MecWelcomeMessage extends MecControlMessage
 * {
 *     chunkLength = inet::B(200);
 *     ctlMsgType = MEC_WELCOME_MESSAGE;
 *     double updateRate;
 * }
 * </pre>
 */
class MecWelcomeMessage : public ::MecControlMessage
{
  protected:
    double updateRate = 0;

  private:
    void copy(const MecWelcomeMessage& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const MecWelcomeMessage&);

  public:
    MecWelcomeMessage();
    MecWelcomeMessage(const MecWelcomeMessage& other);
    virtual ~MecWelcomeMessage();
    MecWelcomeMessage& operator=(const MecWelcomeMessage& other);
    virtual MecWelcomeMessage *dup() const override {return new MecWelcomeMessage(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual double getUpdateRate() const;
    virtual void setUpdateRate(double updateRate);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const MecWelcomeMessage& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, MecWelcomeMessage& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>control_plane/messages/MecControlMessages.msg:119</tt> by nedtool.
 * <pre>
 * // user -> orchestrator
 * class MecRequestServiceMessage extends MecControlMessage
 * {
 *     chunkLength = inet::B(200);
 *     ctlMsgType = MEC_REQUEST_SERVICE_MESSAGE;
 *     string serviceName;
 *     MecAppDescription mecApplications[];
 * }
 * </pre>
 */
class MecRequestServiceMessage : public ::MecControlMessage
{
  protected:
    omnetpp::opp_string serviceName;
    MecAppDescription *mecApplications = nullptr;
    size_t mecApplications_arraysize = 0;

  private:
    void copy(const MecRequestServiceMessage& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const MecRequestServiceMessage&);

  public:
    MecRequestServiceMessage();
    MecRequestServiceMessage(const MecRequestServiceMessage& other);
    virtual ~MecRequestServiceMessage();
    MecRequestServiceMessage& operator=(const MecRequestServiceMessage& other);
    virtual MecRequestServiceMessage *dup() const override {return new MecRequestServiceMessage(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual const char * getServiceName() const;
    virtual void setServiceName(const char * serviceName);
    virtual void setMecApplicationsArraySize(size_t size);
    virtual size_t getMecApplicationsArraySize() const;
    virtual const MecAppDescription& getMecApplications(size_t k) const;
    virtual MecAppDescription& getMecApplicationsForUpdate(size_t k) { handleChange();return const_cast<MecAppDescription&>(const_cast<MecRequestServiceMessage*>(this)->getMecApplications(k));}
    virtual void setMecApplications(size_t k, const MecAppDescription& mecApplications);
    virtual void insertMecApplications(const MecAppDescription& mecApplications);
    virtual void insertMecApplications(size_t k, const MecAppDescription& mecApplications);
    virtual void eraseMecApplications(size_t k);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const MecRequestServiceMessage& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, MecRequestServiceMessage& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>control_plane/messages/MecControlMessages.msg:127</tt> by nedtool.
 * <pre>
 * // orchestrator -> platform
 * class MecStartMecAppMessage extends MecControlMessage
 * {
 *     chunkLength = inet::B(200);
 *     ctlMsgType = MEC_START_MEC_APP_MESSAGE;
 *     string serviceName;
 *     MecAppDescription mecApplication;
 *     string containerName;
 * }
 * </pre>
 */
class MecStartMecAppMessage : public ::MecControlMessage
{
  protected:
    omnetpp::opp_string serviceName;
    MecAppDescription mecApplication;
    omnetpp::opp_string containerName;

  private:
    void copy(const MecStartMecAppMessage& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const MecStartMecAppMessage&);

  public:
    MecStartMecAppMessage();
    MecStartMecAppMessage(const MecStartMecAppMessage& other);
    virtual ~MecStartMecAppMessage();
    MecStartMecAppMessage& operator=(const MecStartMecAppMessage& other);
    virtual MecStartMecAppMessage *dup() const override {return new MecStartMecAppMessage(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual const char * getServiceName() const;
    virtual void setServiceName(const char * serviceName);
    virtual const MecAppDescription& getMecApplication() const;
    virtual MecAppDescription& getMecApplicationForUpdate() { handleChange();return const_cast<MecAppDescription&>(const_cast<MecStartMecAppMessage*>(this)->getMecApplication());}
    virtual void setMecApplication(const MecAppDescription& mecApplication);
    virtual const char * getContainerName() const;
    virtual void setContainerName(const char * containerName);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const MecStartMecAppMessage& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, MecStartMecAppMessage& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>control_plane/messages/MecControlMessages.msg:136</tt> by nedtool.
 * <pre>
 * // platform -> orchestrator
 * class MecAppStartedMessage extends MecControlMessage
 * {
 *     chunkLength = inet::B(200);
 *     ctlMsgType = MEC_APP_STARTED_MESSAGE;
 *     string serviceName;
 *     string appName;
 * }
 * </pre>
 */
class MecAppStartedMessage : public ::MecControlMessage
{
  protected:
    omnetpp::opp_string serviceName;
    omnetpp::opp_string appName;

  private:
    void copy(const MecAppStartedMessage& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const MecAppStartedMessage&);

  public:
    MecAppStartedMessage();
    MecAppStartedMessage(const MecAppStartedMessage& other);
    virtual ~MecAppStartedMessage();
    MecAppStartedMessage& operator=(const MecAppStartedMessage& other);
    virtual MecAppStartedMessage *dup() const override {return new MecAppStartedMessage(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual const char * getServiceName() const;
    virtual void setServiceName(const char * serviceName);
    virtual const char * getAppName() const;
    virtual void setAppName(const char * appName);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const MecAppStartedMessage& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, MecAppStartedMessage& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>control_plane/messages/MecControlMessages.msg:144</tt> by nedtool.
 * <pre>
 * // orchestrator -> user 	probably to change something, for example insert the qos and resources parameters
 * class MecServiceStartedMessage extends MecControlMessage
 * {
 *     chunkLength = inet::B(200);
 *     ctlMsgType = MEC_SERVICE_STARTED_MESSAGE;
 *     string serviceName;
 * }
 * </pre>
 */
class MecServiceStartedMessage : public ::MecControlMessage
{
  protected:
    omnetpp::opp_string serviceName;

  private:
    void copy(const MecServiceStartedMessage& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const MecServiceStartedMessage&);

  public:
    MecServiceStartedMessage();
    MecServiceStartedMessage(const MecServiceStartedMessage& other);
    virtual ~MecServiceStartedMessage();
    MecServiceStartedMessage& operator=(const MecServiceStartedMessage& other);
    virtual MecServiceStartedMessage *dup() const override {return new MecServiceStartedMessage(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual const char * getServiceName() const;
    virtual void setServiceName(const char * serviceName);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const MecServiceStartedMessage& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, MecServiceStartedMessage& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>control_plane/messages/MecControlMessages.msg:150</tt> by nedtool.
 * <pre>
 * //platform->platform
 * class MecAppTransfertMessage extends MecControlMessage
 * {
 *     chunkLength = inet::B(5*1024);
 *     ctlMsgType = MEC_APP_TRANSFERT_MESSAGE;
 *     string containerAppName;
 * }
 * </pre>
 */
class MecAppTransfertMessage : public ::MecControlMessage
{
  protected:
    omnetpp::opp_string containerAppName;

  private:
    void copy(const MecAppTransfertMessage& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const MecAppTransfertMessage&);

  public:
    MecAppTransfertMessage();
    MecAppTransfertMessage(const MecAppTransfertMessage& other);
    virtual ~MecAppTransfertMessage();
    MecAppTransfertMessage& operator=(const MecAppTransfertMessage& other);
    virtual MecAppTransfertMessage *dup() const override {return new MecAppTransfertMessage(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual const char * getContainerAppName() const;
    virtual void setContainerAppName(const char * containerAppName);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const MecAppTransfertMessage& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, MecAppTransfertMessage& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>control_plane/messages/MecControlMessages.msg:156</tt> by nedtool.
 * <pre>
 * //orchestrator->platform
 * class MecAppMigrationMessage extends MecControlMessage
 * {
 *     chunkLength = inet::B(200);
 *     ctlMsgType = MEC_APP_MIGRATION_MESSAGE;
 *     string containerAppName;
 *     string dest;
 * 
 * }
 * </pre>
 */
class MecAppMigrationMessage : public ::MecControlMessage
{
  protected:
    omnetpp::opp_string containerAppName;
    omnetpp::opp_string dest;

  private:
    void copy(const MecAppMigrationMessage& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const MecAppMigrationMessage&);

  public:
    MecAppMigrationMessage();
    MecAppMigrationMessage(const MecAppMigrationMessage& other);
    virtual ~MecAppMigrationMessage();
    MecAppMigrationMessage& operator=(const MecAppMigrationMessage& other);
    virtual MecAppMigrationMessage *dup() const override {return new MecAppMigrationMessage(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual const char * getContainerAppName() const;
    virtual void setContainerAppName(const char * containerAppName);
    virtual const char * getDest() const;
    virtual void setDest(const char * dest);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const MecAppMigrationMessage& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, MecAppMigrationMessage& obj) {obj.parsimUnpack(b);}

#endif // ifndef __MECCONTROLMESSAGES_M_H


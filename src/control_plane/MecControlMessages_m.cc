//
// Generated file, do not edit! Created by nedtool 5.6 from control_plane/MecControlMessages.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wshadow"
#  pragma clang diagnostic ignored "-Wconversion"
#  pragma clang diagnostic ignored "-Wunused-parameter"
#  pragma clang diagnostic ignored "-Wc++98-compat"
#  pragma clang diagnostic ignored "-Wunreachable-code-break"
#  pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#  pragma GCC diagnostic ignored "-Wshadow"
#  pragma GCC diagnostic ignored "-Wconversion"
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#  pragma GCC diagnostic ignored "-Wold-style-cast"
#  pragma GCC diagnostic ignored "-Wsuggest-attribute=noreturn"
#  pragma GCC diagnostic ignored "-Wfloat-conversion"
#endif

#include <iostream>
#include <sstream>
#include <memory>
#include "MecControlMessages_m.h"

namespace omnetpp {

// Template pack/unpack rules. They are declared *after* a1l type-specific pack functions for multiple reasons.
// They are in the omnetpp namespace, to allow them to be found by argument-dependent lookup via the cCommBuffer argument

// Packing/unpacking an std::vector
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::vector<T,A>& v)
{
    int n = v.size();
    doParsimPacking(buffer, n);
    for (int i = 0; i < n; i++)
        doParsimPacking(buffer, v[i]);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::vector<T,A>& v)
{
    int n;
    doParsimUnpacking(buffer, n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        doParsimUnpacking(buffer, v[i]);
}

// Packing/unpacking an std::list
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::list<T,A>& l)
{
    doParsimPacking(buffer, (int)l.size());
    for (typename std::list<T,A>::const_iterator it = l.begin(); it != l.end(); ++it)
        doParsimPacking(buffer, (T&)*it);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::list<T,A>& l)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        l.push_back(T());
        doParsimUnpacking(buffer, l.back());
    }
}

// Packing/unpacking an std::set
template<typename T, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::set<T,Tr,A>& s)
{
    doParsimPacking(buffer, (int)s.size());
    for (typename std::set<T,Tr,A>::const_iterator it = s.begin(); it != s.end(); ++it)
        doParsimPacking(buffer, *it);
}

template<typename T, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::set<T,Tr,A>& s)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        T x;
        doParsimUnpacking(buffer, x);
        s.insert(x);
    }
}

// Packing/unpacking an std::map
template<typename K, typename V, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::map<K,V,Tr,A>& m)
{
    doParsimPacking(buffer, (int)m.size());
    for (typename std::map<K,V,Tr,A>::const_iterator it = m.begin(); it != m.end(); ++it) {
        doParsimPacking(buffer, it->first);
        doParsimPacking(buffer, it->second);
    }
}

template<typename K, typename V, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::map<K,V,Tr,A>& m)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        K k; V v;
        doParsimUnpacking(buffer, k);
        doParsimUnpacking(buffer, v);
        m[k] = v;
    }
}

// Default pack/unpack function for arrays
template<typename T>
void doParsimArrayPacking(omnetpp::cCommBuffer *b, const T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimPacking(b, t[i]);
}

template<typename T>
void doParsimArrayUnpacking(omnetpp::cCommBuffer *b, T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimUnpacking(b, t[i]);
}

// Default rule to prevent compiler from choosing base class' doParsimPacking() function
template<typename T>
void doParsimPacking(omnetpp::cCommBuffer *, const T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimPacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

template<typename T>
void doParsimUnpacking(omnetpp::cCommBuffer *, T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimUnpacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

}  // namespace omnetpp

namespace {
template <class T> inline
typename std::enable_if<std::is_polymorphic<T>::value && std::is_base_of<omnetpp::cObject,T>::value, void *>::type
toVoidPtr(T* t)
{
    return (void *)(static_cast<const omnetpp::cObject *>(t));
}

template <class T> inline
typename std::enable_if<std::is_polymorphic<T>::value && !std::is_base_of<omnetpp::cObject,T>::value, void *>::type
toVoidPtr(T* t)
{
    return (void *)dynamic_cast<const void *>(t);
}

template <class T> inline
typename std::enable_if<!std::is_polymorphic<T>::value, void *>::type
toVoidPtr(T* t)
{
    return (void *)static_cast<const void *>(t);
}

}


// forward
template<typename T, typename A>
std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec);

// Template rule to generate operator<< for shared_ptr<T>
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const std::shared_ptr<T>& t) { return out << t.get(); }

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const T&) {return out;}

// operator<< for std::vector<T>
template<typename T, typename A>
inline std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec)
{
    out.put('{');
    for(typename std::vector<T,A>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        if (it != vec.begin()) {
            out.put(','); out.put(' ');
        }
        out << *it;
    }
    out.put('}');

    char buf[32];
    sprintf(buf, " (size=%u)", (unsigned int)vec.size());
    out.write(buf, strlen(buf));
    return out;
}

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("ControlMessageType");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("ControlMessageType"));
    e->insert(MEC_HELLO_MESSAGE, "MEC_HELLO_MESSAGE");
    e->insert(MEC_STATUS_UPDATE, "MEC_STATUS_UPDATE");
    e->insert(MEC_WELCOME_MESSAGE, "MEC_WELCOME_MESSAGE");
    e->insert(MEC_REQUEST_SERVICE_MESSAGE, "MEC_REQUEST_SERVICE_MESSAGE");
    e->insert(MEC_START_MEC_APP_MESSAGE, "MEC_START_MEC_APP_MESSAGE");
    e->insert(MEC_APP_STARTED_MESSAGE, "MEC_APP_STARTED_MESSAGE");
    e->insert(MEC_SERVICE_STARTED_MESSAGE, "MEC_SERVICE_STARTED_MESSAGE");
)

Resources::Resources()
{
}

Resources::Resources(const Resources& other)
{
    copy(other);
}

Resources::~Resources()
{
}

Resources& Resources::operator=(const Resources& other)
{
    if (this == &other) return *this;
    copy(other);
    return *this;
}

void Resources::copy(const Resources& other)
{
    this->cpu = other.cpu;
    this->ram = other.ram;
    this->disk = other.disk;
    this->network = other.network;
}

void Resources::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,this->cpu);
    doParsimPacking(b,this->ram);
    doParsimPacking(b,this->disk);
    doParsimPacking(b,this->network);
}

void Resources::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,this->cpu);
    doParsimUnpacking(b,this->ram);
    doParsimUnpacking(b,this->disk);
    doParsimUnpacking(b,this->network);
}

int Resources::getCpu() const
{
    return this->cpu;
}

void Resources::setCpu(int cpu)
{
    this->cpu = cpu;
}

int Resources::getRam() const
{
    return this->ram;
}

void Resources::setRam(int ram)
{
    this->ram = ram;
}

int Resources::getDisk() const
{
    return this->disk;
}

void Resources::setDisk(int disk)
{
    this->disk = disk;
}

int Resources::getNetwork() const
{
    return this->network;
}

void Resources::setNetwork(int network)
{
    this->network = network;
}

class ResourcesDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_cpu,
        FIELD_ram,
        FIELD_disk,
        FIELD_network,
    };
  public:
    ResourcesDescriptor();
    virtual ~ResourcesDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(ResourcesDescriptor)

ResourcesDescriptor::ResourcesDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(Resources)), "")
{
    propertynames = nullptr;
}

ResourcesDescriptor::~ResourcesDescriptor()
{
    delete[] propertynames;
}

bool ResourcesDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Resources *>(obj)!=nullptr;
}

const char **ResourcesDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *ResourcesDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int ResourcesDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int ResourcesDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_cpu
        FD_ISEDITABLE,    // FIELD_ram
        FD_ISEDITABLE,    // FIELD_disk
        FD_ISEDITABLE,    // FIELD_network
    };
    return (field >= 0 && field < 4) ? fieldTypeFlags[field] : 0;
}

const char *ResourcesDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "cpu",
        "ram",
        "disk",
        "network",
    };
    return (field >= 0 && field < 4) ? fieldNames[field] : nullptr;
}

int ResourcesDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'c' && strcmp(fieldName, "cpu") == 0) return base+0;
    if (fieldName[0] == 'r' && strcmp(fieldName, "ram") == 0) return base+1;
    if (fieldName[0] == 'd' && strcmp(fieldName, "disk") == 0) return base+2;
    if (fieldName[0] == 'n' && strcmp(fieldName, "network") == 0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *ResourcesDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_cpu
        "int",    // FIELD_ram
        "int",    // FIELD_disk
        "int",    // FIELD_network
    };
    return (field >= 0 && field < 4) ? fieldTypeStrings[field] : nullptr;
}

const char **ResourcesDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *ResourcesDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int ResourcesDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Resources *pp = (Resources *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *ResourcesDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Resources *pp = (Resources *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string ResourcesDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Resources *pp = (Resources *)object; (void)pp;
    switch (field) {
        case FIELD_cpu: return long2string(pp->getCpu());
        case FIELD_ram: return long2string(pp->getRam());
        case FIELD_disk: return long2string(pp->getDisk());
        case FIELD_network: return long2string(pp->getNetwork());
        default: return "";
    }
}

bool ResourcesDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Resources *pp = (Resources *)object; (void)pp;
    switch (field) {
        case FIELD_cpu: pp->setCpu(string2long(value)); return true;
        case FIELD_ram: pp->setRam(string2long(value)); return true;
        case FIELD_disk: pp->setDisk(string2long(value)); return true;
        case FIELD_network: pp->setNetwork(string2long(value)); return true;
        default: return false;
    }
}

const char *ResourcesDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *ResourcesDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Resources *pp = (Resources *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

QoSRequirements::QoSRequirements()
{
}

QoSRequirements::QoSRequirements(const QoSRequirements& other)
{
    copy(other);
}

QoSRequirements::~QoSRequirements()
{
}

QoSRequirements& QoSRequirements::operator=(const QoSRequirements& other)
{
    if (this == &other) return *this;
    copy(other);
    return *this;
}

void QoSRequirements::copy(const QoSRequirements& other)
{
    this->expectedDelay = other.expectedDelay;
    this->bandwidth = other.bandwidth;
    this->processingTime = other.processingTime;
}

void QoSRequirements::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,this->expectedDelay);
    doParsimPacking(b,this->bandwidth);
    doParsimPacking(b,this->processingTime);
}

void QoSRequirements::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,this->expectedDelay);
    doParsimUnpacking(b,this->bandwidth);
    doParsimUnpacking(b,this->processingTime);
}

double QoSRequirements::getExpectedDelay() const
{
    return this->expectedDelay;
}

void QoSRequirements::setExpectedDelay(double expectedDelay)
{
    this->expectedDelay = expectedDelay;
}

double QoSRequirements::getBandwidth() const
{
    return this->bandwidth;
}

void QoSRequirements::setBandwidth(double bandwidth)
{
    this->bandwidth = bandwidth;
}

double QoSRequirements::getProcessingTime() const
{
    return this->processingTime;
}

void QoSRequirements::setProcessingTime(double processingTime)
{
    this->processingTime = processingTime;
}

class QoSRequirementsDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_expectedDelay,
        FIELD_bandwidth,
        FIELD_processingTime,
    };
  public:
    QoSRequirementsDescriptor();
    virtual ~QoSRequirementsDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(QoSRequirementsDescriptor)

QoSRequirementsDescriptor::QoSRequirementsDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(QoSRequirements)), "")
{
    propertynames = nullptr;
}

QoSRequirementsDescriptor::~QoSRequirementsDescriptor()
{
    delete[] propertynames;
}

bool QoSRequirementsDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<QoSRequirements *>(obj)!=nullptr;
}

const char **QoSRequirementsDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *QoSRequirementsDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int QoSRequirementsDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int QoSRequirementsDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_expectedDelay
        FD_ISEDITABLE,    // FIELD_bandwidth
        FD_ISEDITABLE,    // FIELD_processingTime
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *QoSRequirementsDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "expectedDelay",
        "bandwidth",
        "processingTime",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int QoSRequirementsDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'e' && strcmp(fieldName, "expectedDelay") == 0) return base+0;
    if (fieldName[0] == 'b' && strcmp(fieldName, "bandwidth") == 0) return base+1;
    if (fieldName[0] == 'p' && strcmp(fieldName, "processingTime") == 0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *QoSRequirementsDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "double",    // FIELD_expectedDelay
        "double",    // FIELD_bandwidth
        "double",    // FIELD_processingTime
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **QoSRequirementsDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *QoSRequirementsDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int QoSRequirementsDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    QoSRequirements *pp = (QoSRequirements *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *QoSRequirementsDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    QoSRequirements *pp = (QoSRequirements *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string QoSRequirementsDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    QoSRequirements *pp = (QoSRequirements *)object; (void)pp;
    switch (field) {
        case FIELD_expectedDelay: return double2string(pp->getExpectedDelay());
        case FIELD_bandwidth: return double2string(pp->getBandwidth());
        case FIELD_processingTime: return double2string(pp->getProcessingTime());
        default: return "";
    }
}

bool QoSRequirementsDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    QoSRequirements *pp = (QoSRequirements *)object; (void)pp;
    switch (field) {
        case FIELD_expectedDelay: pp->setExpectedDelay(string2double(value)); return true;
        case FIELD_bandwidth: pp->setBandwidth(string2double(value)); return true;
        case FIELD_processingTime: pp->setProcessingTime(string2double(value)); return true;
        default: return false;
    }
}

const char *QoSRequirementsDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *QoSRequirementsDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    QoSRequirements *pp = (QoSRequirements *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

MecAppDescription::MecAppDescription()
{
}

MecAppDescription::MecAppDescription(const MecAppDescription& other)
{
    copy(other);
}

MecAppDescription::~MecAppDescription()
{
}

MecAppDescription& MecAppDescription::operator=(const MecAppDescription& other)
{
    if (this == &other) return *this;
    copy(other);
    return *this;
}

void MecAppDescription::copy(const MecAppDescription& other)
{
    this->appName = other.appName;
    this->requiredResources = other.requiredResources;
    this->qosRequirements = other.qosRequirements;
}

void MecAppDescription::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,this->appName);
    doParsimPacking(b,this->requiredResources);
    doParsimPacking(b,this->qosRequirements);
}

void MecAppDescription::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,this->appName);
    doParsimUnpacking(b,this->requiredResources);
    doParsimUnpacking(b,this->qosRequirements);
}

const char * MecAppDescription::getAppName() const
{
    return this->appName.c_str();
}

void MecAppDescription::setAppName(const char * appName)
{
    this->appName = appName;
}

const Resources& MecAppDescription::getRequiredResources() const
{
    return this->requiredResources;
}

void MecAppDescription::setRequiredResources(const Resources& requiredResources)
{
    this->requiredResources = requiredResources;
}

const QoSRequirements& MecAppDescription::getQosRequirements() const
{
    return this->qosRequirements;
}

void MecAppDescription::setQosRequirements(const QoSRequirements& qosRequirements)
{
    this->qosRequirements = qosRequirements;
}

class MecAppDescriptionDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_appName,
        FIELD_requiredResources,
        FIELD_qosRequirements,
    };
  public:
    MecAppDescriptionDescriptor();
    virtual ~MecAppDescriptionDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(MecAppDescriptionDescriptor)

MecAppDescriptionDescriptor::MecAppDescriptionDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(MecAppDescription)), "")
{
    propertynames = nullptr;
}

MecAppDescriptionDescriptor::~MecAppDescriptionDescriptor()
{
    delete[] propertynames;
}

bool MecAppDescriptionDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<MecAppDescription *>(obj)!=nullptr;
}

const char **MecAppDescriptionDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *MecAppDescriptionDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int MecAppDescriptionDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int MecAppDescriptionDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_appName
        FD_ISCOMPOUND,    // FIELD_requiredResources
        FD_ISCOMPOUND,    // FIELD_qosRequirements
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *MecAppDescriptionDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "appName",
        "requiredResources",
        "qosRequirements",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int MecAppDescriptionDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'a' && strcmp(fieldName, "appName") == 0) return base+0;
    if (fieldName[0] == 'r' && strcmp(fieldName, "requiredResources") == 0) return base+1;
    if (fieldName[0] == 'q' && strcmp(fieldName, "qosRequirements") == 0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *MecAppDescriptionDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "string",    // FIELD_appName
        "Resources",    // FIELD_requiredResources
        "QoSRequirements",    // FIELD_qosRequirements
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **MecAppDescriptionDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *MecAppDescriptionDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int MecAppDescriptionDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    MecAppDescription *pp = (MecAppDescription *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *MecAppDescriptionDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    MecAppDescription *pp = (MecAppDescription *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string MecAppDescriptionDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    MecAppDescription *pp = (MecAppDescription *)object; (void)pp;
    switch (field) {
        case FIELD_appName: return oppstring2string(pp->getAppName());
        case FIELD_requiredResources: {std::stringstream out; out << pp->getRequiredResources(); return out.str();}
        case FIELD_qosRequirements: {std::stringstream out; out << pp->getQosRequirements(); return out.str();}
        default: return "";
    }
}

bool MecAppDescriptionDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    MecAppDescription *pp = (MecAppDescription *)object; (void)pp;
    switch (field) {
        case FIELD_appName: pp->setAppName((value)); return true;
        default: return false;
    }
}

const char *MecAppDescriptionDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_requiredResources: return omnetpp::opp_typename(typeid(Resources));
        case FIELD_qosRequirements: return omnetpp::opp_typename(typeid(QoSRequirements));
        default: return nullptr;
    };
}

void *MecAppDescriptionDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    MecAppDescription *pp = (MecAppDescription *)object; (void)pp;
    switch (field) {
        case FIELD_requiredResources: return toVoidPtr(&pp->getRequiredResources()); break;
        case FIELD_qosRequirements: return toVoidPtr(&pp->getQosRequirements()); break;
        default: return nullptr;
    }
}

Register_Class(MecControlMessage)

MecControlMessage::MecControlMessage() : ::inet::FieldsChunk()
{
}

MecControlMessage::MecControlMessage(const MecControlMessage& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

MecControlMessage::~MecControlMessage()
{
}

MecControlMessage& MecControlMessage::operator=(const MecControlMessage& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void MecControlMessage::copy(const MecControlMessage& other)
{
    this->messageId = other.messageId;
    this->sourceHost = other.sourceHost;
    this->ctlMsgType = other.ctlMsgType;
    this->timestamp = other.timestamp;
}

void MecControlMessage::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->messageId);
    doParsimPacking(b,this->sourceHost);
    doParsimPacking(b,this->ctlMsgType);
    doParsimPacking(b,this->timestamp);
}

void MecControlMessage::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->messageId);
    doParsimUnpacking(b,this->sourceHost);
    doParsimUnpacking(b,this->ctlMsgType);
    doParsimUnpacking(b,this->timestamp);
}

long MecControlMessage::getMessageId() const
{
    return this->messageId;
}

void MecControlMessage::setMessageId(long messageId)
{
    handleChange();
    this->messageId = messageId;
}

const char * MecControlMessage::getSourceHost() const
{
    return this->sourceHost.c_str();
}

void MecControlMessage::setSourceHost(const char * sourceHost)
{
    handleChange();
    this->sourceHost = sourceHost;
}

ControlMessageType MecControlMessage::getCtlMsgType() const
{
    return this->ctlMsgType;
}

void MecControlMessage::setCtlMsgType(ControlMessageType ctlMsgType)
{
    handleChange();
    this->ctlMsgType = ctlMsgType;
}

double MecControlMessage::getTimestamp() const
{
    return this->timestamp;
}

void MecControlMessage::setTimestamp(double timestamp)
{
    handleChange();
    this->timestamp = timestamp;
}

class MecControlMessageDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_messageId,
        FIELD_sourceHost,
        FIELD_ctlMsgType,
        FIELD_timestamp,
    };
  public:
    MecControlMessageDescriptor();
    virtual ~MecControlMessageDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(MecControlMessageDescriptor)

MecControlMessageDescriptor::MecControlMessageDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(MecControlMessage)), "inet::FieldsChunk")
{
    propertynames = nullptr;
}

MecControlMessageDescriptor::~MecControlMessageDescriptor()
{
    delete[] propertynames;
}

bool MecControlMessageDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<MecControlMessage *>(obj)!=nullptr;
}

const char **MecControlMessageDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *MecControlMessageDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int MecControlMessageDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int MecControlMessageDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_messageId
        FD_ISEDITABLE,    // FIELD_sourceHost
        0,    // FIELD_ctlMsgType
        FD_ISEDITABLE,    // FIELD_timestamp
    };
    return (field >= 0 && field < 4) ? fieldTypeFlags[field] : 0;
}

const char *MecControlMessageDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "messageId",
        "sourceHost",
        "ctlMsgType",
        "timestamp",
    };
    return (field >= 0 && field < 4) ? fieldNames[field] : nullptr;
}

int MecControlMessageDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'm' && strcmp(fieldName, "messageId") == 0) return base+0;
    if (fieldName[0] == 's' && strcmp(fieldName, "sourceHost") == 0) return base+1;
    if (fieldName[0] == 'c' && strcmp(fieldName, "ctlMsgType") == 0) return base+2;
    if (fieldName[0] == 't' && strcmp(fieldName, "timestamp") == 0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *MecControlMessageDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "long",    // FIELD_messageId
        "string",    // FIELD_sourceHost
        "ControlMessageType",    // FIELD_ctlMsgType
        "double",    // FIELD_timestamp
    };
    return (field >= 0 && field < 4) ? fieldTypeStrings[field] : nullptr;
}

const char **MecControlMessageDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_ctlMsgType: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *MecControlMessageDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_ctlMsgType:
            if (!strcmp(propertyname, "enum")) return "ControlMessageType";
            return nullptr;
        default: return nullptr;
    }
}

int MecControlMessageDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    MecControlMessage *pp = (MecControlMessage *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *MecControlMessageDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    MecControlMessage *pp = (MecControlMessage *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string MecControlMessageDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    MecControlMessage *pp = (MecControlMessage *)object; (void)pp;
    switch (field) {
        case FIELD_messageId: return long2string(pp->getMessageId());
        case FIELD_sourceHost: return oppstring2string(pp->getSourceHost());
        case FIELD_ctlMsgType: return enum2string(pp->getCtlMsgType(), "ControlMessageType");
        case FIELD_timestamp: return double2string(pp->getTimestamp());
        default: return "";
    }
}

bool MecControlMessageDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    MecControlMessage *pp = (MecControlMessage *)object; (void)pp;
    switch (field) {
        case FIELD_messageId: pp->setMessageId(string2long(value)); return true;
        case FIELD_sourceHost: pp->setSourceHost((value)); return true;
        case FIELD_timestamp: pp->setTimestamp(string2double(value)); return true;
        default: return false;
    }
}

const char *MecControlMessageDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *MecControlMessageDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    MecControlMessage *pp = (MecControlMessage *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(MecUpdateMessage)

MecUpdateMessage::MecUpdateMessage() : ::MecControlMessage()
{
    this->setChunkLength(inet::B(400));
    this->setCtlMsgType(MEC_STATUS_UPDATE);

}

MecUpdateMessage::MecUpdateMessage(const MecUpdateMessage& other) : ::MecControlMessage(other)
{
    copy(other);
}

MecUpdateMessage::~MecUpdateMessage()
{
}

MecUpdateMessage& MecUpdateMessage::operator=(const MecUpdateMessage& other)
{
    if (this == &other) return *this;
    ::MecControlMessage::operator=(other);
    copy(other);
    return *this;
}

void MecUpdateMessage::copy(const MecUpdateMessage& other)
{
    this->memoryCapacityUsed = other.memoryCapacityUsed;
    this->computationalCapacityUsed = other.computationalCapacityUsed;
    this->storageCapacityUsed = other.storageCapacityUsed;
    this->networkCapacityUsed = other.networkCapacityUsed;
}

void MecUpdateMessage::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::MecControlMessage::parsimPack(b);
    doParsimPacking(b,this->memoryCapacityUsed);
    doParsimPacking(b,this->computationalCapacityUsed);
    doParsimPacking(b,this->storageCapacityUsed);
    doParsimPacking(b,this->networkCapacityUsed);
}

void MecUpdateMessage::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::MecControlMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->memoryCapacityUsed);
    doParsimUnpacking(b,this->computationalCapacityUsed);
    doParsimUnpacking(b,this->storageCapacityUsed);
    doParsimUnpacking(b,this->networkCapacityUsed);
}

double MecUpdateMessage::getMemoryCapacityUsed() const
{
    return this->memoryCapacityUsed;
}

void MecUpdateMessage::setMemoryCapacityUsed(double memoryCapacityUsed)
{
    handleChange();
    this->memoryCapacityUsed = memoryCapacityUsed;
}

double MecUpdateMessage::getComputationalCapacityUsed() const
{
    return this->computationalCapacityUsed;
}

void MecUpdateMessage::setComputationalCapacityUsed(double computationalCapacityUsed)
{
    handleChange();
    this->computationalCapacityUsed = computationalCapacityUsed;
}

double MecUpdateMessage::getStorageCapacityUsed() const
{
    return this->storageCapacityUsed;
}

void MecUpdateMessage::setStorageCapacityUsed(double storageCapacityUsed)
{
    handleChange();
    this->storageCapacityUsed = storageCapacityUsed;
}

double MecUpdateMessage::getNetworkCapacityUsed() const
{
    return this->networkCapacityUsed;
}

void MecUpdateMessage::setNetworkCapacityUsed(double networkCapacityUsed)
{
    handleChange();
    this->networkCapacityUsed = networkCapacityUsed;
}

class MecUpdateMessageDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_memoryCapacityUsed,
        FIELD_computationalCapacityUsed,
        FIELD_storageCapacityUsed,
        FIELD_networkCapacityUsed,
    };
  public:
    MecUpdateMessageDescriptor();
    virtual ~MecUpdateMessageDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(MecUpdateMessageDescriptor)

MecUpdateMessageDescriptor::MecUpdateMessageDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(MecUpdateMessage)), "MecControlMessage")
{
    propertynames = nullptr;
}

MecUpdateMessageDescriptor::~MecUpdateMessageDescriptor()
{
    delete[] propertynames;
}

bool MecUpdateMessageDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<MecUpdateMessage *>(obj)!=nullptr;
}

const char **MecUpdateMessageDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *MecUpdateMessageDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int MecUpdateMessageDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int MecUpdateMessageDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_memoryCapacityUsed
        FD_ISEDITABLE,    // FIELD_computationalCapacityUsed
        FD_ISEDITABLE,    // FIELD_storageCapacityUsed
        FD_ISEDITABLE,    // FIELD_networkCapacityUsed
    };
    return (field >= 0 && field < 4) ? fieldTypeFlags[field] : 0;
}

const char *MecUpdateMessageDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "memoryCapacityUsed",
        "computationalCapacityUsed",
        "storageCapacityUsed",
        "networkCapacityUsed",
    };
    return (field >= 0 && field < 4) ? fieldNames[field] : nullptr;
}

int MecUpdateMessageDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'm' && strcmp(fieldName, "memoryCapacityUsed") == 0) return base+0;
    if (fieldName[0] == 'c' && strcmp(fieldName, "computationalCapacityUsed") == 0) return base+1;
    if (fieldName[0] == 's' && strcmp(fieldName, "storageCapacityUsed") == 0) return base+2;
    if (fieldName[0] == 'n' && strcmp(fieldName, "networkCapacityUsed") == 0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *MecUpdateMessageDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "double",    // FIELD_memoryCapacityUsed
        "double",    // FIELD_computationalCapacityUsed
        "double",    // FIELD_storageCapacityUsed
        "double",    // FIELD_networkCapacityUsed
    };
    return (field >= 0 && field < 4) ? fieldTypeStrings[field] : nullptr;
}

const char **MecUpdateMessageDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *MecUpdateMessageDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int MecUpdateMessageDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    MecUpdateMessage *pp = (MecUpdateMessage *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *MecUpdateMessageDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    MecUpdateMessage *pp = (MecUpdateMessage *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string MecUpdateMessageDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    MecUpdateMessage *pp = (MecUpdateMessage *)object; (void)pp;
    switch (field) {
        case FIELD_memoryCapacityUsed: return double2string(pp->getMemoryCapacityUsed());
        case FIELD_computationalCapacityUsed: return double2string(pp->getComputationalCapacityUsed());
        case FIELD_storageCapacityUsed: return double2string(pp->getStorageCapacityUsed());
        case FIELD_networkCapacityUsed: return double2string(pp->getNetworkCapacityUsed());
        default: return "";
    }
}

bool MecUpdateMessageDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    MecUpdateMessage *pp = (MecUpdateMessage *)object; (void)pp;
    switch (field) {
        case FIELD_memoryCapacityUsed: pp->setMemoryCapacityUsed(string2double(value)); return true;
        case FIELD_computationalCapacityUsed: pp->setComputationalCapacityUsed(string2double(value)); return true;
        case FIELD_storageCapacityUsed: pp->setStorageCapacityUsed(string2double(value)); return true;
        case FIELD_networkCapacityUsed: pp->setNetworkCapacityUsed(string2double(value)); return true;
        default: return false;
    }
}

const char *MecUpdateMessageDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *MecUpdateMessageDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    MecUpdateMessage *pp = (MecUpdateMessage *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(MecHelloMessage)

MecHelloMessage::MecHelloMessage() : ::MecControlMessage()
{
    this->setChunkLength(inet::B(200));
    this->setCtlMsgType(MEC_HELLO_MESSAGE);

}

MecHelloMessage::MecHelloMessage(const MecHelloMessage& other) : ::MecControlMessage(other)
{
    copy(other);
}

MecHelloMessage::~MecHelloMessage()
{
}

MecHelloMessage& MecHelloMessage::operator=(const MecHelloMessage& other)
{
    if (this == &other) return *this;
    ::MecControlMessage::operator=(other);
    copy(other);
    return *this;
}

void MecHelloMessage::copy(const MecHelloMessage& other)
{
    this->capabilities = other.capabilities;
}

void MecHelloMessage::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::MecControlMessage::parsimPack(b);
    doParsimPacking(b,this->capabilities);
}

void MecHelloMessage::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::MecControlMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->capabilities);
}

const Resources& MecHelloMessage::getCapabilities() const
{
    return this->capabilities;
}

void MecHelloMessage::setCapabilities(const Resources& capabilities)
{
    handleChange();
    this->capabilities = capabilities;
}

class MecHelloMessageDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_capabilities,
    };
  public:
    MecHelloMessageDescriptor();
    virtual ~MecHelloMessageDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(MecHelloMessageDescriptor)

MecHelloMessageDescriptor::MecHelloMessageDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(MecHelloMessage)), "MecControlMessage")
{
    propertynames = nullptr;
}

MecHelloMessageDescriptor::~MecHelloMessageDescriptor()
{
    delete[] propertynames;
}

bool MecHelloMessageDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<MecHelloMessage *>(obj)!=nullptr;
}

const char **MecHelloMessageDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *MecHelloMessageDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int MecHelloMessageDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int MecHelloMessageDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND,    // FIELD_capabilities
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *MecHelloMessageDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "capabilities",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int MecHelloMessageDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'c' && strcmp(fieldName, "capabilities") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *MecHelloMessageDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "Resources",    // FIELD_capabilities
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **MecHelloMessageDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *MecHelloMessageDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int MecHelloMessageDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    MecHelloMessage *pp = (MecHelloMessage *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *MecHelloMessageDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    MecHelloMessage *pp = (MecHelloMessage *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string MecHelloMessageDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    MecHelloMessage *pp = (MecHelloMessage *)object; (void)pp;
    switch (field) {
        case FIELD_capabilities: {std::stringstream out; out << pp->getCapabilities(); return out.str();}
        default: return "";
    }
}

bool MecHelloMessageDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    MecHelloMessage *pp = (MecHelloMessage *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *MecHelloMessageDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_capabilities: return omnetpp::opp_typename(typeid(Resources));
        default: return nullptr;
    };
}

void *MecHelloMessageDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    MecHelloMessage *pp = (MecHelloMessage *)object; (void)pp;
    switch (field) {
        case FIELD_capabilities: return toVoidPtr(&pp->getCapabilities()); break;
        default: return nullptr;
    }
}

Register_Class(MecWelcomeMessage)

MecWelcomeMessage::MecWelcomeMessage() : ::MecControlMessage()
{
    this->setChunkLength(inet::B(200));
    this->setCtlMsgType(MEC_WELCOME_MESSAGE);

}

MecWelcomeMessage::MecWelcomeMessage(const MecWelcomeMessage& other) : ::MecControlMessage(other)
{
    copy(other);
}

MecWelcomeMessage::~MecWelcomeMessage()
{
}

MecWelcomeMessage& MecWelcomeMessage::operator=(const MecWelcomeMessage& other)
{
    if (this == &other) return *this;
    ::MecControlMessage::operator=(other);
    copy(other);
    return *this;
}

void MecWelcomeMessage::copy(const MecWelcomeMessage& other)
{
    this->updateRate = other.updateRate;
}

void MecWelcomeMessage::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::MecControlMessage::parsimPack(b);
    doParsimPacking(b,this->updateRate);
}

void MecWelcomeMessage::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::MecControlMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->updateRate);
}

double MecWelcomeMessage::getUpdateRate() const
{
    return this->updateRate;
}

void MecWelcomeMessage::setUpdateRate(double updateRate)
{
    handleChange();
    this->updateRate = updateRate;
}

class MecWelcomeMessageDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_updateRate,
    };
  public:
    MecWelcomeMessageDescriptor();
    virtual ~MecWelcomeMessageDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(MecWelcomeMessageDescriptor)

MecWelcomeMessageDescriptor::MecWelcomeMessageDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(MecWelcomeMessage)), "MecControlMessage")
{
    propertynames = nullptr;
}

MecWelcomeMessageDescriptor::~MecWelcomeMessageDescriptor()
{
    delete[] propertynames;
}

bool MecWelcomeMessageDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<MecWelcomeMessage *>(obj)!=nullptr;
}

const char **MecWelcomeMessageDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *MecWelcomeMessageDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int MecWelcomeMessageDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int MecWelcomeMessageDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_updateRate
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *MecWelcomeMessageDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "updateRate",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int MecWelcomeMessageDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'u' && strcmp(fieldName, "updateRate") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *MecWelcomeMessageDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "double",    // FIELD_updateRate
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **MecWelcomeMessageDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *MecWelcomeMessageDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int MecWelcomeMessageDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    MecWelcomeMessage *pp = (MecWelcomeMessage *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *MecWelcomeMessageDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    MecWelcomeMessage *pp = (MecWelcomeMessage *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string MecWelcomeMessageDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    MecWelcomeMessage *pp = (MecWelcomeMessage *)object; (void)pp;
    switch (field) {
        case FIELD_updateRate: return double2string(pp->getUpdateRate());
        default: return "";
    }
}

bool MecWelcomeMessageDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    MecWelcomeMessage *pp = (MecWelcomeMessage *)object; (void)pp;
    switch (field) {
        case FIELD_updateRate: pp->setUpdateRate(string2double(value)); return true;
        default: return false;
    }
}

const char *MecWelcomeMessageDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *MecWelcomeMessageDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    MecWelcomeMessage *pp = (MecWelcomeMessage *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(MecRequestServiceMessage)

MecRequestServiceMessage::MecRequestServiceMessage() : ::MecControlMessage()
{
    this->setChunkLength(inet::B(200));
    this->setCtlMsgType(MEC_REQUEST_SERVICE_MESSAGE);

}

MecRequestServiceMessage::MecRequestServiceMessage(const MecRequestServiceMessage& other) : ::MecControlMessage(other)
{
    copy(other);
}

MecRequestServiceMessage::~MecRequestServiceMessage()
{
    delete [] this->mecApplications;
}

MecRequestServiceMessage& MecRequestServiceMessage::operator=(const MecRequestServiceMessage& other)
{
    if (this == &other) return *this;
    ::MecControlMessage::operator=(other);
    copy(other);
    return *this;
}

void MecRequestServiceMessage::copy(const MecRequestServiceMessage& other)
{
    this->serviceName = other.serviceName;
    delete [] this->mecApplications;
    this->mecApplications = (other.mecApplications_arraysize==0) ? nullptr : new MecAppDescription[other.mecApplications_arraysize];
    mecApplications_arraysize = other.mecApplications_arraysize;
    for (size_t i = 0; i < mecApplications_arraysize; i++) {
        this->mecApplications[i] = other.mecApplications[i];
    }
}

void MecRequestServiceMessage::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::MecControlMessage::parsimPack(b);
    doParsimPacking(b,this->serviceName);
    b->pack(mecApplications_arraysize);
    doParsimArrayPacking(b,this->mecApplications,mecApplications_arraysize);
}

void MecRequestServiceMessage::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::MecControlMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->serviceName);
    delete [] this->mecApplications;
    b->unpack(mecApplications_arraysize);
    if (mecApplications_arraysize == 0) {
        this->mecApplications = nullptr;
    } else {
        this->mecApplications = new MecAppDescription[mecApplications_arraysize];
        doParsimArrayUnpacking(b,this->mecApplications,mecApplications_arraysize);
    }
}

const char * MecRequestServiceMessage::getServiceName() const
{
    return this->serviceName.c_str();
}

void MecRequestServiceMessage::setServiceName(const char * serviceName)
{
    handleChange();
    this->serviceName = serviceName;
}

size_t MecRequestServiceMessage::getMecApplicationsArraySize() const
{
    return mecApplications_arraysize;
}

const MecAppDescription& MecRequestServiceMessage::getMecApplications(size_t k) const
{
    if (k >= mecApplications_arraysize) throw omnetpp::cRuntimeError("Array of size mecApplications_arraysize indexed by %lu", (unsigned long)k);
    return this->mecApplications[k];
}

void MecRequestServiceMessage::setMecApplicationsArraySize(size_t newSize)
{
    handleChange();
    MecAppDescription *mecApplications2 = (newSize==0) ? nullptr : new MecAppDescription[newSize];
    size_t minSize = mecApplications_arraysize < newSize ? mecApplications_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        mecApplications2[i] = this->mecApplications[i];
    delete [] this->mecApplications;
    this->mecApplications = mecApplications2;
    mecApplications_arraysize = newSize;
}

void MecRequestServiceMessage::setMecApplications(size_t k, const MecAppDescription& mecApplications)
{
    if (k >= mecApplications_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    this->mecApplications[k] = mecApplications;
}

void MecRequestServiceMessage::insertMecApplications(size_t k, const MecAppDescription& mecApplications)
{
    handleChange();
    if (k > mecApplications_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = mecApplications_arraysize + 1;
    MecAppDescription *mecApplications2 = new MecAppDescription[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        mecApplications2[i] = this->mecApplications[i];
    mecApplications2[k] = mecApplications;
    for (i = k + 1; i < newSize; i++)
        mecApplications2[i] = this->mecApplications[i-1];
    delete [] this->mecApplications;
    this->mecApplications = mecApplications2;
    mecApplications_arraysize = newSize;
}

void MecRequestServiceMessage::insertMecApplications(const MecAppDescription& mecApplications)
{
    insertMecApplications(mecApplications_arraysize, mecApplications);
}

void MecRequestServiceMessage::eraseMecApplications(size_t k)
{
    if (k >= mecApplications_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    size_t newSize = mecApplications_arraysize - 1;
    MecAppDescription *mecApplications2 = (newSize == 0) ? nullptr : new MecAppDescription[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        mecApplications2[i] = this->mecApplications[i];
    for (i = k; i < newSize; i++)
        mecApplications2[i] = this->mecApplications[i+1];
    delete [] this->mecApplications;
    this->mecApplications = mecApplications2;
    mecApplications_arraysize = newSize;
}

class MecRequestServiceMessageDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_serviceName,
        FIELD_mecApplications,
    };
  public:
    MecRequestServiceMessageDescriptor();
    virtual ~MecRequestServiceMessageDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(MecRequestServiceMessageDescriptor)

MecRequestServiceMessageDescriptor::MecRequestServiceMessageDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(MecRequestServiceMessage)), "MecControlMessage")
{
    propertynames = nullptr;
}

MecRequestServiceMessageDescriptor::~MecRequestServiceMessageDescriptor()
{
    delete[] propertynames;
}

bool MecRequestServiceMessageDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<MecRequestServiceMessage *>(obj)!=nullptr;
}

const char **MecRequestServiceMessageDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *MecRequestServiceMessageDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int MecRequestServiceMessageDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int MecRequestServiceMessageDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_serviceName
        FD_ISARRAY | FD_ISCOMPOUND,    // FIELD_mecApplications
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *MecRequestServiceMessageDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "serviceName",
        "mecApplications",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int MecRequestServiceMessageDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 's' && strcmp(fieldName, "serviceName") == 0) return base+0;
    if (fieldName[0] == 'm' && strcmp(fieldName, "mecApplications") == 0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *MecRequestServiceMessageDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "string",    // FIELD_serviceName
        "MecAppDescription",    // FIELD_mecApplications
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **MecRequestServiceMessageDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *MecRequestServiceMessageDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int MecRequestServiceMessageDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    MecRequestServiceMessage *pp = (MecRequestServiceMessage *)object; (void)pp;
    switch (field) {
        case FIELD_mecApplications: return pp->getMecApplicationsArraySize();
        default: return 0;
    }
}

const char *MecRequestServiceMessageDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    MecRequestServiceMessage *pp = (MecRequestServiceMessage *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string MecRequestServiceMessageDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    MecRequestServiceMessage *pp = (MecRequestServiceMessage *)object; (void)pp;
    switch (field) {
        case FIELD_serviceName: return oppstring2string(pp->getServiceName());
        case FIELD_mecApplications: {std::stringstream out; out << pp->getMecApplications(i); return out.str();}
        default: return "";
    }
}

bool MecRequestServiceMessageDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    MecRequestServiceMessage *pp = (MecRequestServiceMessage *)object; (void)pp;
    switch (field) {
        case FIELD_serviceName: pp->setServiceName((value)); return true;
        default: return false;
    }
}

const char *MecRequestServiceMessageDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_mecApplications: return omnetpp::opp_typename(typeid(MecAppDescription));
        default: return nullptr;
    };
}

void *MecRequestServiceMessageDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    MecRequestServiceMessage *pp = (MecRequestServiceMessage *)object; (void)pp;
    switch (field) {
        case FIELD_mecApplications: return toVoidPtr(&pp->getMecApplications(i)); break;
        default: return nullptr;
    }
}

Register_Class(MecStartMecAppMessage)

MecStartMecAppMessage::MecStartMecAppMessage() : ::MecControlMessage()
{
    this->setChunkLength(inet::B(200));
    this->setCtlMsgType(MEC_START_MEC_APP_MESSAGE);

}

MecStartMecAppMessage::MecStartMecAppMessage(const MecStartMecAppMessage& other) : ::MecControlMessage(other)
{
    copy(other);
}

MecStartMecAppMessage::~MecStartMecAppMessage()
{
}

MecStartMecAppMessage& MecStartMecAppMessage::operator=(const MecStartMecAppMessage& other)
{
    if (this == &other) return *this;
    ::MecControlMessage::operator=(other);
    copy(other);
    return *this;
}

void MecStartMecAppMessage::copy(const MecStartMecAppMessage& other)
{
    this->serviceName = other.serviceName;
    this->mecApplication = other.mecApplication;
}

void MecStartMecAppMessage::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::MecControlMessage::parsimPack(b);
    doParsimPacking(b,this->serviceName);
    doParsimPacking(b,this->mecApplication);
}

void MecStartMecAppMessage::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::MecControlMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->serviceName);
    doParsimUnpacking(b,this->mecApplication);
}

const char * MecStartMecAppMessage::getServiceName() const
{
    return this->serviceName.c_str();
}

void MecStartMecAppMessage::setServiceName(const char * serviceName)
{
    handleChange();
    this->serviceName = serviceName;
}

const MecAppDescription& MecStartMecAppMessage::getMecApplication() const
{
    return this->mecApplication;
}

void MecStartMecAppMessage::setMecApplication(const MecAppDescription& mecApplication)
{
    handleChange();
    this->mecApplication = mecApplication;
}

class MecStartMecAppMessageDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_serviceName,
        FIELD_mecApplication,
    };
  public:
    MecStartMecAppMessageDescriptor();
    virtual ~MecStartMecAppMessageDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(MecStartMecAppMessageDescriptor)

MecStartMecAppMessageDescriptor::MecStartMecAppMessageDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(MecStartMecAppMessage)), "MecControlMessage")
{
    propertynames = nullptr;
}

MecStartMecAppMessageDescriptor::~MecStartMecAppMessageDescriptor()
{
    delete[] propertynames;
}

bool MecStartMecAppMessageDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<MecStartMecAppMessage *>(obj)!=nullptr;
}

const char **MecStartMecAppMessageDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *MecStartMecAppMessageDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int MecStartMecAppMessageDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int MecStartMecAppMessageDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_serviceName
        FD_ISCOMPOUND,    // FIELD_mecApplication
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *MecStartMecAppMessageDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "serviceName",
        "mecApplication",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int MecStartMecAppMessageDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 's' && strcmp(fieldName, "serviceName") == 0) return base+0;
    if (fieldName[0] == 'm' && strcmp(fieldName, "mecApplication") == 0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *MecStartMecAppMessageDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "string",    // FIELD_serviceName
        "MecAppDescription",    // FIELD_mecApplication
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **MecStartMecAppMessageDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *MecStartMecAppMessageDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int MecStartMecAppMessageDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    MecStartMecAppMessage *pp = (MecStartMecAppMessage *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *MecStartMecAppMessageDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    MecStartMecAppMessage *pp = (MecStartMecAppMessage *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string MecStartMecAppMessageDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    MecStartMecAppMessage *pp = (MecStartMecAppMessage *)object; (void)pp;
    switch (field) {
        case FIELD_serviceName: return oppstring2string(pp->getServiceName());
        case FIELD_mecApplication: {std::stringstream out; out << pp->getMecApplication(); return out.str();}
        default: return "";
    }
}

bool MecStartMecAppMessageDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    MecStartMecAppMessage *pp = (MecStartMecAppMessage *)object; (void)pp;
    switch (field) {
        case FIELD_serviceName: pp->setServiceName((value)); return true;
        default: return false;
    }
}

const char *MecStartMecAppMessageDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_mecApplication: return omnetpp::opp_typename(typeid(MecAppDescription));
        default: return nullptr;
    };
}

void *MecStartMecAppMessageDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    MecStartMecAppMessage *pp = (MecStartMecAppMessage *)object; (void)pp;
    switch (field) {
        case FIELD_mecApplication: return toVoidPtr(&pp->getMecApplication()); break;
        default: return nullptr;
    }
}

Register_Class(MecAppStartedMessage)

MecAppStartedMessage::MecAppStartedMessage() : ::MecControlMessage()
{
    this->setChunkLength(inet::B(200));
    this->setCtlMsgType(MEC_APP_STARTED_MESSAGE);

}

MecAppStartedMessage::MecAppStartedMessage(const MecAppStartedMessage& other) : ::MecControlMessage(other)
{
    copy(other);
}

MecAppStartedMessage::~MecAppStartedMessage()
{
}

MecAppStartedMessage& MecAppStartedMessage::operator=(const MecAppStartedMessage& other)
{
    if (this == &other) return *this;
    ::MecControlMessage::operator=(other);
    copy(other);
    return *this;
}

void MecAppStartedMessage::copy(const MecAppStartedMessage& other)
{
    this->serviceName = other.serviceName;
    this->appName = other.appName;
}

void MecAppStartedMessage::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::MecControlMessage::parsimPack(b);
    doParsimPacking(b,this->serviceName);
    doParsimPacking(b,this->appName);
}

void MecAppStartedMessage::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::MecControlMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->serviceName);
    doParsimUnpacking(b,this->appName);
}

const char * MecAppStartedMessage::getServiceName() const
{
    return this->serviceName.c_str();
}

void MecAppStartedMessage::setServiceName(const char * serviceName)
{
    handleChange();
    this->serviceName = serviceName;
}

const char * MecAppStartedMessage::getAppName() const
{
    return this->appName.c_str();
}

void MecAppStartedMessage::setAppName(const char * appName)
{
    handleChange();
    this->appName = appName;
}

class MecAppStartedMessageDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_serviceName,
        FIELD_appName,
    };
  public:
    MecAppStartedMessageDescriptor();
    virtual ~MecAppStartedMessageDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(MecAppStartedMessageDescriptor)

MecAppStartedMessageDescriptor::MecAppStartedMessageDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(MecAppStartedMessage)), "MecControlMessage")
{
    propertynames = nullptr;
}

MecAppStartedMessageDescriptor::~MecAppStartedMessageDescriptor()
{
    delete[] propertynames;
}

bool MecAppStartedMessageDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<MecAppStartedMessage *>(obj)!=nullptr;
}

const char **MecAppStartedMessageDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *MecAppStartedMessageDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int MecAppStartedMessageDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int MecAppStartedMessageDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_serviceName
        FD_ISEDITABLE,    // FIELD_appName
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *MecAppStartedMessageDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "serviceName",
        "appName",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int MecAppStartedMessageDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 's' && strcmp(fieldName, "serviceName") == 0) return base+0;
    if (fieldName[0] == 'a' && strcmp(fieldName, "appName") == 0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *MecAppStartedMessageDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "string",    // FIELD_serviceName
        "string",    // FIELD_appName
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **MecAppStartedMessageDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *MecAppStartedMessageDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int MecAppStartedMessageDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    MecAppStartedMessage *pp = (MecAppStartedMessage *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *MecAppStartedMessageDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    MecAppStartedMessage *pp = (MecAppStartedMessage *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string MecAppStartedMessageDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    MecAppStartedMessage *pp = (MecAppStartedMessage *)object; (void)pp;
    switch (field) {
        case FIELD_serviceName: return oppstring2string(pp->getServiceName());
        case FIELD_appName: return oppstring2string(pp->getAppName());
        default: return "";
    }
}

bool MecAppStartedMessageDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    MecAppStartedMessage *pp = (MecAppStartedMessage *)object; (void)pp;
    switch (field) {
        case FIELD_serviceName: pp->setServiceName((value)); return true;
        case FIELD_appName: pp->setAppName((value)); return true;
        default: return false;
    }
}

const char *MecAppStartedMessageDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *MecAppStartedMessageDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    MecAppStartedMessage *pp = (MecAppStartedMessage *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(MecServiceStartedMessage)

MecServiceStartedMessage::MecServiceStartedMessage() : ::MecControlMessage()
{
    this->setChunkLength(inet::B(200));
    this->setCtlMsgType(MEC_SERVICE_STARTED_MESSAGE);

}

MecServiceStartedMessage::MecServiceStartedMessage(const MecServiceStartedMessage& other) : ::MecControlMessage(other)
{
    copy(other);
}

MecServiceStartedMessage::~MecServiceStartedMessage()
{
}

MecServiceStartedMessage& MecServiceStartedMessage::operator=(const MecServiceStartedMessage& other)
{
    if (this == &other) return *this;
    ::MecControlMessage::operator=(other);
    copy(other);
    return *this;
}

void MecServiceStartedMessage::copy(const MecServiceStartedMessage& other)
{
    this->serviceName = other.serviceName;
}

void MecServiceStartedMessage::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::MecControlMessage::parsimPack(b);
    doParsimPacking(b,this->serviceName);
}

void MecServiceStartedMessage::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::MecControlMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->serviceName);
}

const char * MecServiceStartedMessage::getServiceName() const
{
    return this->serviceName.c_str();
}

void MecServiceStartedMessage::setServiceName(const char * serviceName)
{
    handleChange();
    this->serviceName = serviceName;
}

class MecServiceStartedMessageDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_serviceName,
    };
  public:
    MecServiceStartedMessageDescriptor();
    virtual ~MecServiceStartedMessageDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(MecServiceStartedMessageDescriptor)

MecServiceStartedMessageDescriptor::MecServiceStartedMessageDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(MecServiceStartedMessage)), "MecControlMessage")
{
    propertynames = nullptr;
}

MecServiceStartedMessageDescriptor::~MecServiceStartedMessageDescriptor()
{
    delete[] propertynames;
}

bool MecServiceStartedMessageDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<MecServiceStartedMessage *>(obj)!=nullptr;
}

const char **MecServiceStartedMessageDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *MecServiceStartedMessageDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int MecServiceStartedMessageDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int MecServiceStartedMessageDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_serviceName
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *MecServiceStartedMessageDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "serviceName",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int MecServiceStartedMessageDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 's' && strcmp(fieldName, "serviceName") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *MecServiceStartedMessageDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "string",    // FIELD_serviceName
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **MecServiceStartedMessageDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *MecServiceStartedMessageDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int MecServiceStartedMessageDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    MecServiceStartedMessage *pp = (MecServiceStartedMessage *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *MecServiceStartedMessageDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    MecServiceStartedMessage *pp = (MecServiceStartedMessage *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string MecServiceStartedMessageDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    MecServiceStartedMessage *pp = (MecServiceStartedMessage *)object; (void)pp;
    switch (field) {
        case FIELD_serviceName: return oppstring2string(pp->getServiceName());
        default: return "";
    }
}

bool MecServiceStartedMessageDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    MecServiceStartedMessage *pp = (MecServiceStartedMessage *)object; (void)pp;
    switch (field) {
        case FIELD_serviceName: pp->setServiceName((value)); return true;
        default: return false;
    }
}

const char *MecServiceStartedMessageDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *MecServiceStartedMessageDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    MecServiceStartedMessage *pp = (MecServiceStartedMessage *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}


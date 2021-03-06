//
// Generated file, do not edit! Created by opp_msgc 4.4 from applications/mcoa/proxy_enhanced/messages/control_messages/RequetConnectionToLegacyServer.msg.
//

#ifndef _REQUETCONNECTIONTOLEGACYSERVER_M_H_
#define _REQUETCONNECTIONTOLEGACYSERVER_M_H_

#include <omnetpp.h>

// opp_msgc version check
#define MSGC_VERSION 0x0404
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of opp_msgc: 'make clean' should help.
#endif



/**
 * Class generated from <tt>applications/mcoa/proxy_enhanced/messages/control_messages/RequetConnectionToLegacyServer.msg</tt> by opp_msgc.
 * <pre>
 * packet RequetConnectionToLegacyServer {
 *     int SrcPort;
 *     int DestPort;
 *     string SrcAddress;
 *     string DestAddress;
 * 
 * }
 * </pre>
 */
class RequetConnectionToLegacyServer : public ::cPacket
{
  protected:
    int SrcPort_var;
    int DestPort_var;
    opp_string SrcAddress_var;
    opp_string DestAddress_var;

  private:
    void copy(const RequetConnectionToLegacyServer& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const RequetConnectionToLegacyServer&);

  public:
    RequetConnectionToLegacyServer(const char *name=NULL, int kind=0);
    RequetConnectionToLegacyServer(const RequetConnectionToLegacyServer& other);
    virtual ~RequetConnectionToLegacyServer();
    RequetConnectionToLegacyServer& operator=(const RequetConnectionToLegacyServer& other);
    virtual RequetConnectionToLegacyServer *dup() const {return new RequetConnectionToLegacyServer(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual int getSrcPort() const;
    virtual void setSrcPort(int SrcPort);
    virtual int getDestPort() const;
    virtual void setDestPort(int DestPort);
    virtual const char * getSrcAddress() const;
    virtual void setSrcAddress(const char * SrcAddress);
    virtual const char * getDestAddress() const;
    virtual void setDestAddress(const char * DestAddress);
};

inline void doPacking(cCommBuffer *b, RequetConnectionToLegacyServer& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, RequetConnectionToLegacyServer& obj) {obj.parsimUnpack(b);}


#endif // _REQUETCONNECTIONTOLEGACYSERVER_M_H_

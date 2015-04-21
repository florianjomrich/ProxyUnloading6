//
// Generated file, do not edit! Created by opp_msgc 4.4 from applications/mcoa/proxy_enhanced/messages/control_messages/ACK_Request.msg.
//

#ifndef _ACK_REQUEST_M_H_
#define _ACK_REQUEST_M_H_

#include <omnetpp.h>

// opp_msgc version check
#define MSGC_VERSION 0x0404
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of opp_msgc: 'make clean' should help.
#endif



/**
 * Class generated from <tt>applications/mcoa/proxy_enhanced/messages/control_messages/ACK_Request.msg</tt> by opp_msgc.
 * <pre>
 * packet ACK_Request {
 *    	int SrcPort;
 *     int DestPort;
 *     string SrcAddress;
 *     string DestAddress;
 * }
 * </pre>
 */
class ACK_Request : public ::cPacket
{
  protected:
    int SrcPort_var;
    int DestPort_var;
    opp_string SrcAddress_var;
    opp_string DestAddress_var;

  private:
    void copy(const ACK_Request& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const ACK_Request&);

  public:
    ACK_Request(const char *name=NULL, int kind=0);
    ACK_Request(const ACK_Request& other);
    virtual ~ACK_Request();
    ACK_Request& operator=(const ACK_Request& other);
    virtual ACK_Request *dup() const {return new ACK_Request(*this);}
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

inline void doPacking(cCommBuffer *b, ACK_Request& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, ACK_Request& obj) {obj.parsimUnpack(b);}


#endif // _ACK_REQUEST_M_H_
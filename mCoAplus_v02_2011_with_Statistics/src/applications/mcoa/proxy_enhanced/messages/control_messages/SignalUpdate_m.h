//
// Generated file, do not edit! Created by opp_msgc 4.4 from applications/mcoa/proxy_enhanced/messages/control_messages/SignalUpdate.msg.
//

#ifndef _SIGNALUPDATE_M_H_
#define _SIGNALUPDATE_M_H_

#include <omnetpp.h>

// opp_msgc version check
#define MSGC_VERSION 0x0404
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of opp_msgc: 'make clean' should help.
#endif



/**
 * Class generated from <tt>applications/mcoa/proxy_enhanced/messages/control_messages/SignalUpdate.msg</tt> by opp_msgc.
 * <pre>
 * packet SignalUpdate {
 *    	string AccessPoint;
 *     double valueOfSNR;
 *    
 * }
 * </pre>
 */
class SignalUpdate : public ::cPacket
{
  protected:
    opp_string AccessPoint_var;
    double valueOfSNR_var;

  private:
    void copy(const SignalUpdate& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const SignalUpdate&);

  public:
    SignalUpdate(const char *name=NULL, int kind=0);
    SignalUpdate(const SignalUpdate& other);
    virtual ~SignalUpdate();
    SignalUpdate& operator=(const SignalUpdate& other);
    virtual SignalUpdate *dup() const {return new SignalUpdate(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual const char * getAccessPoint() const;
    virtual void setAccessPoint(const char * AccessPoint);
    virtual double getValueOfSNR() const;
    virtual void setValueOfSNR(double valueOfSNR);
};

inline void doPacking(cCommBuffer *b, SignalUpdate& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, SignalUpdate& obj) {obj.parsimUnpack(b);}


#endif // _SIGNALUPDATE_M_H_

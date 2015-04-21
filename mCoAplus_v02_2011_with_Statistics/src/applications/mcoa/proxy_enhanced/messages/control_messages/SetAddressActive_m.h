//
// Generated file, do not edit! Created by opp_msgc 4.4 from applications/mcoa/proxy_enhanced/messages/control_messages/SetAddressActive.msg.
//

#ifndef _SETADDRESSACTIVE_M_H_
#define _SETADDRESSACTIVE_M_H_

#include <omnetpp.h>

// opp_msgc version check
#define MSGC_VERSION 0x0404
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of opp_msgc: 'make clean' should help.
#endif



/**
 * Class generated from <tt>applications/mcoa/proxy_enhanced/messages/control_messages/SetAddressActive.msg</tt> by opp_msgc.
 * <pre>
 * packet SetAddressActive {
 *     string addressToBeSetActive;
 *     string sourceAddressOfMN;
 *     int CorrespondentNodeToReceive;
 * }
 * </pre>
 */
class SetAddressActive : public ::cPacket
{
  protected:
    opp_string addressToBeSetActive_var;
    opp_string sourceAddressOfMN_var;
    int CorrespondentNodeToReceive_var;

  private:
    void copy(const SetAddressActive& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const SetAddressActive&);

  public:
    SetAddressActive(const char *name=NULL, int kind=0);
    SetAddressActive(const SetAddressActive& other);
    virtual ~SetAddressActive();
    SetAddressActive& operator=(const SetAddressActive& other);
    virtual SetAddressActive *dup() const {return new SetAddressActive(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual const char * getAddressToBeSetActive() const;
    virtual void setAddressToBeSetActive(const char * addressToBeSetActive);
    virtual const char * getSourceAddressOfMN() const;
    virtual void setSourceAddressOfMN(const char * sourceAddressOfMN);
    virtual int getCorrespondentNodeToReceive() const;
    virtual void setCorrespondentNodeToReceive(int CorrespondentNodeToReceive);
};

inline void doPacking(cCommBuffer *b, SetAddressActive& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, SetAddressActive& obj) {obj.parsimUnpack(b);}


#endif // _SETADDRESSACTIVE_M_H_

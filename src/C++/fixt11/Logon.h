#ifndef FIXT11_LOGON_H
#define FIXT11_LOGON_H

#include "Message.h"

namespace FIXT11
{

  class Logon : public Message
  {
  public:
    Logon() : Message(MsgType()) {}
    Logon(const FIX::Message& m) : Message(m) {}
    Logon(const Message& m) : Message(m) {}
    Logon(const Logon& m) : Message(m) {}
    static FIX::MsgType MsgType() { return FIX::MsgType("A"); }

    Logon(
      const FIX::EncryptMethod& aEncryptMethod,
      const FIX::HeartBtInt& aHeartBtInt,
      const FIX::DefaultApplVerID& aDefaultApplVerID )
    : Message(MsgType())
    {
      set(aEncryptMethod);
      set(aHeartBtInt);
      set(aDefaultApplVerID);
    }

    FIELD_SET(*this, FIX::EncryptMethod);
    FIELD_SET(*this, FIX::HeartBtInt);
    FIELD_SET(*this, FIX::RawDataLength);
    FIELD_SET(*this, FIX::RawData);
    FIELD_SET(*this, FIX::ResetSeqNumFlag);
    FIELD_SET(*this, FIX::NextExpectedMsgSeqNum);
    FIELD_SET(*this, FIX::MaxMessageSize);
    FIELD_SET(*this, FIX::TestMessageIndicator);
    FIELD_SET(*this, FIX::Username);
    FIELD_SET(*this, FIX::Password);
    FIELD_SET(*this, FIX::DefaultApplVerID);
    FIELD_SET(*this, FIX::NoMsgTypes);
    class NoMsgTypes: public FIX::Group
    {
    public:
      static FIX::message_order const & getOrder() {
        static int const data[] = {372,385,1130,1131};
        static FIX::message_order const order(data, 4);
        return order;
      };
      NoMsgTypes () : FIX::Group(384,372,getOrder()) {}
      FIELD_SET(*this, FIX::RefMsgType);
      FIELD_SET(*this, FIX::MsgDirection);
      FIELD_SET(*this, FIX::RefApplVerID);
      FIELD_SET(*this, FIX::RefCstmApplVerID);
    };
  };

}

#endif

#ifndef FIX42_LOGON_H
#define FIX42_LOGON_H

#include "Message.h"

namespace FIX42
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
      const FIX::HeartBtInt& aHeartBtInt )
    : Message(MsgType())
    {
      set(aEncryptMethod);
      set(aHeartBtInt);
    }

    FIELD_SET(*this, FIX::EncryptMethod);
    FIELD_SET(*this, FIX::HeartBtInt);
    FIELD_SET(*this, FIX::RawDataLength);
    FIELD_SET(*this, FIX::RawData);
    FIELD_SET(*this, FIX::ResetSeqNumFlag);
    FIELD_SET(*this, FIX::MaxMessageSize);
    FIELD_SET(*this, FIX::NoMsgTypes);
    class NoMsgTypes: public FIX::Group
    {
    public:
      static FIX::message_order const & getOrder() {
        static int const data[] = {372,385};
        static FIX::message_order const order(data, 2);
        return order;
      };
      NoMsgTypes () : FIX::Group(384,372,getOrder()) {}
      FIELD_SET(*this, FIX::RefMsgType);
      FIELD_SET(*this, FIX::MsgDirection);
    };
  };

}

#endif

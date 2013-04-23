#ifndef FIX41_EMAIL_H
#define FIX41_EMAIL_H

#include "Message.h"

namespace FIX41
{

  class Email : public Message
  {
  public:
    Email() : Message(MsgType()) {}
    Email(const FIX::Message& m) : Message(m) {}
    Email(const Message& m) : Message(m) {}
    Email(const Email& m) : Message(m) {}
    static FIX::MsgType MsgType() { return FIX::MsgType("C"); }

    Email(
      const FIX::EmailThreadID& aEmailThreadID,
      const FIX::EmailType& aEmailType,
      const FIX::Subject& aSubject )
    : Message(MsgType())
    {
      set(aEmailThreadID);
      set(aEmailType);
      set(aSubject);
    }

    FIELD_SET(*this, FIX::EmailThreadID);
    FIELD_SET(*this, FIX::EmailType);
    FIELD_SET(*this, FIX::OrigTime);
    FIELD_SET(*this, FIX::Subject);
    FIELD_SET(*this, FIX::OrderID);
    FIELD_SET(*this, FIX::ClOrdID);
    FIELD_SET(*this, FIX::RawDataLength);
    FIELD_SET(*this, FIX::RawData);
    FIELD_SET(*this, FIX::NoRelatedSym);
    class NoRelatedSym: public FIX::Group
    {
    public:
      static FIX::message_order const & getOrder() {
        static int const data[] = {46,65,48,22,167,200,205,201,202,206,207,106,107};
        static FIX::message_order const order(data, 13);
        return order;
      };
      NoRelatedSym () : FIX::Group(146,46,getOrder()) {}
      FIELD_SET(*this, FIX::RelatdSym);
      FIELD_SET(*this, FIX::SymbolSfx);
      FIELD_SET(*this, FIX::SecurityID);
      FIELD_SET(*this, FIX::IDSource);
      FIELD_SET(*this, FIX::SecurityType);
      FIELD_SET(*this, FIX::MaturityMonthYear);
      FIELD_SET(*this, FIX::MaturityDay);
      FIELD_SET(*this, FIX::PutOrCall);
      FIELD_SET(*this, FIX::StrikePrice);
      FIELD_SET(*this, FIX::OptAttribute);
      FIELD_SET(*this, FIX::SecurityExchange);
      FIELD_SET(*this, FIX::Issuer);
      FIELD_SET(*this, FIX::SecurityDesc);
    };
    FIELD_SET(*this, FIX::LinesOfText);
    class LinesOfText: public FIX::Group
    {
    public:
      static FIX::message_order const & getOrder() {
        static int const data[] = {58};
        static FIX::message_order const order(data, 1);
        return order;
      };
      LinesOfText () : FIX::Group(33,58,getOrder()) {}
      FIELD_SET(*this, FIX::Text);
    };
  };

}

#endif

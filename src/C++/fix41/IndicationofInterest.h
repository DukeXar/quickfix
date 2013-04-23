#ifndef FIX41_INDICATIONOFINTEREST_H
#define FIX41_INDICATIONOFINTEREST_H

#include "Message.h"

namespace FIX41
{

  class IndicationofInterest : public Message
  {
  public:
    IndicationofInterest() : Message(MsgType()) {}
    IndicationofInterest(const FIX::Message& m) : Message(m) {}
    IndicationofInterest(const Message& m) : Message(m) {}
    IndicationofInterest(const IndicationofInterest& m) : Message(m) {}
    static FIX::MsgType MsgType() { return FIX::MsgType("6"); }

    IndicationofInterest(
      const FIX::IOIid& aIOIid,
      const FIX::IOITransType& aIOITransType,
      const FIX::Symbol& aSymbol,
      const FIX::Side& aSide,
      const FIX::IOIShares& aIOIShares )
    : Message(MsgType())
    {
      set(aIOIid);
      set(aIOITransType);
      set(aSymbol);
      set(aSide);
      set(aIOIShares);
    }

    FIELD_SET(*this, FIX::IOIid);
    FIELD_SET(*this, FIX::IOITransType);
    FIELD_SET(*this, FIX::IOIRefID);
    FIELD_SET(*this, FIX::Symbol);
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
    FIELD_SET(*this, FIX::Side);
    FIELD_SET(*this, FIX::IOIShares);
    FIELD_SET(*this, FIX::Price);
    FIELD_SET(*this, FIX::Currency);
    FIELD_SET(*this, FIX::ValidUntilTime);
    FIELD_SET(*this, FIX::IOIQltyInd);
    FIELD_SET(*this, FIX::IOIOthSvc);
    FIELD_SET(*this, FIX::IOINaturalFlag);
    FIELD_SET(*this, FIX::Text);
    FIELD_SET(*this, FIX::TransactTime);
    FIELD_SET(*this, FIX::URLLink);
    FIELD_SET(*this, FIX::NoIOIQualifiers);
    class NoIOIQualifiers: public FIX::Group
    {
    public:
      static FIX::message_order const & getOrder() {
        static int const data[] = {104};
        static FIX::message_order const order(data, 1);
        return order;
      };
      NoIOIQualifiers () : FIX::Group(199,104,getOrder()) {}
      FIELD_SET(*this, FIX::IOIQualifier);
    };
  };

}

#endif

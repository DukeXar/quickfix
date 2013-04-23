#ifndef FIX43_REGISTRATIONINSTRUCTIONSRESPONSE_H
#define FIX43_REGISTRATIONINSTRUCTIONSRESPONSE_H

#include "Message.h"

namespace FIX43
{

  class RegistrationInstructionsResponse : public Message
  {
  public:
    RegistrationInstructionsResponse() : Message(MsgType()) {}
    RegistrationInstructionsResponse(const FIX::Message& m) : Message(m) {}
    RegistrationInstructionsResponse(const Message& m) : Message(m) {}
    RegistrationInstructionsResponse(const RegistrationInstructionsResponse& m) : Message(m) {}
    static FIX::MsgType MsgType() { return FIX::MsgType("p"); }

    RegistrationInstructionsResponse(
      const FIX::RegistID& aRegistID,
      const FIX::RegistTransType& aRegistTransType,
      const FIX::RegistRefID& aRegistRefID,
      const FIX::RegistStatus& aRegistStatus )
    : Message(MsgType())
    {
      set(aRegistID);
      set(aRegistTransType);
      set(aRegistRefID);
      set(aRegistStatus);
    }

    FIELD_SET(*this, FIX::RegistID);
    FIELD_SET(*this, FIX::RegistTransType);
    FIELD_SET(*this, FIX::RegistRefID);
    FIELD_SET(*this, FIX::ClOrdID);
    FIELD_SET(*this, FIX::NoPartyIDs);
    class NoPartyIDs: public FIX::Group
    {
    public:
      static FIX::message_order const & getOrder() {
        static int const data[] = {448,447,452,523};
        static FIX::message_order const order(data, 4);
        return order;
      };
      NoPartyIDs () : FIX::Group(453,448,getOrder()) {}
      FIELD_SET(*this, FIX::PartyID);
      FIELD_SET(*this, FIX::PartyIDSource);
      FIELD_SET(*this, FIX::PartyRole);
      FIELD_SET(*this, FIX::PartySubID);
    };
    FIELD_SET(*this, FIX::Account);
    FIELD_SET(*this, FIX::RegistStatus);
    FIELD_SET(*this, FIX::RegistRejReasonCode);
    FIELD_SET(*this, FIX::RegistRejReasonText);
  };

}

#endif

#ifndef FIX44_REGISTRATIONINSTRUCTIONS_H
#define FIX44_REGISTRATIONINSTRUCTIONS_H

#include "Message.h"

namespace FIX44
{

  class RegistrationInstructions : public Message
  {
  public:
    RegistrationInstructions() : Message(MsgType()) {}
    RegistrationInstructions(const FIX::Message& m) : Message(m) {}
    RegistrationInstructions(const Message& m) : Message(m) {}
    RegistrationInstructions(const RegistrationInstructions& m) : Message(m) {}
    static FIX::MsgType MsgType() { return FIX::MsgType("o"); }

    RegistrationInstructions(
      const FIX::RegistID& aRegistID,
      const FIX::RegistTransType& aRegistTransType,
      const FIX::RegistRefID& aRegistRefID )
    : Message(MsgType())
    {
      set(aRegistID);
      set(aRegistTransType);
      set(aRegistRefID);
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
        static int const data[] = {448,447,452,802};
        static FIX::message_order const order(data, 4);
        return order;
      };
      NoPartyIDs () : FIX::Group(453,448,getOrder()) {}
      FIELD_SET(*this, FIX::PartyID);
      FIELD_SET(*this, FIX::PartyIDSource);
      FIELD_SET(*this, FIX::PartyRole);
      FIELD_SET(*this, FIX::NoPartySubIDs);
      class NoPartySubIDs: public FIX::Group
      {
      public:
        static FIX::message_order const & getOrder() {
          static int const data[] = {523,803};
          static FIX::message_order const order(data, 2);
          return order;
        };
        NoPartySubIDs () : FIX::Group(802,523,getOrder()) {}
        FIELD_SET(*this, FIX::PartySubID);
        FIELD_SET(*this, FIX::PartySubIDType);
      };
    };
    FIELD_SET(*this, FIX::Account);
    FIELD_SET(*this, FIX::AcctIDSource);
    FIELD_SET(*this, FIX::RegistAcctType);
    FIELD_SET(*this, FIX::TaxAdvantageType);
    FIELD_SET(*this, FIX::OwnershipType);
    FIELD_SET(*this, FIX::NoRegistDtls);
    class NoRegistDtls: public FIX::Group
    {
    public:
      static FIX::message_order const & getOrder() {
        static int const data[] = {509,511,474,482,539,522,486,475};
        static FIX::message_order const order(data, 8);
        return order;
      };
      NoRegistDtls () : FIX::Group(473,509,getOrder()) {}
      FIELD_SET(*this, FIX::RegistDtls);
      FIELD_SET(*this, FIX::RegistEmail);
      FIELD_SET(*this, FIX::MailingDtls);
      FIELD_SET(*this, FIX::MailingInst);
      FIELD_SET(*this, FIX::NoNestedPartyIDs);
      class NoNestedPartyIDs: public FIX::Group
      {
      public:
        static FIX::message_order const & getOrder() {
          static int const data[] = {524,525,538,804};
          static FIX::message_order const order(data, 4);
          return order;
        };
        NoNestedPartyIDs () : FIX::Group(539,524,getOrder()) {}
        FIELD_SET(*this, FIX::NestedPartyID);
        FIELD_SET(*this, FIX::NestedPartyIDSource);
        FIELD_SET(*this, FIX::NestedPartyRole);
        FIELD_SET(*this, FIX::NoNestedPartySubIDs);
        class NoNestedPartySubIDs: public FIX::Group
        {
        public:
          static FIX::message_order const & getOrder() {
            static int const data[] = {545,805};
            static FIX::message_order const order(data, 2);
            return order;
          };
          NoNestedPartySubIDs () : FIX::Group(804,545,getOrder()) {}
          FIELD_SET(*this, FIX::NestedPartySubID);
          FIELD_SET(*this, FIX::NestedPartySubIDType);
        };
      };
      FIELD_SET(*this, FIX::OwnerType);
      FIELD_SET(*this, FIX::DateOfBirth);
      FIELD_SET(*this, FIX::InvestorCountryOfResidence);
    };
    FIELD_SET(*this, FIX::NoDistribInsts);
    class NoDistribInsts: public FIX::Group
    {
    public:
      static FIX::message_order const & getOrder() {
        static int const data[] = {477,512,478,498,499,500,501,502};
        static FIX::message_order const order(data, 8);
        return order;
      };
      NoDistribInsts () : FIX::Group(510,477,getOrder()) {}
      FIELD_SET(*this, FIX::DistribPaymentMethod);
      FIELD_SET(*this, FIX::DistribPercentage);
      FIELD_SET(*this, FIX::CashDistribCurr);
      FIELD_SET(*this, FIX::CashDistribAgentName);
      FIELD_SET(*this, FIX::CashDistribAgentCode);
      FIELD_SET(*this, FIX::CashDistribAgentAcctNumber);
      FIELD_SET(*this, FIX::CashDistribPayRef);
      FIELD_SET(*this, FIX::CashDistribAgentAcctName);
    };
  };

}

#endif

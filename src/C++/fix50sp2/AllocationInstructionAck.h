#ifndef FIX50SP2_ALLOCATIONINSTRUCTIONACK_H
#define FIX50SP2_ALLOCATIONINSTRUCTIONACK_H

#include "Message.h"

namespace FIX50SP2
{

  class AllocationInstructionAck : public Message
  {
  public:
    AllocationInstructionAck() : Message(MsgType()) {}
    AllocationInstructionAck(const FIX::Message& m) : Message(m) {}
    AllocationInstructionAck(const Message& m) : Message(m) {}
    AllocationInstructionAck(const AllocationInstructionAck& m) : Message(m) {}
    static FIX::MsgType MsgType() { return FIX::MsgType("P"); }

    AllocationInstructionAck(
      const FIX::AllocID& aAllocID,
      const FIX::AllocStatus& aAllocStatus )
    : Message(MsgType())
    {
      set(aAllocID);
      set(aAllocStatus);
    }

    FIELD_SET(*this, FIX::AllocID);
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
    FIELD_SET(*this, FIX::SecondaryAllocID);
    FIELD_SET(*this, FIX::TradeDate);
    FIELD_SET(*this, FIX::TransactTime);
    FIELD_SET(*this, FIX::AllocStatus);
    FIELD_SET(*this, FIX::AllocRejCode);
    FIELD_SET(*this, FIX::AllocType);
    FIELD_SET(*this, FIX::AllocIntermedReqType);
    FIELD_SET(*this, FIX::MatchStatus);
    FIELD_SET(*this, FIX::Product);
    FIELD_SET(*this, FIX::SecurityType);
    FIELD_SET(*this, FIX::Text);
    FIELD_SET(*this, FIX::EncodedTextLen);
    FIELD_SET(*this, FIX::EncodedText);
    FIELD_SET(*this, FIX::NoAllocs);
    class NoAllocs: public FIX::Group
    {
    public:
      static FIX::message_order const & getOrder() {
        static int const data[] = {79,661,366,467,776,161,360,361,989,993,992,80,539,1047};
        static FIX::message_order const order(data, 14);
        return order;
      };
      NoAllocs () : FIX::Group(78,79,getOrder()) {}
      FIELD_SET(*this, FIX::AllocAccount);
      FIELD_SET(*this, FIX::AllocAcctIDSource);
      FIELD_SET(*this, FIX::AllocPrice);
      FIELD_SET(*this, FIX::IndividualAllocID);
      FIELD_SET(*this, FIX::IndividualAllocRejCode);
      FIELD_SET(*this, FIX::AllocText);
      FIELD_SET(*this, FIX::EncodedAllocTextLen);
      FIELD_SET(*this, FIX::EncodedAllocText);
      FIELD_SET(*this, FIX::SecondaryIndividualAllocID);
      FIELD_SET(*this, FIX::AllocCustomerCapacity);
      FIELD_SET(*this, FIX::IndividualAllocType);
      FIELD_SET(*this, FIX::AllocQty);
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
      FIELD_SET(*this, FIX::AllocPositionEffect);
    };
  };

}

#endif

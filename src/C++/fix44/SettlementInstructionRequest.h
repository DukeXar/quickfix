#ifndef FIX44_SETTLEMENTINSTRUCTIONREQUEST_H
#define FIX44_SETTLEMENTINSTRUCTIONREQUEST_H

#include "Message.h"

namespace FIX44
{

  class SettlementInstructionRequest : public Message
  {
  public:
    SettlementInstructionRequest() : Message(MsgType()) {}
    SettlementInstructionRequest(const FIX::Message& m) : Message(m) {}
    SettlementInstructionRequest(const Message& m) : Message(m) {}
    SettlementInstructionRequest(const SettlementInstructionRequest& m) : Message(m) {}
    static FIX::MsgType MsgType() { return FIX::MsgType("AV"); }

    SettlementInstructionRequest(
      const FIX::SettlInstReqID& aSettlInstReqID,
      const FIX::TransactTime& aTransactTime )
    : Message(MsgType())
    {
      set(aSettlInstReqID);
      set(aTransactTime);
    }

    FIELD_SET(*this, FIX::SettlInstReqID);
    FIELD_SET(*this, FIX::TransactTime);
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
    FIELD_SET(*this, FIX::AllocAccount);
    FIELD_SET(*this, FIX::AllocAcctIDSource);
    FIELD_SET(*this, FIX::Side);
    FIELD_SET(*this, FIX::Product);
    FIELD_SET(*this, FIX::SecurityType);
    FIELD_SET(*this, FIX::CFICode);
    FIELD_SET(*this, FIX::EffectiveTime);
    FIELD_SET(*this, FIX::ExpireTime);
    FIELD_SET(*this, FIX::LastUpdateTime);
    FIELD_SET(*this, FIX::StandInstDbType);
    FIELD_SET(*this, FIX::StandInstDbName);
    FIELD_SET(*this, FIX::StandInstDbID);
  };

}

#endif

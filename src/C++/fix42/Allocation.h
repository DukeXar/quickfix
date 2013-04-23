#ifndef FIX42_ALLOCATION_H
#define FIX42_ALLOCATION_H

#include "Message.h"

namespace FIX42
{

  class Allocation : public Message
  {
  public:
    Allocation() : Message(MsgType()) {}
    Allocation(const FIX::Message& m) : Message(m) {}
    Allocation(const Message& m) : Message(m) {}
    Allocation(const Allocation& m) : Message(m) {}
    static FIX::MsgType MsgType() { return FIX::MsgType("J"); }

    Allocation(
      const FIX::AllocID& aAllocID,
      const FIX::AllocTransType& aAllocTransType,
      const FIX::Side& aSide,
      const FIX::Symbol& aSymbol,
      const FIX::Shares& aShares,
      const FIX::AvgPx& aAvgPx,
      const FIX::TradeDate& aTradeDate )
    : Message(MsgType())
    {
      set(aAllocID);
      set(aAllocTransType);
      set(aSide);
      set(aSymbol);
      set(aShares);
      set(aAvgPx);
      set(aTradeDate);
    }

    FIELD_SET(*this, FIX::AllocID);
    FIELD_SET(*this, FIX::AllocTransType);
    FIELD_SET(*this, FIX::RefAllocID);
    FIELD_SET(*this, FIX::AllocLinkID);
    FIELD_SET(*this, FIX::AllocLinkType);
    FIELD_SET(*this, FIX::Side);
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
    FIELD_SET(*this, FIX::ContractMultiplier);
    FIELD_SET(*this, FIX::CouponRate);
    FIELD_SET(*this, FIX::SecurityExchange);
    FIELD_SET(*this, FIX::Issuer);
    FIELD_SET(*this, FIX::EncodedIssuerLen);
    FIELD_SET(*this, FIX::EncodedIssuer);
    FIELD_SET(*this, FIX::SecurityDesc);
    FIELD_SET(*this, FIX::EncodedSecurityDescLen);
    FIELD_SET(*this, FIX::EncodedSecurityDesc);
    FIELD_SET(*this, FIX::Shares);
    FIELD_SET(*this, FIX::LastMkt);
    FIELD_SET(*this, FIX::TradingSessionID);
    FIELD_SET(*this, FIX::AvgPx);
    FIELD_SET(*this, FIX::Currency);
    FIELD_SET(*this, FIX::AvgPrxPrecision);
    FIELD_SET(*this, FIX::TradeDate);
    FIELD_SET(*this, FIX::TransactTime);
    FIELD_SET(*this, FIX::SettlmntTyp);
    FIELD_SET(*this, FIX::FutSettDate);
    FIELD_SET(*this, FIX::GrossTradeAmt);
    FIELD_SET(*this, FIX::NetMoney);
    FIELD_SET(*this, FIX::OpenClose);
    FIELD_SET(*this, FIX::Text);
    FIELD_SET(*this, FIX::EncodedTextLen);
    FIELD_SET(*this, FIX::EncodedText);
    FIELD_SET(*this, FIX::NumDaysInterest);
    FIELD_SET(*this, FIX::AccruedInterestRate);
    FIELD_SET(*this, FIX::NoOrders);
    class NoOrders: public FIX::Group
    {
    public:
      static FIX::message_order const & getOrder() {
        static int const data[] = {11,37,198,66,105};
        static FIX::message_order const order(data, 5);
        return order;
      };
      NoOrders () : FIX::Group(73,11,getOrder()) {}
      FIELD_SET(*this, FIX::ClOrdID);
      FIELD_SET(*this, FIX::OrderID);
      FIELD_SET(*this, FIX::SecondaryOrderID);
      FIELD_SET(*this, FIX::ListID);
      FIELD_SET(*this, FIX::WaveNo);
    };
    FIELD_SET(*this, FIX::NoExecs);
    class NoExecs: public FIX::Group
    {
    public:
      static FIX::message_order const & getOrder() {
        static int const data[] = {32,17,31,29};
        static FIX::message_order const order(data, 4);
        return order;
      };
      NoExecs () : FIX::Group(124,32,getOrder()) {}
      FIELD_SET(*this, FIX::LastShares);
      FIELD_SET(*this, FIX::ExecID);
      FIELD_SET(*this, FIX::LastPx);
      FIELD_SET(*this, FIX::LastCapacity);
    };
    FIELD_SET(*this, FIX::NoAllocs);
    class NoAllocs: public FIX::Group
    {
    public:
      static FIX::message_order const & getOrder() {
        static int const data[] = {79,366,80,81,92,208,209,161,360,361,76,109,12,13,153,154,119,120,155,156,159,160,136};
        static FIX::message_order const order(data, 23);
        return order;
      };
      NoAllocs () : FIX::Group(78,79,getOrder()) {}
      FIELD_SET(*this, FIX::AllocAccount);
      FIELD_SET(*this, FIX::AllocPrice);
      FIELD_SET(*this, FIX::AllocShares);
      FIELD_SET(*this, FIX::ProcessCode);
      FIELD_SET(*this, FIX::BrokerOfCredit);
      FIELD_SET(*this, FIX::NotifyBrokerOfCredit);
      FIELD_SET(*this, FIX::AllocHandlInst);
      FIELD_SET(*this, FIX::AllocText);
      FIELD_SET(*this, FIX::EncodedAllocTextLen);
      FIELD_SET(*this, FIX::EncodedAllocText);
      FIELD_SET(*this, FIX::ExecBroker);
      FIELD_SET(*this, FIX::ClientID);
      FIELD_SET(*this, FIX::Commission);
      FIELD_SET(*this, FIX::CommType);
      FIELD_SET(*this, FIX::AllocAvgPx);
      FIELD_SET(*this, FIX::AllocNetMoney);
      FIELD_SET(*this, FIX::SettlCurrAmt);
      FIELD_SET(*this, FIX::SettlCurrency);
      FIELD_SET(*this, FIX::SettlCurrFxRate);
      FIELD_SET(*this, FIX::SettlCurrFxRateCalc);
      FIELD_SET(*this, FIX::AccruedInterestAmt);
      FIELD_SET(*this, FIX::SettlInstMode);
      FIELD_SET(*this, FIX::NoMiscFees);
      class NoMiscFees: public FIX::Group
      {
      public:
        static FIX::message_order const & getOrder() {
          static int const data[] = {137,138,139};
          static FIX::message_order const order(data, 3);
          return order;
        };
        NoMiscFees () : FIX::Group(136,137,getOrder()) {}
        FIELD_SET(*this, FIX::MiscFeeAmt);
        FIELD_SET(*this, FIX::MiscFeeCurr);
        FIELD_SET(*this, FIX::MiscFeeType);
      };
    };
  };

}

#endif

#ifndef FIX43_NEWORDERCROSS_H
#define FIX43_NEWORDERCROSS_H

#include "Message.h"

namespace FIX43
{

  class NewOrderCross : public Message
  {
  public:
    NewOrderCross() : Message(MsgType()) {}
    NewOrderCross(const FIX::Message& m) : Message(m) {}
    NewOrderCross(const Message& m) : Message(m) {}
    NewOrderCross(const NewOrderCross& m) : Message(m) {}
    static FIX::MsgType MsgType() { return FIX::MsgType("s"); }

    NewOrderCross(
      const FIX::CrossID& aCrossID,
      const FIX::CrossType& aCrossType,
      const FIX::CrossPrioritization& aCrossPrioritization,
      const FIX::HandlInst& aHandlInst,
      const FIX::TransactTime& aTransactTime,
      const FIX::OrdType& aOrdType )
    : Message(MsgType())
    {
      set(aCrossID);
      set(aCrossType);
      set(aCrossPrioritization);
      set(aHandlInst);
      set(aTransactTime);
      set(aOrdType);
    }

    FIELD_SET(*this, FIX::CrossID);
    FIELD_SET(*this, FIX::CrossType);
    FIELD_SET(*this, FIX::CrossPrioritization);
    FIELD_SET(*this, FIX::Symbol);
    FIELD_SET(*this, FIX::SymbolSfx);
    FIELD_SET(*this, FIX::SecurityID);
    FIELD_SET(*this, FIX::SecurityIDSource);
    FIELD_SET(*this, FIX::Product);
    FIELD_SET(*this, FIX::CFICode);
    FIELD_SET(*this, FIX::SecurityType);
    FIELD_SET(*this, FIX::MaturityMonthYear);
    FIELD_SET(*this, FIX::MaturityDate);
    FIELD_SET(*this, FIX::CouponPaymentDate);
    FIELD_SET(*this, FIX::IssueDate);
    FIELD_SET(*this, FIX::RepoCollateralSecurityType);
    FIELD_SET(*this, FIX::RepurchaseTerm);
    FIELD_SET(*this, FIX::RepurchaseRate);
    FIELD_SET(*this, FIX::Factor);
    FIELD_SET(*this, FIX::CreditRating);
    FIELD_SET(*this, FIX::InstrRegistry);
    FIELD_SET(*this, FIX::CountryOfIssue);
    FIELD_SET(*this, FIX::StateOrProvinceOfIssue);
    FIELD_SET(*this, FIX::LocaleOfIssue);
    FIELD_SET(*this, FIX::RedemptionDate);
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
    FIELD_SET(*this, FIX::NoSecurityAltID);
    class NoSecurityAltID: public FIX::Group
    {
    public:
      static FIX::message_order const & getOrder() {
        static int const data[] = {455,456};
        static FIX::message_order const order(data, 2);
        return order;
      };
      NoSecurityAltID () : FIX::Group(454,455,getOrder()) {}
      FIELD_SET(*this, FIX::SecurityAltID);
      FIELD_SET(*this, FIX::SecurityAltIDSource);
    };
    FIELD_SET(*this, FIX::SettlmntTyp);
    FIELD_SET(*this, FIX::FutSettDate);
    FIELD_SET(*this, FIX::HandlInst);
    FIELD_SET(*this, FIX::ExecInst);
    FIELD_SET(*this, FIX::MinQty);
    FIELD_SET(*this, FIX::MaxFloor);
    FIELD_SET(*this, FIX::ExDestination);
    FIELD_SET(*this, FIX::ProcessCode);
    FIELD_SET(*this, FIX::PrevClosePx);
    FIELD_SET(*this, FIX::LocateReqd);
    FIELD_SET(*this, FIX::TransactTime);
    FIELD_SET(*this, FIX::NoStipulations);
    class NoStipulations: public FIX::Group
    {
    public:
      static FIX::message_order const & getOrder() {
        static int const data[] = {233,234};
        static FIX::message_order const order(data, 2);
        return order;
      };
      NoStipulations () : FIX::Group(232,233,getOrder()) {}
      FIELD_SET(*this, FIX::StipulationType);
      FIELD_SET(*this, FIX::StipulationValue);
    };
    FIELD_SET(*this, FIX::OrdType);
    FIELD_SET(*this, FIX::PriceType);
    FIELD_SET(*this, FIX::Price);
    FIELD_SET(*this, FIX::StopPx);
    FIELD_SET(*this, FIX::Spread);
    FIELD_SET(*this, FIX::BenchmarkCurveCurrency);
    FIELD_SET(*this, FIX::BenchmarkCurveName);
    FIELD_SET(*this, FIX::BenchmarkCurvePoint);
    FIELD_SET(*this, FIX::YieldType);
    FIELD_SET(*this, FIX::Yield);
    FIELD_SET(*this, FIX::Currency);
    FIELD_SET(*this, FIX::ComplianceID);
    FIELD_SET(*this, FIX::IOIid);
    FIELD_SET(*this, FIX::QuoteID);
    FIELD_SET(*this, FIX::TimeInForce);
    FIELD_SET(*this, FIX::EffectiveTime);
    FIELD_SET(*this, FIX::ExpireDate);
    FIELD_SET(*this, FIX::ExpireTime);
    FIELD_SET(*this, FIX::GTBookingInst);
    FIELD_SET(*this, FIX::MaxShow);
    FIELD_SET(*this, FIX::PegDifference);
    FIELD_SET(*this, FIX::DiscretionInst);
    FIELD_SET(*this, FIX::DiscretionOffset);
    FIELD_SET(*this, FIX::CancellationRights);
    FIELD_SET(*this, FIX::MoneyLaunderingStatus);
    FIELD_SET(*this, FIX::RegistID);
    FIELD_SET(*this, FIX::Designation);
    FIELD_SET(*this, FIX::AccruedInterestRate);
    FIELD_SET(*this, FIX::AccruedInterestAmt);
    FIELD_SET(*this, FIX::NetMoney);
    FIELD_SET(*this, FIX::NoSides);
    class NoSides: public FIX::Group
    {
    public:
      static FIX::message_order const & getOrder() {
        static int const data[] = {54,11,526,583,453,229,1,581,589,590,591,78,465,38,152,516,468,469,12,13,479,497,528,529,582,121,120,58,354,355,77,203,544,635,377,659};
        static FIX::message_order const order(data, 36);
        return order;
      };
      NoSides () : FIX::Group(552,54,getOrder()) {}
      FIELD_SET(*this, FIX::Side);
      FIELD_SET(*this, FIX::ClOrdID);
      FIELD_SET(*this, FIX::SecondaryClOrdID);
      FIELD_SET(*this, FIX::ClOrdLinkID);
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
      FIELD_SET(*this, FIX::TradeOriginationDate);
      FIELD_SET(*this, FIX::Account);
      FIELD_SET(*this, FIX::AccountType);
      FIELD_SET(*this, FIX::DayBookingInst);
      FIELD_SET(*this, FIX::BookingUnit);
      FIELD_SET(*this, FIX::PreallocMethod);
      FIELD_SET(*this, FIX::QuantityType);
      FIELD_SET(*this, FIX::OrderQty);
      FIELD_SET(*this, FIX::CashOrderQty);
      FIELD_SET(*this, FIX::OrderPercent);
      FIELD_SET(*this, FIX::RoundingDirection);
      FIELD_SET(*this, FIX::RoundingModulus);
      FIELD_SET(*this, FIX::Commission);
      FIELD_SET(*this, FIX::CommType);
      FIELD_SET(*this, FIX::CommCurrency);
      FIELD_SET(*this, FIX::FundRenewWaiv);
      FIELD_SET(*this, FIX::OrderCapacity);
      FIELD_SET(*this, FIX::OrderRestrictions);
      FIELD_SET(*this, FIX::CustOrderCapacity);
      FIELD_SET(*this, FIX::ForexReq);
      FIELD_SET(*this, FIX::SettlCurrency);
      FIELD_SET(*this, FIX::Text);
      FIELD_SET(*this, FIX::EncodedTextLen);
      FIELD_SET(*this, FIX::EncodedText);
      FIELD_SET(*this, FIX::PositionEffect);
      FIELD_SET(*this, FIX::CoveredOrUncovered);
      FIELD_SET(*this, FIX::CashMargin);
      FIELD_SET(*this, FIX::ClearingFeeIndicator);
      FIELD_SET(*this, FIX::SolicitedFlag);
      FIELD_SET(*this, FIX::SideComplianceID);
      FIELD_SET(*this, FIX::NoAllocs);
      class NoAllocs: public FIX::Group
      {
      public:
        static FIX::message_order const & getOrder() {
          static int const data[] = {79,467,539,80};
          static FIX::message_order const order(data, 4);
          return order;
        };
        NoAllocs () : FIX::Group(78,79,getOrder()) {}
        FIELD_SET(*this, FIX::AllocAccount);
        FIELD_SET(*this, FIX::IndividualAllocID);
        FIELD_SET(*this, FIX::NoNestedPartyIDs);
        class NoNestedPartyIDs: public FIX::Group
        {
        public:
          static FIX::message_order const & getOrder() {
            static int const data[] = {524,525,538,545};
            static FIX::message_order const order(data, 4);
            return order;
          };
          NoNestedPartyIDs () : FIX::Group(539,524,getOrder()) {}
          FIELD_SET(*this, FIX::NestedPartyID);
          FIELD_SET(*this, FIX::NestedPartyIDSource);
          FIELD_SET(*this, FIX::NestedPartyRole);
          FIELD_SET(*this, FIX::NestedPartySubID);
        };
        FIELD_SET(*this, FIX::AllocQty);
      };
    };
    FIELD_SET(*this, FIX::NoTradingSessions);
    class NoTradingSessions: public FIX::Group
    {
    public:
      static FIX::message_order const & getOrder() {
        static int const data[] = {336,625};
        static FIX::message_order const order(data, 2);
        return order;
      };
      NoTradingSessions () : FIX::Group(386,336,getOrder()) {}
      FIELD_SET(*this, FIX::TradingSessionID);
      FIELD_SET(*this, FIX::TradingSessionSubID);
    };
  };

}

#endif

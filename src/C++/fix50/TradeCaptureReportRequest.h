#ifndef FIX50_TRADECAPTUREREPORTREQUEST_H
#define FIX50_TRADECAPTUREREPORTREQUEST_H

#include "Message.h"

namespace FIX50
{

  class TradeCaptureReportRequest : public Message
  {
  public:
    TradeCaptureReportRequest() : Message(MsgType()) {}
    TradeCaptureReportRequest(const FIX::Message& m) : Message(m) {}
    TradeCaptureReportRequest(const Message& m) : Message(m) {}
    TradeCaptureReportRequest(const TradeCaptureReportRequest& m) : Message(m) {}
    static FIX::MsgType MsgType() { return FIX::MsgType("AD"); }

    TradeCaptureReportRequest(
      const FIX::TradeRequestID& aTradeRequestID,
      const FIX::TradeRequestType& aTradeRequestType )
    : Message(MsgType())
    {
      set(aTradeRequestID);
      set(aTradeRequestType);
    }

    FIELD_SET(*this, FIX::TradeRequestID);
    FIELD_SET(*this, FIX::TradeRequestType);
    FIELD_SET(*this, FIX::SubscriptionRequestType);
    FIELD_SET(*this, FIX::TradeReportID);
    FIELD_SET(*this, FIX::SecondaryTradeReportID);
    FIELD_SET(*this, FIX::ExecID);
    FIELD_SET(*this, FIX::ExecType);
    FIELD_SET(*this, FIX::OrderID);
    FIELD_SET(*this, FIX::ClOrdID);
    FIELD_SET(*this, FIX::MatchStatus);
    FIELD_SET(*this, FIX::TrdType);
    FIELD_SET(*this, FIX::TrdSubType);
    FIELD_SET(*this, FIX::TransferReason);
    FIELD_SET(*this, FIX::SecondaryTrdType);
    FIELD_SET(*this, FIX::TradeLinkID);
    FIELD_SET(*this, FIX::TrdMatchID);
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
    FIELD_SET(*this, FIX::Symbol);
    FIELD_SET(*this, FIX::SymbolSfx);
    FIELD_SET(*this, FIX::SecurityID);
    FIELD_SET(*this, FIX::SecurityIDSource);
    FIELD_SET(*this, FIX::Product);
    FIELD_SET(*this, FIX::CFICode);
    FIELD_SET(*this, FIX::SecurityType);
    FIELD_SET(*this, FIX::SecuritySubType);
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
    FIELD_SET(*this, FIX::StrikeCurrency);
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
    FIELD_SET(*this, FIX::Pool);
    FIELD_SET(*this, FIX::ContractSettlMonth);
    FIELD_SET(*this, FIX::CPProgram);
    FIELD_SET(*this, FIX::CPRegType);
    FIELD_SET(*this, FIX::DatedDate);
    FIELD_SET(*this, FIX::InterestAccrualDate);
    FIELD_SET(*this, FIX::SecurityStatus);
    FIELD_SET(*this, FIX::SettleOnOpenFlag);
    FIELD_SET(*this, FIX::InstrmtAssignmentMethod);
    FIELD_SET(*this, FIX::StrikeMultiplier);
    FIELD_SET(*this, FIX::StrikeValue);
    FIELD_SET(*this, FIX::MinPriceIncrement);
    FIELD_SET(*this, FIX::PositionLimit);
    FIELD_SET(*this, FIX::NTPositionLimit);
    FIELD_SET(*this, FIX::UnitOfMeasure);
    FIELD_SET(*this, FIX::TimeUnit);
    FIELD_SET(*this, FIX::MaturityTime);
    FIELD_SET(*this, FIX::DeliveryForm);
    FIELD_SET(*this, FIX::PctAtRisk);
    FIELD_SET(*this, FIX::AgreementDesc);
    FIELD_SET(*this, FIX::AgreementID);
    FIELD_SET(*this, FIX::AgreementDate);
    FIELD_SET(*this, FIX::AgreementCurrency);
    FIELD_SET(*this, FIX::TerminationType);
    FIELD_SET(*this, FIX::StartDate);
    FIELD_SET(*this, FIX::EndDate);
    FIELD_SET(*this, FIX::DeliveryType);
    FIELD_SET(*this, FIX::MarginRatio);
    FIELD_SET(*this, FIX::NoUnderlyings);
    class NoUnderlyings: public FIX::Group
    {
    public:
      static FIX::message_order const & getOrder() {
        static int const data[] = {311,312,309,305,462,463,310,763,313,542,241,242,243,244,245,246,256,595,592,593,594,247,316,941,317,436,435,308,306,362,363,307,364,365,877,878,318,879,810,882,883,884,885,886,972,975,973,974,998,1000,1038,1039,1044,1045,1046};
        static FIX::message_order const order(data, 55);
        return order;
      };
      NoUnderlyings () : FIX::Group(711,311,getOrder()) {}
      FIELD_SET(*this, FIX::UnderlyingSymbol);
      FIELD_SET(*this, FIX::UnderlyingSymbolSfx);
      FIELD_SET(*this, FIX::UnderlyingSecurityID);
      FIELD_SET(*this, FIX::UnderlyingSecurityIDSource);
      FIELD_SET(*this, FIX::UnderlyingProduct);
      FIELD_SET(*this, FIX::UnderlyingCFICode);
      FIELD_SET(*this, FIX::UnderlyingSecurityType);
      FIELD_SET(*this, FIX::UnderlyingSecuritySubType);
      FIELD_SET(*this, FIX::UnderlyingMaturityMonthYear);
      FIELD_SET(*this, FIX::UnderlyingMaturityDate);
      FIELD_SET(*this, FIX::UnderlyingCouponPaymentDate);
      FIELD_SET(*this, FIX::UnderlyingIssueDate);
      FIELD_SET(*this, FIX::UnderlyingRepoCollateralSecurityType);
      FIELD_SET(*this, FIX::UnderlyingRepurchaseTerm);
      FIELD_SET(*this, FIX::UnderlyingRepurchaseRate);
      FIELD_SET(*this, FIX::UnderlyingFactor);
      FIELD_SET(*this, FIX::UnderlyingCreditRating);
      FIELD_SET(*this, FIX::UnderlyingInstrRegistry);
      FIELD_SET(*this, FIX::UnderlyingCountryOfIssue);
      FIELD_SET(*this, FIX::UnderlyingStateOrProvinceOfIssue);
      FIELD_SET(*this, FIX::UnderlyingLocaleOfIssue);
      FIELD_SET(*this, FIX::UnderlyingRedemptionDate);
      FIELD_SET(*this, FIX::UnderlyingStrikePrice);
      FIELD_SET(*this, FIX::UnderlyingStrikeCurrency);
      FIELD_SET(*this, FIX::UnderlyingOptAttribute);
      FIELD_SET(*this, FIX::UnderlyingContractMultiplier);
      FIELD_SET(*this, FIX::UnderlyingCouponRate);
      FIELD_SET(*this, FIX::UnderlyingSecurityExchange);
      FIELD_SET(*this, FIX::UnderlyingIssuer);
      FIELD_SET(*this, FIX::EncodedUnderlyingIssuerLen);
      FIELD_SET(*this, FIX::EncodedUnderlyingIssuer);
      FIELD_SET(*this, FIX::UnderlyingSecurityDesc);
      FIELD_SET(*this, FIX::EncodedUnderlyingSecurityDescLen);
      FIELD_SET(*this, FIX::EncodedUnderlyingSecurityDesc);
      FIELD_SET(*this, FIX::UnderlyingCPProgram);
      FIELD_SET(*this, FIX::UnderlyingCPRegType);
      FIELD_SET(*this, FIX::UnderlyingCurrency);
      FIELD_SET(*this, FIX::UnderlyingQty);
      FIELD_SET(*this, FIX::UnderlyingPx);
      FIELD_SET(*this, FIX::UnderlyingDirtyPrice);
      FIELD_SET(*this, FIX::UnderlyingEndPrice);
      FIELD_SET(*this, FIX::UnderlyingStartValue);
      FIELD_SET(*this, FIX::UnderlyingCurrentValue);
      FIELD_SET(*this, FIX::UnderlyingEndValue);
      FIELD_SET(*this, FIX::UnderlyingAllocationPercent);
      FIELD_SET(*this, FIX::UnderlyingSettlementType);
      FIELD_SET(*this, FIX::UnderlyingCashAmount);
      FIELD_SET(*this, FIX::UnderlyingCashType);
      FIELD_SET(*this, FIX::UnderlyingUnitOfMeasure);
      FIELD_SET(*this, FIX::UnderlyingTimeUnit);
      FIELD_SET(*this, FIX::UnderlyingCapValue);
      FIELD_SET(*this, FIX::UnderlyingSettlMethod);
      FIELD_SET(*this, FIX::UnderlyingAdjustedQuantity);
      FIELD_SET(*this, FIX::UnderlyingFXRate);
      FIELD_SET(*this, FIX::UnderlyingFXRateCalc);
    };
    FIELD_SET(*this, FIX::NoLegs);
    class NoLegs: public FIX::Group
    {
    public:
      static FIX::message_order const & getOrder() {
        static int const data[] = {600,601,602,603,607,608,609,764,610,611,248,249,250,251,252,253,257,599,596,597,598,254,612,942,613,614,615,616,617,618,619,620,621,622,623,624,556,740,739,955,956,999,1001};
        static FIX::message_order const order(data, 43);
        return order;
      };
      NoLegs () : FIX::Group(555,600,getOrder()) {}
      FIELD_SET(*this, FIX::LegSymbol);
      FIELD_SET(*this, FIX::LegSymbolSfx);
      FIELD_SET(*this, FIX::LegSecurityID);
      FIELD_SET(*this, FIX::LegSecurityIDSource);
      FIELD_SET(*this, FIX::LegProduct);
      FIELD_SET(*this, FIX::LegCFICode);
      FIELD_SET(*this, FIX::LegSecurityType);
      FIELD_SET(*this, FIX::LegSecuritySubType);
      FIELD_SET(*this, FIX::LegMaturityMonthYear);
      FIELD_SET(*this, FIX::LegMaturityDate);
      FIELD_SET(*this, FIX::LegCouponPaymentDate);
      FIELD_SET(*this, FIX::LegIssueDate);
      FIELD_SET(*this, FIX::LegRepoCollateralSecurityType);
      FIELD_SET(*this, FIX::LegRepurchaseTerm);
      FIELD_SET(*this, FIX::LegRepurchaseRate);
      FIELD_SET(*this, FIX::LegFactor);
      FIELD_SET(*this, FIX::LegCreditRating);
      FIELD_SET(*this, FIX::LegInstrRegistry);
      FIELD_SET(*this, FIX::LegCountryOfIssue);
      FIELD_SET(*this, FIX::LegStateOrProvinceOfIssue);
      FIELD_SET(*this, FIX::LegLocaleOfIssue);
      FIELD_SET(*this, FIX::LegRedemptionDate);
      FIELD_SET(*this, FIX::LegStrikePrice);
      FIELD_SET(*this, FIX::LegStrikeCurrency);
      FIELD_SET(*this, FIX::LegOptAttribute);
      FIELD_SET(*this, FIX::LegContractMultiplier);
      FIELD_SET(*this, FIX::LegCouponRate);
      FIELD_SET(*this, FIX::LegSecurityExchange);
      FIELD_SET(*this, FIX::LegIssuer);
      FIELD_SET(*this, FIX::EncodedLegIssuerLen);
      FIELD_SET(*this, FIX::EncodedLegIssuer);
      FIELD_SET(*this, FIX::LegSecurityDesc);
      FIELD_SET(*this, FIX::EncodedLegSecurityDescLen);
      FIELD_SET(*this, FIX::EncodedLegSecurityDesc);
      FIELD_SET(*this, FIX::LegRatioQty);
      FIELD_SET(*this, FIX::LegSide);
      FIELD_SET(*this, FIX::LegCurrency);
      FIELD_SET(*this, FIX::LegPool);
      FIELD_SET(*this, FIX::LegDatedDate);
      FIELD_SET(*this, FIX::LegContractSettlMonth);
      FIELD_SET(*this, FIX::LegInterestAccrualDate);
      FIELD_SET(*this, FIX::LegUnitOfMeasure);
      FIELD_SET(*this, FIX::LegTimeUnit);
    };
    FIELD_SET(*this, FIX::NoDates);
    class NoDates: public FIX::Group
    {
    public:
      static FIX::message_order const & getOrder() {
        static int const data[] = {75,60,779};
        static FIX::message_order const order(data, 3);
        return order;
      };
      NoDates () : FIX::Group(580,75,getOrder()) {}
      FIELD_SET(*this, FIX::TradeDate);
      FIELD_SET(*this, FIX::TransactTime);
      FIELD_SET(*this, FIX::LastUpdateTime);
    };
    FIELD_SET(*this, FIX::ClearingBusinessDate);
    FIELD_SET(*this, FIX::TradingSessionID);
    FIELD_SET(*this, FIX::TradingSessionSubID);
    FIELD_SET(*this, FIX::TimeBracket);
    FIELD_SET(*this, FIX::Side);
    FIELD_SET(*this, FIX::MultiLegReportingType);
    FIELD_SET(*this, FIX::TradeInputSource);
    FIELD_SET(*this, FIX::TradeInputDevice);
    FIELD_SET(*this, FIX::ResponseTransportType);
    FIELD_SET(*this, FIX::ResponseDestination);
    FIELD_SET(*this, FIX::Text);
    FIELD_SET(*this, FIX::EncodedTextLen);
    FIELD_SET(*this, FIX::EncodedText);
    FIELD_SET(*this, FIX::MessageEventSource);
    FIELD_SET(*this, FIX::TradeID);
    FIELD_SET(*this, FIX::SecondaryTradeID);
    FIELD_SET(*this, FIX::FirmTradeID);
    FIELD_SET(*this, FIX::SecondaryFirmTradeID);
    FIELD_SET(*this, FIX::TradeHandlingInstr);
  };

}

#endif

#ifndef FIX50SP2_MARKETDATASNAPSHOTFULLREFRESH_H
#define FIX50SP2_MARKETDATASNAPSHOTFULLREFRESH_H

#include "Message.h"

namespace FIX50SP2
{

  class MarketDataSnapshotFullRefresh : public Message
  {
  public:
    MarketDataSnapshotFullRefresh() : Message(MsgType()) {}
    MarketDataSnapshotFullRefresh(const FIX::Message& m) : Message(m) {}
    MarketDataSnapshotFullRefresh(const Message& m) : Message(m) {}
    MarketDataSnapshotFullRefresh(const MarketDataSnapshotFullRefresh& m) : Message(m) {}
    static FIX::MsgType MsgType() { return FIX::MsgType("W"); }

    FIELD_SET(*this, FIX::MDReqID);
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
    FIELD_SET(*this, FIX::SecurityGroup);
    FIELD_SET(*this, FIX::MinPriceIncrementAmount);
    FIELD_SET(*this, FIX::UnitOfMeasureQty);
    FIELD_SET(*this, FIX::ProductComplex);
    FIELD_SET(*this, FIX::PriceUnitOfMeasure);
    FIELD_SET(*this, FIX::PriceUnitOfMeasureQty);
    FIELD_SET(*this, FIX::SettlMethod);
    FIELD_SET(*this, FIX::ExerciseStyle);
    FIELD_SET(*this, FIX::OptPayoutAmount);
    FIELD_SET(*this, FIX::PriceQuoteMethod);
    FIELD_SET(*this, FIX::ListMethod);
    FIELD_SET(*this, FIX::CapPrice);
    FIELD_SET(*this, FIX::FloorPrice);
    FIELD_SET(*this, FIX::PutOrCall);
    FIELD_SET(*this, FIX::FlexibleIndicator);
    FIELD_SET(*this, FIX::FlexProductEligibilityIndicator);
    FIELD_SET(*this, FIX::ValuationMethod);
    FIELD_SET(*this, FIX::ContractMultiplierUnit);
    FIELD_SET(*this, FIX::FlowScheduleType);
    FIELD_SET(*this, FIX::RestructuringType);
    FIELD_SET(*this, FIX::Seniority);
    FIELD_SET(*this, FIX::NotionalPercentageOutstanding);
    FIELD_SET(*this, FIX::OriginalNotionalPercentageOutstanding);
    FIELD_SET(*this, FIX::AttachmentPoint);
    FIELD_SET(*this, FIX::DetachmentPoint);
    FIELD_SET(*this, FIX::StrikePriceDeterminationMethod);
    FIELD_SET(*this, FIX::StrikePriceBoundaryMethod);
    FIELD_SET(*this, FIX::StrikePriceBoundaryPrecision);
    FIELD_SET(*this, FIX::UnderlyingPriceDeterminationMethod);
    FIELD_SET(*this, FIX::OptPayoutType);
    FIELD_SET(*this, FIX::NoUnderlyings);
    class NoUnderlyings: public FIX::Group
    {
    public:
      static FIX::message_order const & getOrder() {
        static int const data[] = {311,312,309,305,462,463,310,763,313,542,241,242,243,244,245,246,256,595,592,593,594,247,316,941,317,436,435,308,306,362,363,307,364,365,877,878,318,879,810,882,883,884,885,886,972,975,973,974,998,1000,1038,1039,1044,1045,1046,1213,315,1419,1423,1424,1425,1437,1441,1453,1454,1455,1456,1459,1460};
        static FIX::message_order const order(data, 69);
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
      FIELD_SET(*this, FIX::UnderlyingMaturityTime);
      FIELD_SET(*this, FIX::UnderlyingPutOrCall);
      FIELD_SET(*this, FIX::UnderlyingExerciseStyle);
      FIELD_SET(*this, FIX::UnderlyingUnitOfMeasureQty);
      FIELD_SET(*this, FIX::UnderlyingPriceUnitOfMeasure);
      FIELD_SET(*this, FIX::UnderlyingPriceUnitOfMeasureQty);
      FIELD_SET(*this, FIX::UnderlyingContractMultiplierUnit);
      FIELD_SET(*this, FIX::UnderlyingFlowScheduleType);
      FIELD_SET(*this, FIX::UnderlyingRestructuringType);
      FIELD_SET(*this, FIX::UnderlyingSeniority);
      FIELD_SET(*this, FIX::UnderlyingNotionalPercentageOutstanding);
      FIELD_SET(*this, FIX::UnderlyingOriginalNotionalPercentageOutstanding);
      FIELD_SET(*this, FIX::UnderlyingAttachmentPoint);
      FIELD_SET(*this, FIX::UnderlyingDetachmentPoint);
    };
    FIELD_SET(*this, FIX::NoLegs);
    class NoLegs: public FIX::Group
    {
    public:
      static FIX::message_order const & getOrder() {
        static int const data[] = {600,601,602,603,607,608,609,764,610,611,248,249,250,251,252,253,257,599,596,597,598,254,612,942,613,614,615,616,617,618,619,620,621,622,623,624,556,740,739,955,956,999,1001,1017,566,1212,1358,1420,1224,1421,1422,1436,1440};
        static FIX::message_order const order(data, 53);
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
      FIELD_SET(*this, FIX::LegOptionRatio);
      FIELD_SET(*this, FIX::LegPrice);
      FIELD_SET(*this, FIX::LegMaturityTime);
      FIELD_SET(*this, FIX::LegPutOrCall);
      FIELD_SET(*this, FIX::LegExerciseStyle);
      FIELD_SET(*this, FIX::LegUnitOfMeasureQty);
      FIELD_SET(*this, FIX::LegPriceUnitOfMeasure);
      FIELD_SET(*this, FIX::LegPriceUnitOfMeasureQty);
      FIELD_SET(*this, FIX::LegContractMultiplierUnit);
      FIELD_SET(*this, FIX::LegFlowScheduleType);
    };
    FIELD_SET(*this, FIX::FinancialStatus);
    FIELD_SET(*this, FIX::CorporateAction);
    FIELD_SET(*this, FIX::NetChgPrevDay);
    FIELD_SET(*this, FIX::NoMDEntries);
    class NoMDEntries: public FIX::Group
    {
    public:
      static FIX::message_order const & getOrder() {
        static int const data[] = {269,270,15,271,272,273,274,275,336,625,276,277,282,283,284,286,59,432,126,110,18,287,37,299,288,289,346,290,546,811,58,354,355,1023,528,1024,332,333,1020,63,64,1070,83,1048,1026,1027,278,453,198,40,423,235,236,701,696,697,698,218,220,221,222,662,663,699,761,1177,1093,326,327,120,1445,828,1025,31};
        static FIX::message_order const order(data, 74);
        return order;
      };
      NoMDEntries () : FIX::Group(268,269,getOrder()) {}
      FIELD_SET(*this, FIX::MDEntryType);
      FIELD_SET(*this, FIX::MDEntryPx);
      FIELD_SET(*this, FIX::Currency);
      FIELD_SET(*this, FIX::MDEntrySize);
      FIELD_SET(*this, FIX::MDEntryDate);
      FIELD_SET(*this, FIX::MDEntryTime);
      FIELD_SET(*this, FIX::TickDirection);
      FIELD_SET(*this, FIX::MDMkt);
      FIELD_SET(*this, FIX::TradingSessionID);
      FIELD_SET(*this, FIX::TradingSessionSubID);
      FIELD_SET(*this, FIX::QuoteCondition);
      FIELD_SET(*this, FIX::TradeCondition);
      FIELD_SET(*this, FIX::MDEntryOriginator);
      FIELD_SET(*this, FIX::LocationID);
      FIELD_SET(*this, FIX::DeskID);
      FIELD_SET(*this, FIX::OpenCloseSettlFlag);
      FIELD_SET(*this, FIX::TimeInForce);
      FIELD_SET(*this, FIX::ExpireDate);
      FIELD_SET(*this, FIX::ExpireTime);
      FIELD_SET(*this, FIX::MinQty);
      FIELD_SET(*this, FIX::ExecInst);
      FIELD_SET(*this, FIX::SellerDays);
      FIELD_SET(*this, FIX::OrderID);
      FIELD_SET(*this, FIX::QuoteEntryID);
      FIELD_SET(*this, FIX::MDEntryBuyer);
      FIELD_SET(*this, FIX::MDEntrySeller);
      FIELD_SET(*this, FIX::NumberOfOrders);
      FIELD_SET(*this, FIX::MDEntryPositionNo);
      FIELD_SET(*this, FIX::Scope);
      FIELD_SET(*this, FIX::PriceDelta);
      FIELD_SET(*this, FIX::Text);
      FIELD_SET(*this, FIX::EncodedTextLen);
      FIELD_SET(*this, FIX::EncodedText);
      FIELD_SET(*this, FIX::MDPriceLevel);
      FIELD_SET(*this, FIX::OrderCapacity);
      FIELD_SET(*this, FIX::MDOriginType);
      FIELD_SET(*this, FIX::HighPx);
      FIELD_SET(*this, FIX::LowPx);
      FIELD_SET(*this, FIX::TradeVolume);
      FIELD_SET(*this, FIX::SettlType);
      FIELD_SET(*this, FIX::SettlDate);
      FIELD_SET(*this, FIX::MDQuoteType);
      FIELD_SET(*this, FIX::RptSeq);
      FIELD_SET(*this, FIX::DealingCapacity);
      FIELD_SET(*this, FIX::MDEntrySpotRate);
      FIELD_SET(*this, FIX::MDEntryForwardPoints);
      FIELD_SET(*this, FIX::MDEntryID);
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
      FIELD_SET(*this, FIX::SecondaryOrderID);
      FIELD_SET(*this, FIX::OrdType);
      FIELD_SET(*this, FIX::PriceType);
      FIELD_SET(*this, FIX::YieldType);
      FIELD_SET(*this, FIX::Yield);
      FIELD_SET(*this, FIX::YieldCalcDate);
      FIELD_SET(*this, FIX::YieldRedemptionDate);
      FIELD_SET(*this, FIX::YieldRedemptionPrice);
      FIELD_SET(*this, FIX::YieldRedemptionPriceType);
      FIELD_SET(*this, FIX::Spread);
      FIELD_SET(*this, FIX::BenchmarkCurveCurrency);
      FIELD_SET(*this, FIX::BenchmarkCurveName);
      FIELD_SET(*this, FIX::BenchmarkCurvePoint);
      FIELD_SET(*this, FIX::BenchmarkPrice);
      FIELD_SET(*this, FIX::BenchmarkPriceType);
      FIELD_SET(*this, FIX::BenchmarkSecurityID);
      FIELD_SET(*this, FIX::BenchmarkSecurityIDSource);
      FIELD_SET(*this, FIX::NoOfSecSizes);
      class NoOfSecSizes: public FIX::Group
      {
      public:
        static FIX::message_order const & getOrder() {
          static int const data[] = {1178,1179};
          static FIX::message_order const order(data, 2);
          return order;
        };
        NoOfSecSizes () : FIX::Group(1177,1178,getOrder()) {}
        FIELD_SET(*this, FIX::MDSecSizeType);
        FIELD_SET(*this, FIX::MDSecSize);
      };
      FIELD_SET(*this, FIX::LotType);
      FIELD_SET(*this, FIX::SecurityTradingStatus);
      FIELD_SET(*this, FIX::HaltReasonInt);
      FIELD_SET(*this, FIX::SettlCurrency);
      FIELD_SET(*this, FIX::NoRateSources);
      class NoRateSources: public FIX::Group
      {
      public:
        static FIX::message_order const & getOrder() {
          static int const data[] = {1446,1447,1448};
          static FIX::message_order const order(data, 3);
          return order;
        };
        NoRateSources () : FIX::Group(1445,1446,getOrder()) {}
        FIELD_SET(*this, FIX::RateSource);
        FIELD_SET(*this, FIX::RateSourceType);
        FIELD_SET(*this, FIX::ReferencePage);
      };
      FIELD_SET(*this, FIX::TrdType);
      FIELD_SET(*this, FIX::FirstPx);
      FIELD_SET(*this, FIX::LastPx);
    };
    FIELD_SET(*this, FIX::ApplQueueDepth);
    FIELD_SET(*this, FIX::ApplQueueResolution);
    FIELD_SET(*this, FIX::MDReportID);
    FIELD_SET(*this, FIX::ClearingBusinessDate);
    FIELD_SET(*this, FIX::MDBookType);
    FIELD_SET(*this, FIX::MDFeedType);
    FIELD_SET(*this, FIX::TradeDate);
    FIELD_SET(*this, FIX::NoRoutingIDs);
    class NoRoutingIDs: public FIX::Group
    {
    public:
      static FIX::message_order const & getOrder() {
        static int const data[] = {216,217};
        static FIX::message_order const order(data, 2);
        return order;
      };
      NoRoutingIDs () : FIX::Group(215,216,getOrder()) {}
      FIELD_SET(*this, FIX::RoutingType);
      FIELD_SET(*this, FIX::RoutingID);
    };
    FIELD_SET(*this, FIX::MDSubBookType);
    FIELD_SET(*this, FIX::MarketDepth);
    FIELD_SET(*this, FIX::TotNumReports);
    FIELD_SET(*this, FIX::RefreshIndicator);
    FIELD_SET(*this, FIX::ApplID);
    FIELD_SET(*this, FIX::ApplSeqNum);
    FIELD_SET(*this, FIX::ApplLastSeqNum);
    FIELD_SET(*this, FIX::ApplResendFlag);
    FIELD_SET(*this, FIX::MDStreamID);
  };

}

#endif

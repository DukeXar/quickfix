#ifndef FIX50_ORDERMASSSTATUSREQUEST_H
#define FIX50_ORDERMASSSTATUSREQUEST_H

#include "Message.h"

namespace FIX50
{

  class OrderMassStatusRequest : public Message
  {
  public:
    OrderMassStatusRequest() : Message(MsgType()) {}
    OrderMassStatusRequest(const FIX::Message& m) : Message(m) {}
    OrderMassStatusRequest(const Message& m) : Message(m) {}
    OrderMassStatusRequest(const OrderMassStatusRequest& m) : Message(m) {}
    static FIX::MsgType MsgType() { return FIX::MsgType("AF"); }

    OrderMassStatusRequest(
      const FIX::MassStatusReqID& aMassStatusReqID,
      const FIX::MassStatusReqType& aMassStatusReqType )
    : Message(MsgType())
    {
      set(aMassStatusReqID);
      set(aMassStatusReqType);
    }

    FIELD_SET(*this, FIX::MassStatusReqID);
    FIELD_SET(*this, FIX::MassStatusReqType);
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
    FIELD_SET(*this, FIX::TradingSessionID);
    FIELD_SET(*this, FIX::TradingSessionSubID);
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
    FIELD_SET(*this, FIX::Side);
  };

}

#endif

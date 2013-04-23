#ifndef FIX50SP2_PARTYDETAILSLISTREPORT_H
#define FIX50SP2_PARTYDETAILSLISTREPORT_H

#include "Message.h"

namespace FIX50SP2
{

  class PartyDetailsListReport : public Message
  {
  public:
    PartyDetailsListReport() : Message(MsgType()) {}
    PartyDetailsListReport(const FIX::Message& m) : Message(m) {}
    PartyDetailsListReport(const Message& m) : Message(m) {}
    PartyDetailsListReport(const PartyDetailsListReport& m) : Message(m) {}
    static FIX::MsgType MsgType() { return FIX::MsgType("CG"); }

    PartyDetailsListReport(
      const FIX::PartyDetailsListReportID& aPartyDetailsListReportID )
    : Message(MsgType())
    {
      set(aPartyDetailsListReportID);
    }

    FIELD_SET(*this, FIX::ApplID);
    FIELD_SET(*this, FIX::ApplSeqNum);
    FIELD_SET(*this, FIX::ApplLastSeqNum);
    FIELD_SET(*this, FIX::ApplResendFlag);
    FIELD_SET(*this, FIX::PartyDetailsListReportID);
    FIELD_SET(*this, FIX::PartyDetailsListRequestID);
    FIELD_SET(*this, FIX::PartyDetailsRequestResult);
    FIELD_SET(*this, FIX::TotNoPartyList);
    FIELD_SET(*this, FIX::LastFragment);
    FIELD_SET(*this, FIX::NoPartyList);
    class NoPartyList: public FIX::Group
    {
    public:
      static FIX::message_order const & getOrder() {
        static int const data[] = {448,447,452,1562};
        static FIX::message_order const order(data, 4);
        return order;
      };
      NoPartyList () : FIX::Group(1513,448,getOrder()) {}
      FIELD_SET(*this, FIX::PartyID);
      FIELD_SET(*this, FIX::PartyIDSource);
      FIELD_SET(*this, FIX::PartyRole);
      FIELD_SET(*this, FIX::NoRelatedPartyIDs);
      class NoRelatedPartyIDs: public FIX::Group
      {
      public:
        static FIX::message_order const & getOrder() {
          static int const data[] = {1563,1564,1565,1514};
          static FIX::message_order const order(data, 4);
          return order;
        };
        NoRelatedPartyIDs () : FIX::Group(1562,1563,getOrder()) {}
        FIELD_SET(*this, FIX::RelatedPartyID);
        FIELD_SET(*this, FIX::RelatedPartyIDSource);
        FIELD_SET(*this, FIX::RelatedPartyRole);
        FIELD_SET(*this, FIX::NoPartyRelationships);
        class NoPartyRelationships: public FIX::Group
        {
        public:
          static FIX::message_order const & getOrder() {
            static int const data[] = {1515};
            static FIX::message_order const order(data, 1);
            return order;
          };
          NoPartyRelationships () : FIX::Group(1514,1515,getOrder()) {}
          FIELD_SET(*this, FIX::PartyRelationship);
        };
      };
    };
    FIELD_SET(*this, FIX::Text);
    FIELD_SET(*this, FIX::EncodedTextLen);
    FIELD_SET(*this, FIX::EncodedText);
  };

}

#endif

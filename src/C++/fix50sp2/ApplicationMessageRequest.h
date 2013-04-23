#ifndef FIX50SP2_APPLICATIONMESSAGEREQUEST_H
#define FIX50SP2_APPLICATIONMESSAGEREQUEST_H

#include "Message.h"

namespace FIX50SP2
{

  class ApplicationMessageRequest : public Message
  {
  public:
    ApplicationMessageRequest() : Message(MsgType()) {}
    ApplicationMessageRequest(const FIX::Message& m) : Message(m) {}
    ApplicationMessageRequest(const Message& m) : Message(m) {}
    ApplicationMessageRequest(const ApplicationMessageRequest& m) : Message(m) {}
    static FIX::MsgType MsgType() { return FIX::MsgType("BW"); }

    ApplicationMessageRequest(
      const FIX::ApplReqID& aApplReqID,
      const FIX::ApplReqType& aApplReqType )
    : Message(MsgType())
    {
      set(aApplReqID);
      set(aApplReqType);
    }

    FIELD_SET(*this, FIX::ApplReqID);
    FIELD_SET(*this, FIX::ApplReqType);
    FIELD_SET(*this, FIX::NoApplIDs);
    class NoApplIDs: public FIX::Group
    {
    public:
      static FIX::message_order const & getOrder() {
        static int const data[] = {1355,1182,1183,539,1433};
        static FIX::message_order const order(data, 5);
        return order;
      };
      NoApplIDs () : FIX::Group(1351,1355,getOrder()) {}
      FIELD_SET(*this, FIX::RefApplID);
      FIELD_SET(*this, FIX::ApplBegSeqNum);
      FIELD_SET(*this, FIX::ApplEndSeqNum);
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
      FIELD_SET(*this, FIX::RefApplReqID);
    };
    FIELD_SET(*this, FIX::Text);
    FIELD_SET(*this, FIX::EncodedTextLen);
    FIELD_SET(*this, FIX::EncodedText);
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
  };

}

#endif

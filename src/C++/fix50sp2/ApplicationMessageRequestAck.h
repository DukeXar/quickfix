#ifndef FIX50SP2_APPLICATIONMESSAGEREQUESTACK_H
#define FIX50SP2_APPLICATIONMESSAGEREQUESTACK_H

#include "Message.h"

namespace FIX50SP2
{

  class ApplicationMessageRequestAck : public Message
  {
  public:
    ApplicationMessageRequestAck() : Message(MsgType()) {}
    ApplicationMessageRequestAck(const FIX::Message& m) : Message(m) {}
    ApplicationMessageRequestAck(const Message& m) : Message(m) {}
    ApplicationMessageRequestAck(const ApplicationMessageRequestAck& m) : Message(m) {}
    static FIX::MsgType MsgType() { return FIX::MsgType("BX"); }

    ApplicationMessageRequestAck(
      const FIX::ApplResponseID& aApplResponseID )
    : Message(MsgType())
    {
      set(aApplResponseID);
    }

    FIELD_SET(*this, FIX::ApplResponseID);
    FIELD_SET(*this, FIX::ApplReqID);
    FIELD_SET(*this, FIX::ApplReqType);
    FIELD_SET(*this, FIX::ApplResponseType);
    FIELD_SET(*this, FIX::ApplTotalMessageCount);
    FIELD_SET(*this, FIX::NoApplIDs);
    class NoApplIDs: public FIX::Group
    {
    public:
      static FIX::message_order const & getOrder() {
        static int const data[] = {1355,1182,1183,1357,1354,539,1433};
        static FIX::message_order const order(data, 7);
        return order;
      };
      NoApplIDs () : FIX::Group(1351,1355,getOrder()) {}
      FIELD_SET(*this, FIX::RefApplID);
      FIELD_SET(*this, FIX::ApplBegSeqNum);
      FIELD_SET(*this, FIX::ApplEndSeqNum);
      FIELD_SET(*this, FIX::RefApplLastSeqNum);
      FIELD_SET(*this, FIX::ApplResponseError);
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

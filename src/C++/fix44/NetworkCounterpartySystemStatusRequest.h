#ifndef FIX44_NETWORKCOUNTERPARTYSYSTEMSTATUSREQUEST_H
#define FIX44_NETWORKCOUNTERPARTYSYSTEMSTATUSREQUEST_H

#include "Message.h"

namespace FIX44
{

  class NetworkCounterpartySystemStatusRequest : public Message
  {
  public:
    NetworkCounterpartySystemStatusRequest() : Message(MsgType()) {}
    NetworkCounterpartySystemStatusRequest(const FIX::Message& m) : Message(m) {}
    NetworkCounterpartySystemStatusRequest(const Message& m) : Message(m) {}
    NetworkCounterpartySystemStatusRequest(const NetworkCounterpartySystemStatusRequest& m) : Message(m) {}
    static FIX::MsgType MsgType() { return FIX::MsgType("BC"); }

    NetworkCounterpartySystemStatusRequest(
      const FIX::NetworkRequestType& aNetworkRequestType,
      const FIX::NetworkRequestID& aNetworkRequestID )
    : Message(MsgType())
    {
      set(aNetworkRequestType);
      set(aNetworkRequestID);
    }

    FIELD_SET(*this, FIX::NetworkRequestType);
    FIELD_SET(*this, FIX::NetworkRequestID);
    FIELD_SET(*this, FIX::NoCompIDs);
    class NoCompIDs: public FIX::Group
    {
    public:
      static FIX::message_order const & getOrder() {
        static int const data[] = {930,931,283,284};
        static FIX::message_order const order(data, 4);
        return order;
      };
      NoCompIDs () : FIX::Group(936,930,getOrder()) {}
      FIELD_SET(*this, FIX::RefCompID);
      FIELD_SET(*this, FIX::RefSubID);
      FIELD_SET(*this, FIX::LocationID);
      FIELD_SET(*this, FIX::DeskID);
    };
  };

}

#endif

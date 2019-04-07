#include "CANMessage.h"
#include <cstring>

namespace CANSocket {
CANMessage::CANMessage()
: m_canIdMask(0)
, m_payloadSize(0)
{
  memset( m_payload, 0, 8 );
  m_messageTimeStamp.tv_sec = 0;
  m_messageTimeStamp.tv_usec = 0;

}

CANMessage::~CANMessage()
{
}

unsigned int CANMessage::GetCANId() const
{
  return ( 0x1fffffff & m_canIdMask );
}

bool CANMessage::GetErrorFlag() const
{
  return ( 0x20000000 & m_canIdMask ); 
}

bool CANMessage::GetRTRFlag() const
{
  return ( 0x40000000 & m_canIdMask ); 
}

bool CANMessage::GetExtendedIdFlag() const
{
  return ( 0x80000000 & m_canIdMask ); 
}

const unsigned char* CANMessage::GetDataPayload() const
{
  return m_payload;
}

unsigned int CANMessage::GetPayloadSize() const
{
  return m_payloadSize;
}

struct timeval& CANMessage::GetWritableTimeStamp()
{
  return m_messageTimeStamp;
}

const struct timeval& CANMessage::GetTimeStamp() const
{
  return m_messageTimeStamp;
}

void CANMessage::SetCANId( const unsigned int messageId)
{
  m_canIdMask = messageId;
}

void CANMessage::SetPayload( const unsigned char payload[], unsigned char size)
{
  m_payloadSize = size;
  memcpy( m_payload, payload, m_payloadSize); 
}

}

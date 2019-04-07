#pragma once
#include <sys/time.h>

namespace CANSocket {
class CANMessage{
public:
  CANMessage();
  ~CANMessage();

  unsigned int GetCANId() const;
  bool GetErrorFlag() const;
  bool GetRTRFlag() const;
  bool GetExtendedIdFlag() const;
  const unsigned char* GetDataPayload() const;
  unsigned int GetPayloadSize() const;

  struct timeval& GetWritableTimeStamp();
  const struct timeval& GetTimeStamp() const;

  void SetCANId( const unsigned int messageId);
  void SetPayload( const unsigned char payload[], unsigned char size);

private:
  CANMessage(const CANMessage&);
  CANMessage& operator=(const CANMessage&);


private:
  /*
   * Controller Area Network Identifier structure
   *
   * bit 0-28	: CAN identifier (11/29 bit)
   * bit 29	: error message frame flag (0 = data frame, 1 = error message)
   * bit 30	: remote transmission request flag (1 = rtr frame)
   * bit 31	: frame format flag (0 = standard 11 bit, 1 = extended 29 bit)
   */
  unsigned int m_canIdMask;

  unsigned char m_payload[8];
  unsigned char m_payloadSize;

  struct timeval m_messageTimeStamp;
};
}

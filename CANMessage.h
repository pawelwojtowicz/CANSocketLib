#pragma once

namespace CANSocket {
class CANMessage{
public:
  CANMessage();
  ~CANMessage();

private:
  CANMessage(const CANMessage&);
  CANMessage& operator=(const CANMessage&);
};
}

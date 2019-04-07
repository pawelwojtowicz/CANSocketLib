#pragma once
#include "ICANDriver.h"

namespace CANSocket{
class CANDriver :public ICANDriver {
public:
  CANDriver();
  virtual ~CANDriver();

  virtual bool Open(const std::string& port);
  virtual void Close();

  virtual bool GetMessage( CANMessage& rMessage );
  virtual bool SendMessage( const CANMessage& rMessage);
   
private:
  int m_fdSocketCAN;

};
}

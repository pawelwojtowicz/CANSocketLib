#include "CCANDriver.h"

namespace CANSocket{
CANDriver::CANDriver()
: m_fdSocketCAN(-1)
{
}

CANDriver::~CANDriver()
{
}

bool CANDriver::Open(const std::string& port)
{
  bool retVal(false);
  if ( -1 !=m_fdSocketCAN)
  {
    Close();
  }

  return retVal;
}

void CANDriver::Close()
{
  if ( -1 !=m_fdSocketCAN)
  {
  }
}

bool CANDriver::GetMessage( CANMessage& rMessage )
{
  bool retVal(false);
  if ( -1 !=m_fdSocketCAN)
  {
  }
  return retVal;
}

bool SendMessage( const CANMessage& rMessage)
{
  bool retVal(false);
  if ( -1 !=m_fdSocketCAN)
  {
  }
  return retVal;
}
   
}

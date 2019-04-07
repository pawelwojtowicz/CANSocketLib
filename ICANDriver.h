#pragma once

namespace CANSocket{
class CANMessage;

class ICANDriver {
public:
  ICANDriver() {};
  virtual ~ICANDriver() {};

  virtual bool Open(const std::string& port) = 0;
  virtual void Close() = 0;

  virtual bool GetMessage( CANMessage& rMessage ) = 0;
  virtual bool SendMessage( const CANMessage& rMessage) = 0;

private:
  ICANDriver(const ICANDriver&);
  ICANDriver& operator=(const ICANDriver&);

};
}

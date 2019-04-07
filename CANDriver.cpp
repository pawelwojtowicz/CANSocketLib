#include "CANDriver.h"
#include "CANMessage.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <linux/can.h>
#include <linux/can/raw.h>
#include <net/if.h>
#include <sys/socket.h>
#include <sys/ioctl.h>


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
  if ( -1 != m_fdSocketCAN)
  {
    Close();
  }

  m_fdSocketCAN = socket(PF_CAN, SOCK_RAW, CAN_RAW);

  if ( m_fdSocketCAN < 0 )
  {
    perror("Cannot open the CAN socket");
    return false;
  }

  const char* ifName = port.c_str();
  struct ifreq ifr;

  strcpy(ifr.ifr_name, ifName);
  ioctl(m_fdSocketCAN, SIOCGIFINDEX, &ifr);

  struct sockaddr_can addr;
  addr.can_family  = AF_CAN;
  addr.can_ifindex = ifr.ifr_ifindex;

  if(bind( m_fdSocketCAN, (struct sockaddr *)&addr, sizeof(addr) ) < 0 ) 
  {
    perror("Cannot bind the CAN Socket");
    return false;
  }

  return true;
}

void CANDriver::Close()
{
  if ( -1 != m_fdSocketCAN)
  {
  }
}

bool CANDriver::GetMessage( CANMessage& rMessage )
{
  if ( -1 != m_fdSocketCAN)
  {
    //    struct can_frame {
    //            canid_t can_id;  /* 32 bit CAN_ID + EFF/RTR/ERR flags */
    //            __u8    can_dlc; /* frame payload length in byte (0 .. 8) */
    //            __u8    __pad;   /* padding */
    //            __u8    __res0;  /* reserved / padding */
    //            __u8    __res1;  /* reserved / padding */
    //            __u8    data[8] __attribute__((aligned(8)));
    //    };
    struct can_frame frame;
    int nbytes = read(m_fdSocketCAN, &frame, sizeof(struct can_frame));

    rMessage.SetCANId( frame.can_id );
    rMessage.SetPayload( frame.data, frame.can_dlc );

    ioctl( m_fdSocketCAN, SIOCGSTAMP, &rMessage.GetWritableTimeStamp() );

  }
  return false;
}

bool CANDriver::SendMessage( const CANMessage& rMessage)
{
  bool retVal(false);
  if ( -1 != m_fdSocketCAN)
  {
    struct can_frame frame;

    int nbytes = write(m_fdSocketCAN, &frame, sizeof(struct can_frame));
  }
  return retVal;
}
   
}

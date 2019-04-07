project( CANSocketLib )

SET( OUTPUT_NAME CANSocketLib )

add_library( ${OUTPUT_NAME} SHARED
CANMessage.cpp
CANDriver.cpp
)

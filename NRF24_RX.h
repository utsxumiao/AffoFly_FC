/* Tested with 16MHz ATmega328p-AP, QuadX and https://github.com/gcopeland/RF24
Motors use pins 9,6,5,3 instead of 9,10,11,3
nRF24 connections (left is nRF24, right is arduino):q
  CE      7
  CSN    10
  MOSI   11
  MISO   12
  SCK    13
You can change CE and CSN in NRF24_RX.cpp
*/

#ifndef NRF24_RX_H_
#define NRF24_RX_H_

#include "config.h"

#if defined(NRF24_RX)

// The sizeof this struct should not exceed 32 ints
struct ControlData {
  uint32_t Token;
  uint16_t Throttle;
  uint16_t Yaw;
  uint16_t Pitch;
  uint16_t Roll;
  uint16_t Aux1;
  uint16_t Aux2;
  uint16_t Aux3;
  uint16_t Aux4;
};

extern int16_t nrf24_rcData[RC_CHANS];

void NRF24_Init();
void NRF24_Read_RC();

#endif

#endif /* NRF24_RX_H_ */

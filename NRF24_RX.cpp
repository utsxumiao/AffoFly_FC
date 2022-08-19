#include "Arduino.h"
#include "config.h"
#include "def.h"
#include "types.h"
#include "MultiWii.h"
#include <RF24.h>
#include "NRF24_RX.h"

#if defined(NRF24_RX)

#define NRF_CE_PIN              7
#define NRF_CSN_PIN             10
#define RADIO_PIPE              0xE8E8F0F0E1LL
#define RADIO_CHANNEL           125
#define RADIO_SECURITY_TOKEN    998789
#define RC_DATA_OFFSET          2

int16_t nrf24_rcData[RC_CHANS];
RF24 radio(NRF_CE_PIN, NRF_CSN_PIN); // CE, CSN
ControlData controlData;

void radio_setup() {
  radio.begin();
  radio.setPALevel(RF24_PA_MIN);
  radio.setAutoAck(false);
  radio.setChannel(RADIO_CHANNEL);
  radio.setDataRate(RF24_250KBPS);
  radio.openReadingPipe(1, RADIO_PIPE);
  radio.startListening();
}

void resetRF24Data()
{
  controlData.Token = RADIO_SECURITY_TOKEN;
  controlData.Throttle = 1000;
  controlData.Yaw = 1500;
  controlData.Pitch = 1500;
  controlData.Roll = 1500;
  controlData.Aux1 = 1000;
  controlData.Aux2 = 1000;
  controlData.Aux3 = 1000;
  controlData.Aux4 = 1000;
}

void NRF24_Read_RC() {
  uint32_t previousSignalTime = 0;
  uint32_t currentTime = millis();

  ControlData tempData;
  if(radio.available()) {
    radio.read(&tempData, sizeof(ControlData));
    if (tempData.Token == RADIO_SECURITY_TOKEN) {
      controlData = tempData;
      previousSignalTime = currentTime;
    }
  }
  
  nrf24_rcData[THROTTLE] = controlData.Throttle + RC_DATA_OFFSET;
  nrf24_rcData[ROLL] = controlData.Roll + RC_DATA_OFFSET;
  nrf24_rcData[PITCH] = controlData.Pitch + RC_DATA_OFFSET;
  nrf24_rcData[YAW] = controlData.Yaw + RC_DATA_OFFSET;
  nrf24_rcData[AUX1] = controlData.Aux1 + RC_DATA_OFFSET;
  nrf24_rcData[AUX2] = controlData.Aux2 + RC_DATA_OFFSET;
  nrf24_rcData[AUX3] = controlData.Aux3 + RC_DATA_OFFSET;
  nrf24_rcData[AUX4] = controlData.Aux4 + RC_DATA_OFFSET;
}

void NRF24_Init() {
  resetRF24Data();
  radio_setup();
  DDRD |= B00010000; //set pin4 as output
}

#endif

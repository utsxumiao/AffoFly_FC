#ifndef RX_H_
#define RX_H_

void configureReceiver();
void computeRC();
uint16_t readRawRC(uint8_t chan);
void readSerial_RX(void);
#if defined(OPENLRSv2MULTI)
  void initOpenLRS(void);
  void Read_OpenLRS_RC(void);
#endif
#if defined(SPEK_BIND)  // Bind Support
  void spekBind(void);
#endif
#if defined(NRF24_RX)
  void readNRF24_RX();
#endif

#endif /* RX_H_ */

#ifndef GroveLEDBar_H
#define GroveLEDBar_H

#include <Arduino.h>

// Avoid name conflict
#define GLB_CMDMODE 0x00  // Work on 8-bit mode
#define GLB_ON      0xff  // 8-bit 1 data
#define GLB_OFF     0x00  // 8-bit 0 data

class GroveLEDBar
{

private:

  unsigned int _pinClock;  // Clock pin
  unsigned int _pinData;   // Data pin
  unsigned char _statesLED[10];// Led state, brightness for each LED
  unsigned char _globalBrightness;

  void sendData(unsigned int data);  // Send a word to led bar
  void latchData(void);              // Load data into the latch register
  void refresh();//Set data array
  void _turnOnLED(unsigned char idLED);
  void _turnOffLED(unsigned char idLED);
  void _toggleLED(unsigned char idLED);

public:

  GroveLEDBar(GrovePin pins);
  void initialize();
  void setGlobalBrightness(float brightness); // 0-1
  void turnOnLED(unsigned char idLED);
  void turnOffLED(unsigned char idLED);
  void toggleLED(unsigned char idLED);
  void turnOnAllLED();
  void turnOffAllLED();
  void toggleAllLED();
  void setLEDBrightness(unsigned char idLED, float brightness);
  void setLEDStates(unsigned int bits);
  unsigned int getLEDStates();
  void setLevel(unsigned char level);
};

#endif
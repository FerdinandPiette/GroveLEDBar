# GroveLEDBar
LED Bar Library for Arduino + Grove shield

[Link to the tested grove module](http://wiki.seeed.cc/Grove-LED_Bar/)

##Example
```c++
#include <GroveLEDBar.h>

GroveLEDBar bar;

void setup() {
  bar.initialize(GROVE_D6);
  bar.setGlobalBrightness(255);
}

void loop() {
  bar.turnOffAllLED();
  delay(1000);
  bar.turnOnAllLED();
  delay(1000);
  bar.turnOffAllLED();
  delay(1000);
  
  bar.turnOnLED(0);
  delay(500);
  bar.turnOnLED(2);
  delay(500);
  bar.turnOnLED(4);
  delay(500);
  bar.turnOnLED(6);
  delay(500);
  bar.turnOnLED(8);
  delay(500);

  bar.toggleAllLED();
  delay(1500);
  
  bar.toggleLED(0);
  delay(200);  
  bar.toggleLED(1);
  delay(200);  
  bar.toggleLED(2);
  delay(200);
  bar.toggleLED(3);
  delay(200);
  bar.toggleLED(4);
  delay(200);
  bar.toggleLED(5);
  delay(200);
  bar.toggleLED(6);
  delay(200);
  bar.toggleLED(7);
  delay(200);
  bar.toggleLED(8);
  delay(200);
  bar.toggleLED(9);
  delay(1200);


  bar.setLevel(0);
  delay(200);
  bar.setLevel(1);
  delay(200);
  bar.setLevel(2);
  delay(200);
  bar.setLevel(3);
  delay(200);
  bar.setLevel(4);
  delay(200);
  bar.setLevel(5);
  delay(200);
  bar.setLevel(6);
  delay(200);
  bar.setLevel(7);
  delay(200);
  bar.setLevel(8);
  delay(200);
  bar.setLevel(9);
  delay(200);
  bar.setLevel(10);
  delay(2000);
}
```

##Documentation

###`void initialize(GrovePin pins)`
Initialize the sensor before using it.

Parameters:
- `pins`: Must be a digital socket (GROVE_D2 to GROVE_D8)

###`void setGlobalBrightness(float brightness)`
Change the brightness of all the LEDs

Parameters:
- `brightness`: A number between 0 and 1 corresponding to the desired brightness of the LEDs (0: the LEDs are OFF ; 1: the LEDs get full power)

###`void turnOnLED(unsigned char idLED)`
Turn on the LED number `idLED`.

Parameters:
- `idLED`: The number of the LED (0-9)

###`void turnOffLED(unsigned char idLED)`
Turn off the LED number `idLED`.

Parameters:
- `idLED`: The number of the LED (0-9)

###`void toggleLED(unsigned char idLED)`
Change the state of the LED number `idLED`.

Parameters:
- `idLED`: The number of the LED (0-9)

###`void turnOnAllLED()`
Turn on all the LEDs.

###`void turnOffAllLED()`
Turn off all the LEDs.

###`void toggleAllLED()`
Change the state of all the LEDs.

###`void setLEDBrightness(unsigned char idLED, float brightness)`
Change the brightness of a specific LED.

Parameters:
- `idLED`: The number of the LED (0-9)
- `brightness`: The brightness of the LED (0-1)

###`void setLEDStates(unsigned int bits)`
Change the state of all the LEDs.

Parameters:
- `bits`: A 16bits number. Each bit represent a state of a LED : 0 is off - 1 id on. 

bit0 correspond to the state LED0 and so on.

Example : `0b0000001000100001` - The LEDs 0, 5 and 9 are on, the other are off.

###`unsigned int getLEDStates()`
Return a 16bits number where each bit represent the state of a LED (0 is off - 1 is on).

bit0 correspond to the state LED0 and so on.

Example : `0b0000001000100001` - The LEDs 0, 5 and 9 are on, the other are off.

###`void setLevel(unsigned char level)`
Turn on a certain number of LEDs from LED0 to LED9.

Parameters:
- `level`: A number between 0 and 9 corresponding to the number of LED on
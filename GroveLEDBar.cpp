#include "GroveLEDBar.h"

GroveLEDBar::GroveLEDBar()
{
	this->setGlobalBrightness(192);

	for (unsigned char indexLED = 0; indexLED < 10; ++indexLED) {
		this->_statesLED[indexLED] = 0;
	}
}

void GroveLEDBar::initialize(GrovePin pins) {
	this->_pinClock = pins.pin2;
	this->_pinData = pins.pin1;	
	pinMode(this->_pinClock, OUTPUT);
	pinMode(this->_pinData, OUTPUT);
	this->refresh();
}

// Send the latch command
void GroveLEDBar::latchData()
{
  digitalWrite(this->_pinData, LOW);
  delayMicroseconds(10);

  for (unsigned char i = 0; i < 4; i++)
  {
    digitalWrite(this->_pinData, HIGH);
    digitalWrite(this->_pinData, LOW);
  }
}


// Send 16 bits of data
void GroveLEDBar::sendData(unsigned int data)
{
  for (unsigned char i = 0; i < 16; i++)
  {
    unsigned int state = (data & 0x8000) ? HIGH : LOW;
    digitalWrite(this->_pinData, state);

    state = digitalRead(this->_pinClock) ? LOW : HIGH;
    digitalWrite(this->_pinClock, state);

    data <<= 1;
  }
}

// each element in the state will hold the brightness level
// 00000000 darkest
// 00000011 brighter
// ........
// 11111111 brightest
void GroveLEDBar::refresh()
{
	sendData(GLB_CMDMODE);

	for (unsigned char i = 0; i < 10; i++)
	{
		this->sendData(this->_statesLED[9-i]);
	}

	// Two extra empty bits for padding the command to the correct length
	this->sendData(0x00);
	this->sendData(0x00);

	this->latchData();
}

void GroveLEDBar::_turnOnLED(unsigned char idLED) {
	if(idLED > 9) { return; }
	this->_statesLED[idLED] = this->_globalBrightness;
}

void GroveLEDBar::_turnOffLED(unsigned char idLED) {
	if(idLED > 9) { return; }
	this->_statesLED[idLED] = 0;
}

void GroveLEDBar::_toggleLED(unsigned char idLED)
{
	if(idLED > 9) { return; }	
	this->_statesLED[idLED] ? this->_turnOffLED(idLED) : this->_turnOnLED(idLED);
}

void GroveLEDBar::setGlobalBrightness(float brightness) {
	this->_globalBrightness = brightness*255;
}
 
void GroveLEDBar::turnOnLED(unsigned char idLED) {
	this->_turnOnLED(idLED);
	this->refresh();
}
 
void GroveLEDBar::turnOffLED(unsigned char idLED) {
	this->_turnOffLED(idLED);
	this->refresh();
}
 
void GroveLEDBar::toggleLED(unsigned char idLED)
{
	this->_toggleLED(idLED);
	this->refresh();
}
 
void GroveLEDBar::toggleAllLED()
{
	for(unsigned char indexLED = 0; indexLED < 10; ++indexLED) {
		this->_toggleLED(indexLED);
	}
	this->refresh();
}
 
void GroveLEDBar::turnOnAllLED()
{
	for(unsigned char indexLED = 0; indexLED < 10; ++indexLED) {
		this->_turnOnLED(indexLED);
	}
	this->refresh();
}
 
void GroveLEDBar::turnOffAllLED()
{
	for(unsigned char indexLED = 0; indexLED < 10; ++indexLED) {
		this->_turnOffLED(indexLED);
	}
	this->refresh();
}

void GroveLEDBar::setLEDStates(unsigned int bits) {
	for(unsigned char indexLED = 0; indexLED < 10; ++indexLED) {
		unsigned int state = (bits >> indexLED) && 1;
		state ? this->_turnOnLED(indexLED) : this->_turnOffLED(indexLED);
	}
	this->refresh();
}

unsigned int GroveLEDBar::getLEDStates() {
	unsigned int bits = 0;
	for(unsigned char indexLED = 0; indexLED < 10; ++indexLED) {
		bits |= (this->_statesLED[indexLED] ? 1 : 0 << indexLED);
	}
}

void GroveLEDBar::setLevel(unsigned char level) {
	for(unsigned char indexLED = 0; indexLED < 10; ++indexLED) {
		indexLED < level ? this->_turnOnLED(indexLED) : this->_turnOffLED(indexLED);
	}
	this->refresh();
}
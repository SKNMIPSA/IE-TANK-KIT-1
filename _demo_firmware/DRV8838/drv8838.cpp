#include "drv8838.h"

//drv8838:drv8838(); //default constructor

drv8838::drv8838(uint8_t ENABLE, uint8_t PHASE){ //Constructor that sets pins for board - enable should be PWM
	mEN_pin = ENABLE;
	mPH_pin = PHASE;
	pinMode(mEN_pin, OUTPUT);
	pinMode(mPH_pin, OUTPUT);
}

void drv8838::configure(uint8_t ENABLE, uint8_t PHASE){ //Manually set pin values
	mEN_pin = ENABLE;
	mPH_pin = PHASE;
	pinMode(mEN_pin, OUTPUT);
	pinMode(mPH_pin, OUTPUT);
}

void drv8838::setDirection(bool direction){ //set motor direction
	if(_check_valid())
		digitalWrite(mPH_pin, direction);
}

void drv8838::setSpeed(uint8_t speed){ //set motor speed (0-255)
	if(_check_valid())
		analogWrite(mEN_pin, speed);
}

bool drv8838::_check_valid(){ //check that configuration is set before doing anything
	return (mEN_pin && mPH_pin);
}
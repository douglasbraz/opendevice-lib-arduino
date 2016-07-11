#include "Arduino.h"
#include "LogicalDevice.h"



LogicalDevice::LogicalDevice(int pin,AbstractExpander *controller){
	_pin = pin;
	_controller = controller;
}

LogicalDevice::LogicalDevice(int pin){
	_pin = pin;
}

bool LogicalDevice::setValue(unsigned long value, bool sync){
	_controller->digitalWrite(_pin,value);
	notifyListeners();

	if(sync){
		if(syncListerner) (*syncListerner)(id, currentValue);
	}
}




/*
  LogicalDevice.h - Library for expansão de portas.
  Created by Douglas B., Julho 2, 2016.
  Released into the public domain.
*/

#ifndef LogicalDevice_h
#define LogicalDevice_h

#include "Arduino.h"
#include "Device.h"
#include "Controller595.h"
#include "AbstractExpander.h"

class LogicalDevice : public Device {
  public:
    LogicalDevice(int pin,AbstractExpander *controler);
    LogicalDevice(int pin);
    bool setValue(unsigned long value, bool sync);
  private:
    int _pin;
    AbstractExpander *_controller;
};

#endif
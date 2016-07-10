/*
  Controller595.h - Library for expansão de portas.
  Created by Douglas B., Julho 2, 2016.
  Released into the public domain.
*/

#ifndef Controller595_h
#define Controller595_h

#include "Arduino.h"
#include "AbstractExpander.h"

class Controller595 : public AbstractExpander{
  public:
    Controller595(int lacth,int cloc,int data,int chips);
    void begin();
    void digitalWrite(int indice,byte value);
    static Controller595 *controller;
  private:
    int _pinClock;
    int _pinLacth;
    int _pinData;
    void syncData();
};

#endif
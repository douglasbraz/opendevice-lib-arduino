/*
  Expander595.h - Library for expansão de portas.
  Created by Douglas B., Julho 2, 2016.
  Released into the public domain.
*/

#ifndef Expander595_h
#define Expander595_h

#include "Arduino.h"
#include "AbstractExpander.h"

class Expander595 : public AbstractExpander{
  public:
    Expander595(int lacth,int cloc,int data,int chips);
    void begin();
    void digitalWrite(int indice,byte value);
  private:
    int _pinClock;
    int _pinLacth;
    int _pinData;
    void syncData();
};

#endif
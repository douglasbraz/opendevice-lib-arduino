/*
  Controller595.h - Library for expansão de portas.
  Created by Douglas B., Julho 2, 2016.
  Released into the public domain.
*/

#ifndef AbstractExpander_h
#define AbstractExpander_h

class AbstractExpander{
  public:
    virtual void begin();
    virtual void digitalWrite(int indice,byte value);
  protected:
    int _chips;
    byte *_portas;
    virtual void syncData();
};

#endif
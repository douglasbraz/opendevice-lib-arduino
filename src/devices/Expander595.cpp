#include "Arduino.h"
#include "Expander595.h"

Expander595::Expander595(int lacth,int cloc,int data,int chips){
	_pinClock = cloc;
	_pinLacth = lacth;
	_pinData = data;
	_chips = chips;
	_portas = new byte[_chips];
	pinMode(_pinClock, OUTPUT);
	pinMode(_pinLacth, OUTPUT);
	pinMode(_pinData, OUTPUT);
	for(int i=0;i<_chips;i++){
    	_portas[i] = 0b00000000;
  	}
  	syncData();
}

void Expander595::begin(){

}

void Expander595::digitalWrite(int indice,byte value){
	int chipSelect = (int)indice/9;
    int pinSelect = (indice-1)-(chipSelect*8);
    bitWrite(_portas[chipSelect],pinSelect,value);
 	syncData();   
}

void Expander595::syncData(){
	::digitalWrite(_pinLacth, LOW);
    
    for (int i=_chips-1; i>=0; i--)  {
      	shiftOut(_pinData,_pinClock, MSBFIRST, _portas[i]);
      	Serial.print(" -");
	    Serial.print(_portas[i],BIN);
	    
    }

    Serial.println("");

    ::digitalWrite(_pinLacth, HIGH);
}



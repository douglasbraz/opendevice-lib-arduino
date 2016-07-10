#include "Arduino.h"
#include "Controller595.h"

Controller595 *Controller595::controller=NULL;

Controller595::Controller595(){

}

Controller595::Controller595(int lacth,int cloc,int data,int chips){
	_pinClock = cloc;
	_pinLacth = lacth;
	_pinData = data;
	_chips = chips;
	_portas = new byte[_chips];
	Controller595::controller = (Controller595 *)this;
}

Controller595::Controller595(int lacth,int cloc,int data,int chips,Controller595 *c){
	Controller595(lacth,cloc,data,chips);
	Controller595::controller = c;
}

void Controller595::begin(){
	pinMode(_pinClock, OUTPUT);
	pinMode(_pinLacth, OUTPUT);
	pinMode(_pinData, OUTPUT);
	for(int i=0;i<_chips;i++){
    	_portas[i] = 0b00000000;
  	}
  	syncData();
}

void Controller595::digitalWrite(int indice,byte value){
	int chipSelect = (int)indice/9;
    int pinSelect = (indice-1)-(chipSelect*8);
    bitWrite(_portas[chipSelect],pinSelect,value);
 	syncData();   
}

void Controller595::syncData(){
	::digitalWrite(_pinLacth, LOW);
    
    for (int i=_chips-1; i>=0; i--)  {
      	shiftOut(_pinData,_pinClock, MSBFIRST, _portas[i]);
      	Serial.print(" -");
	    Serial.print(_portas[i],BIN);
	    
    }

    Serial.println("");

    ::digitalWrite(_pinLacth, HIGH);
}



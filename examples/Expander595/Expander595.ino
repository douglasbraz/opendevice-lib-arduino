/*
 * *****************************************************************************
 * See tutorial: https://opendevice.atlassian.net/wiki/display/DOC/A.+First+Steps+with+ODev
 * This example code is in the public domain.
 * *****************************************************************************
 */
#include <OpenDevice.h>
#include <devices/Expander595.h>

void setup(){
    ODev.enableDebug();
    ODev.setIoExpander(new Expander595(8,12,11,3));
    ODev.addLogical("led",1); // ID:1
    ODev.addLogical("led1",2); // ID:2
    ODev.addLogical("led2",22); // ID:3
    ODev.addLogical("led2",24); // ID:3
    ODev.begin(); // by default call Serial.begin() and while(!Serial) on Leonardo
}

void loop(){
  ODev.loop();
}


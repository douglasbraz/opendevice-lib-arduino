/*
 * *****************************************************************************
 * See tutorial: https://opendevice.atlassian.net/wiki/display/DOC/A.+First+Steps+with+ODev
 * This example code is in the public domain.
 * *****************************************************************************
 */
#include <OpenDevice.h>
#include <devices/Controller595.h>

Controller595 control(8,12,11,3);
LogicalDevice led(1);
LogicalDevice led1(9);
LogicalDevice led2(22);

void setup(){
    control.begin();
    ODev.enableDebug();
    ODev.addDevice(led); // ID:1
    ODev.addDevice(led1); // ID:2
    ODev.addDevice(led2); // ID:3
    ODev.begin(); // by default call Serial.begin() and while(!Serial) on Leonardo
}

void loop(){
	ODev.loop();
}


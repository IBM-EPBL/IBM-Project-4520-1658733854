#include <SPI.h>
#include <SD.h>
#include <Wire.h>
#include "GravitySensorHub.h"
#include "GravityRtc.h"
#include "OneWire.h"
#include "SdService.h"
#include "Debug.h"
#include <SoftwareSerial.h>

// clock module
GravityRtc rtc;

// sensor monitor
GravitySensorHub sensorHub;
SdService sdService = SdService(sensorHub.sensors);
void setup() {
	Serial.begin(9600);
	rtc.setup();
	sensorHub.setup();
	sdService.setup();

}


//********************************************************************************************
// function name: sensorHub.getValueBySensorNumber (0)
// Function Description: Get the sensor's values, and the different parameters represent the acquisition of different sensor data     
// Parameters: 0 ph value  
// Parameters: 1 temperature value    
// Parameters: 2 Dissolved Oxygen
// Parameters: 3 Conductivity
// Parameters: 4 Redox potential
// return value: returns a double type of data
//********************************************************************************************

unsigned long updateTime = 0;

void loop() {
	rtc.update();
	sensorHub.update();
	sdService.update();

	// ************************* Serial debugging ******************
	if(millis() - updateTime > 2000)
	{
		updateTime = millis();
		Serial.print(F("ph= "));
		Serial.print(sensorHub.getValueBySensorNumber(0));
		Serial.print(F("  Temp= "));
		Serial.print(sensorHub.getValueBySensorNumber(1));
		Serial.print(F("  Do= "));
		Serial.print(sensorHub.getValueBySensorNumber(2));
		Serial.print(F("  Ec= "));
		Serial.print(sensorHub.getValueBySensorNumber(3));
		Serial.print(F("  Orp= "));
		Serial.println(sensorHub.getValueBySensorNumber(4));
	}
}



//* ***************************** Print the relevant debugging information ************** ************ * /
// Note: Arduino M0 need to replace Serial with SerialUSB when printing debugging information

// ************************* Serial debugging ******************
//Serial.print("ph= ");
//Serial.print(sensorHub.getValueBySensorNumber(0));
//Serial.print("  Temp= ");
//Serial.print(sensorHub.getValueBySensorNumber(1));
//Serial.print("  Orp= ");
//Serial.println(sensorHub.getValueBySensorNumber(4));
//Serial.print("  EC= ");
//Serial.println(sensorHub.getValueBySensorNumber(3));


// ************************************************************ time ********************** **********
//Serial.print("   Year = ");//year
//Serial.print(rtc.year);
//Serial.print("   Month = ");//month
//Serial.print(rtc.month);
//Serial.print("   Day = ");//day
//Serial.print(rtc.day);
//Serial.print("   Week = ");//week
//Serial.print(rtc.week);
//Serial.print("   Hour = ");//hour
//Serial.print(rtc.hour);
//Serial.print("   Minute = ");//minute
//Serial.print(rtc.minute);
//Serial.print("   Second = ");//second
//Serial.println(rtc.second);

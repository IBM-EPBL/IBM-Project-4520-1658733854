#if  defined(__AVR_ATmega2560__)

const int CsPin = 53;

#else

const int CsPin = 4;

#endif

#define SDUPDATEDATATIME 30000

#include "SdService.h"
#include <SPI.h>
#include "Debug.h"
#include "GravityRtc.h"

extern GravityRtc rtc;
String dataString = "";


SdService :: SdService (ISensor * gravitySensor []): chipSelect (CsPin), sdDataUpdateTime ( 0 )
{
	this->gravitySensor = gravitySensor;
}


SdService :: ~ SdService ()
{
}

//********************************************************************************************
// function name: setup ()
// Function Description: Initialize the SD card
//********************************************************************************************
void SdService::setup()
{
	Debug::println(F("Initializing SD card..."));

	pinMode(SS, OUTPUT);

	if (!SD.begin(chipSelect))
	{
		Debug::println(F("Card failed, or not present"));
		// don't do anything more:
		return;
	}
	sdReady = true;
	Debug::println(F("card initialized."));

	// write the file header
	dataFile = SD.open("sensor.csv", FILE_WRITE);
	if (dataFile && dataFile.position() == 0) {
		//dataFile.println(F("Year,Month,Day,Hour,Minues,Second,pH,temp(C),DO(mg/l),ec(s/m),orp(mv)"));
		dataFile.println(F("date,pH,temp(C),DO(mg/l),ec(s/m),orp(mv)"));
		dataFile.close();
	}

}


//********************************************************************************************
// function name: update ()
// Function Description: Update the data in the SD card
//********************************************************************************************
void SdService::update()
{
	if (sdReady && millis() - sdDataUpdateTime > SDUPDATEDATATIME) 
	{
		//Serial.println(F("Write Sd card"));	
		dataString = "";
		// Year Month Day Hours Minute Seconds
		dataString += String(rtc.year,10);
		dataString += "/";
		dataString += String(rtc.month, 10);
		dataString += "/";
		dataString += String(rtc.day, 10);
		dataString += "/";
		dataString += String(rtc.hour, 10);
		dataString += "/";
		dataString += String(rtc.minute, 10);
		dataString += "/";
		dataString += String(rtc.second, 10);
		dataString += ",";

		// write SD card, write data twice, to prevent a single write data caused by the loss of too large
		dataFile = SD.open("sensor.csv", FILE_WRITE);
		if (dataFile)
		{
			dataFile.print(dataString);
			dataFile.close();
			Debug::print(dataString);

		}

		dataString = "";
		//ph
		if (this->gravitySensor[0] != NULL) {
			connectString(this->gravitySensor[0]->getValue());
		}
		else
			connectString(0);

		// temperature
		if (this->gravitySensor[1] != NULL) {
			connectString(this->gravitySensor[1]->getValue());
		}
		else
			connectString(0);

		//DO
		if (this->gravitySensor[2] != NULL) {
			connectString(this->gravitySensor[2]->getValue());
		}
		else
			connectString(0);

		//EC
		if (this->gravitySensor[3] != NULL) {
			connectString(this->gravitySensor[3]->getValue());
		}
		else
			connectString(0);

		//Orp
		if (this->gravitySensor[4] != NULL) {
			connectString(this->gravitySensor[4]->getValue());
		}
		else
			connectString(0);

		// write SD card
		dataFile = SD.open("sensor.csv", FILE_WRITE);
		if (dataFile)
		{
			dataFile.println(dataString);
			dataFile.close();
			Debug::println(dataString);

		}
		sdDataUpdateTime = millis();
	}
}

//********************************************************************************************
// function name: connectString ()
// Function Description: Connects the string data
//********************************************************************************************
void SdService::connectString(double value)
{
	dataString += String(value, 10);
	dataString += ",";
}

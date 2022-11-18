#pragma once

//#define DEBUG_AVR
//#define DEBUG_M0

class Debug
{
public:
	static void print(double info)
	{
		
#ifdef DEBUG_M0
				SerialUSB.print(info);
#endif // DEBUG_M0

#ifdef DEBUG_AVR
				Serial.print(info);
#endif // DEBUG_AVR

	}

	
	static void print(const PROGMEM char* info)
	{

#ifdef DEBUG_M0
			SerialUSB.print(info);
#endif // DEBUG_M0

#ifdef DEBUG_AVR
			Serial.print(info);
#endif // DEBUG_AVR

	}

	static void print(String info)
	{

#ifdef DEBUG_M0
		SerialUSB.print(info);
#endif // DEBUG_M0

#ifdef DEBUG_AVR
		Serial.print(info);
#endif // DEBUG_AVR
	}
	
	static void println(double info)
	{

#ifdef DEBUG_M0
		SerialUSB.println(info);
#endif // DEBUG_M0

#ifdef DEBUG_AVR
		Serial.println(info);
#endif // DEBUG_AVR

	}

	static void println(const PROGMEM char* info)
	{

#ifdef DEBUG_M0
		SerialUSB.println(info);
#endif // DEBUG_M0

#ifdef DEBUG_AVR
		Serial.println(info);
#endif // DEBUG_AVR

	}

	static void println(String info)
	{

#ifdef DEBUG_M0
		SerialUSB.println(info);
#endif // DEBUG_M0

#ifdef DEBUG_AVR
		Serial.println(info);
#endif // DEBUG_AVR
}

};

#pragma once
#include <Arduino.h>
#include "ISensor.h"
class GravityOrp:public ISensor
{
public:
	// orp sensor pin
	int orpSensorPin;

	// voltage value
	double voltage;

	// Calibrate the offset
	float offset;
private:
	// orp value
	double orpValue;


	static const int arrayLength = 5;
	int orpArray[arrayLength];
	double sum;

	double previousOrp;
	double currentOrp;
	double averageOrp;

public:
	GravityOrp();
	~GravityOrp();

	// initialize the sensor
	void  setup ();

	// update the sensor data
	void  update ();

	// Get the sensor data
	double getValue();
};

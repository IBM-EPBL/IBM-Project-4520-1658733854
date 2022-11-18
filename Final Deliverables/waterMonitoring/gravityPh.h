#pragma once
#include <Arduino.h>
#include "ISensor.h"
class GravityPh:public ISensor
{
public:
	// ph sensor pin
	int phSensorPin;

	// offset compensation
	float offset;

	// Take the sample interval
	int samplingInterval;
private:
	static const int arrayLength = 5;
	int pHArray [arrayLength];    // stores the average value of the sensor return data
	double pHValue, voltage;
	double averageVoltage;
	double sum;

public:
	GravityPh();
	~GravityPh() {};
	// initialization
	void  setup ();

	// update the sensor data
	void  update ();

	// Get the sensor data
	double getValue();
};

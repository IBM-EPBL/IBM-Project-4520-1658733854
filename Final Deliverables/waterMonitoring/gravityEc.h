#pragma once
#include "GravityTemperature.h"
#include "ISensor.h"

// external GravityTemperature ecTemperature;

class GravityEc:public ISensor
{
public:
	// Conductivity sensor pin
	int ecSensorPin;

	// Conductivity values
	double ECcurrent;


public:
	GravityEc(ISensor*);
	~GravityEc();

	// initialization
	void  setup ();

	// update the sensor data
	void  update ();

	// Get the sensor data
	double getValue();

private:
	// point to the temperature sensor pointer
	ISensor* ecTemperature = NULL;


	static const int numReadings = 5;
	unsigned int readings[numReadings] = { 0 };      // the readings from the analog input
	int index;
	double sum;
	unsigned long AnalogValueTotal;      // the running total
	unsigned int AnalogAverage;
	unsigned int averageVoltage;
	unsigned long AnalogSampleTime;
	unsigned long printTime;
	unsigned  long tempSampleTime;
	unsigned long AnalogSampleInterval;
	unsigned long printInterval ;

	// Calculate the average
  void calculateAnalogAverage();

	// Calculate the conductivity
	void calculateEc();
};

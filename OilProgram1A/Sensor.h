/*******************************************************************
*   CS 307 Programming Assignment 1
*   File: Sensor.h
*   Author: Travis Halleck
*   Desc: Class that makes sensors.  When instantiated by the Well
          the setters and getters run as well as random number is assigned
*   Date: D2/27/2019
*
*   I attest that this program is entirely my own work
*******************************************************************/

#pragma once
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <random>

using namespace std;

class Sensor {
private:
	string sensorType;
	string sensorClass;
	string sensorDisplayName;
	string sensorUnits;
	string sensorUnitsAbbr;
	double minValue;
	double maxValue;
	double reading;
	bool visible;

private:
	void genRandNum(double minV, double maxV);

public:
	Sensor(void);
	~Sensor(void);
	
	string getSensorType();
	string getSensorClass();
	string getSensorDisplayName();
	string getSensorUnits();
	string getSensorUnitsAbbr();
	double getMinValue();
	double getMaxValue();
	double getReading();
	bool getVisibility();

	void setSensorType(string);
	void setSensorClass(string);
	void setSensorDisplayName(string);
	void setSensorUnits(string);
	void setSensorUnitsAbbr(string);
	void setMinValue(double);
	void setMaxValue(double);
	void setReading(double);
	void setVisibility(bool);
};


/*******************************************************************
*   CS 307 Programming Assignment 1
*   File: Well.h
*   Author: Travis Halleck
*   Desc: setters and getters for wells and instanciates the sensors
          and stores them in a vector.
*   Date: 2/27/2019
*
*   I attest that this program is entirely my own work
*******************************************************************/

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Sensor.h"
#include "XMLOilParser.h"
#include <sstream>

using namespace std;

class Well {
private:
	string wellId;
	string wellOperator;
	vector<Sensor*> sensors;
	bool visible;

private:
	int indexof(string, string);
	void populateSensors();
	double strToDouble(string);

public:
	Well(void);
	~Well(void);
	void setWellID(string);
	void setWellOperator(string);
	string getWellID();
	string getWellOperator();
	vector<Sensor*> getSensors();
	void setSensors(vector<Sensor*>);
	void setVisibility(bool);
	bool getVisibility();
};


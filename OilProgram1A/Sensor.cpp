/*******************************************************************
*   CS 307 Programming Assignment 1
*   File: Sensor.cpp
*   Author: Travis Halleck
*   Desc: Class that makes sensors.  When instantiated by the Well
          the setters and getters run as well as random number is assigned
*   Date: D2/27/2019
*
*   I attest that this program is entirely my own work
*******************************************************************/

#include "Sensor.h"

Sensor::Sensor(void){
 	visible = true;
	reading = 0.00;
}
Sensor::~Sensor(void){}

/* random number is generated for the sensors to simulate a reading
if however the maxvalue is undefined in the parser, then the random
number acts as an accumlator which increases by 50 each time to simulate
depth the sensor.  Please note 50 is arbitrarily choosen since the requirements didn't
specify how much should be accumulated*/
void Sensor::genRandNum(double minV, double maxV){	
	if(maxV == 0){
		reading += (minV + (rand() % (int)(50 - minV)));
	}else{
		reading = minV + (rand() % (int)(maxV - minV));
	}
}

string Sensor::getSensorType(){
	return sensorType;
}
string Sensor::getSensorClass(){
	return sensorClass;
}
string Sensor::getSensorDisplayName(){
	return sensorDisplayName;
}
string Sensor::getSensorUnits(){
	return sensorUnits;
}
string Sensor::getSensorUnitsAbbr(){
	return sensorUnitsAbbr;
}
double Sensor::getMinValue(){
	return minValue;
}
double Sensor::getMaxValue(){
	return maxValue;
}
double Sensor::getReading(){
	genRandNum(minValue, maxValue);
	return reading;
}
bool Sensor::getVisibility(){
	return visible;
}

void Sensor::setSensorType(string sensorType){
	this->sensorType = sensorType;
}
void Sensor::setSensorClass(string sensorClass){
	this->sensorClass = sensorClass;
}

void Sensor::setSensorDisplayName(string sensorDisplayName){
	this->sensorDisplayName = sensorDisplayName;
}
void Sensor::setSensorUnits(string sensorUnits){
	this->sensorUnits = sensorUnits;
}
void Sensor::setSensorUnitsAbbr(string sensorUnitsAbbr){
	this->sensorUnitsAbbr = sensorUnitsAbbr;
}
void Sensor::setMinValue(double minValue){
	this->minValue = minValue;
}
void Sensor::setMaxValue(double maxValue){
	this->maxValue = maxValue;
}
void Sensor::setReading(double reading){
	this->reading = reading;
}
void Sensor::setVisibility(bool monitored){
	this->visible = monitored;
}

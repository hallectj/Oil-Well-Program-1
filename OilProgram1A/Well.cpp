/*******************************************************************
*   CS 307 Programming Assignment 1
*   File: Well.cpp
*   Author: Travis Halleck
*   Desc: setters and getters for wells and instanciates the sensors
          and stores them in a vector.
*   Date: 2/27/2019
*
*   I attest that this program is entirely my own work
*******************************************************************/

#include "Well.h"

Well::Well(void){
	visible = false;
}
Well::~Well(void){}

/* This function is used to read in string looking numbers and transform them
to doubles.  If the read in value is 'UNDEFINED' as could be the case with max
value, then the max value becomes 0, letting me know how to handle that.*/
double Well::strToDouble(string str){
    double d = 0.00;
	if(str == "UNDEFINED"){
		return d;
	}
    stringstream ss;
    ss << str;
    ss >> d;
    return d;
}

/* reads sensors from a file created by the xml oil parser.  This is used to create the snesors
   as it stands when a well is instanciated, the sensors are the first to be defined and get
   values.
*/

void Well::populateSensors(){
	string line;
	//char sensorType[64], sensorClass[64], displayName[64], sensorUnits[64], sensorAbbr[64];
	string sType, sClass, dName, sUnits, sAbbr;
	double miValue, mxValue;
    ifstream oilSensorFile("oilSensorInfo.txt");
    if(oilSensorFile.is_open()){
		//didn't need to have variables could of just getline of the line, but added variables
		//to add clarity to the code
		while(getline(oilSensorFile, line)){
			Sensor *sensor = new Sensor();
			sType = line;
            sensor->setSensorType(sType);
            getline(oilSensorFile, line);

			sClass = line;
			sensor->setSensorClass(sClass);
			getline(oilSensorFile, line);
				
			dName = line;
			sensor->setSensorDisplayName(dName);
			getline(oilSensorFile, line);

			miValue = strToDouble(line);
			sensor->setMinValue(miValue);
			getline(oilSensorFile, line);

			mxValue = strToDouble(line);
			sensor->setMaxValue(mxValue);
			getline(oilSensorFile, line);

			sUnits = line;
			sensor->setSensorUnits(sUnits);
			getline(oilSensorFile, line);

			sAbbr = line;
			sensor->setSensorUnitsAbbr(sAbbr);
			getline(oilSensorFile, line);

            sensors.push_back(sensor);

       }
       oilSensorFile.close();

    }else{
		cout << "no file found " << endl;
        exit(0);
    }
}


void Well::setWellID(string wellID){
	this->wellId = wellID;
}

void Well::setWellOperator(string wellOperator){
	this->wellOperator = wellOperator;
}

string Well::getWellID(){
	return wellId;
}

string Well::getWellOperator(){
	return wellOperator;
}

bool Well::getVisibility(){
	return visible;
}

void Well::setVisibility(bool monitored){
	this->visible = monitored;
}

void Well::setSensors(vector<Sensor*> sensors){
	this->sensors = sensors;
}

/*Populate sensors and then return sensors vector*/
vector<Sensor*> Well::getSensors(){
	populateSensors();
	return sensors;
}
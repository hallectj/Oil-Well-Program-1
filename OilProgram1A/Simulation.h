/**********************************************************************************************
*   CS 307 Programming Assignment 1 (Oil Well)
*   File: Simulation.cpp
*   Author: Travis Halleck
*   Desc: Simulation asks user for xml file from which to parse wells and sensors
          and then iniitializes all the wells, which they in turn
          initialize all the sensors.  The user then selects which wells to display
		  and monitor.  He or she can then select to add more wells or remove wells
		  and also remove independent sensors from the wells selected.
*   Date: 2/27/2019

*   I attest that this program is entirely my own work with the exception of the authorized
    hints section that the instructor provided which includes the timer and identifying keyboard
	keys used.  
************************************************************************************************/

#pragma once
#ifndef SIMULATION_
#define SIMULATION_
#include <iostream>
#include <vector>
#include "Well.h"
#include <iomanip>
#include <sys/types.h>     // needed for the _ftime() function
#include <sys/timeb.h>     // contains definition of _timeb struct
#include <time.h>          // needed for other time functions and structures
#include "XMLOilParser.h"
#include <typeinfo> 

#include <conio.h>
#include <stdio.h>
#include "FormatHelper.h"

class Simulation {
private:
	vector<Well*> wells;
	vector<Sensor*> sensors;

public:
	Simulation(void);
	~Simulation(void);
	void init();
};

#endif
/*******************************************************************
*   CS 307 Programming Assignment 1
*   File: FormatHelper.h
*   Author: Travis Halleck
*   Desc: All this file does is preetify the output of the wells and 
          sensors in the report to the screen, for that reason it is
		  a static class
*   Date: 2/27/2019
*
*   I attest that this program is entirely my own work
*******************************************************************/

#pragma once
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class FormatHelper {
private:
	FormatHelper(){}

public:
	static void formatSensorTextBlock(string, double, string);
	static void formatOilTextBlock(string, string);
};


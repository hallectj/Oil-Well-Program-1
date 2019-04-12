/*******************************************************************
*   CS 307 Programming Assignment 1
*   File: FormatHelper.cpp
*   Author: Travis Halleck
*   Desc: All this file does is preetify the output of the wells and 
          sensors in the report to the screen, for that reason it is
		  a static class
*   Date: D2/27/2019
*
*   I attest that this program is entirely my own work
*******************************************************************/


#include "FormatHelper.h"

//FormatHelper::FormatHelper(){}
void FormatHelper::formatSensorTextBlock(string sensorType, double sensorValue, string sensorUnits){
    const char spacer = ' ';
    const int wordSpaceWidth = 8;
    const int maxWidth = 40;

    cout << "\t";
    cout << left << setw(wordSpaceWidth) << setfill(spacer) << "Sensor Type: ";
    cout << left << setw(wordSpaceWidth) << setfill(spacer) << sensorType;
    cout << right << setw(maxWidth - sensorType.length()) << "Reading: ";
    cout << internal << sensorValue << " " << sensorUnits;
    cout << endl;
  }

 void FormatHelper::formatOilTextBlock(string wellID, string wellOperator){
    const char spacer = ' ';
    const int wordSpaceWidth = 8;
    
    cout << "   ";
    cout << left << setw(wordSpaceWidth) << setfill(spacer) << "Well ID: ";
    cout << left << setw(wordSpaceWidth) << setfill(spacer) << wellID;
    cout << endl;
    cout << "     ";
    cout << left << setw(wordSpaceWidth) << setfill(spacer) << "Operator: ";
    cout << left << setw(wordSpaceWidth) << setfill(spacer) << wellOperator;
    cout << endl;
  }

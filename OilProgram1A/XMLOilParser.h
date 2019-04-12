//====================================================================
// OilFieldDataParser.cpp
// Implementation file for the data parser.
// Author: Dr. Rick Coleman
// Date: December 2009
//
//====================================================================
// Travis Halleck
// 2/27/2019 (modified date)

//Obviously the majority of the code below is the insturctor (Dr Coleman)
//I modifed bits of it to use string when neccessary instead of cstrings
//and I added a createWellFileFunc and createSensorFileFunc which makes 
//(when called) text files of the wells and sensors.  This is used in my
//sensor class.  So to the extent of the statement 
// " I attest that this program is entirely my own work" applies to those
// custom methods I have made, the rest of course is Dr. Coleman's code
// that we are authorized to use.
//====================================================================

#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <string.h>
#include <stdio.h>      /* printf, fopen */
#include <stdlib.h>


using namespace std;

class XMLOilParser {
    private:
        ifstream	*inFile;				// Oilfield data definition file
		int			m_iNumWells;			// Number of wells in the data file
		int			m_iNumSensors;			// Number of sensors on each well
		int			m_iNextWellNumber;		// Index of the next well to read
		char		**m_cpWellID;			// Pointer to array of pointers to
											//  char arrays holding well IDs
		int			*m_ipNextSensorNumber;	// Pointer to array of ints counting
											//  sensors for each well
		string      m_sFileName;			// Data file

    private:
		bool getNextLine(char *buffer, int n);

	public:
		XMLOilParser();
        XMLOilParser(string fileName);
        ~XMLOilParser();
		void setFileName(string);
		int getWellCount();
		int getSensorCount();
		bool getWellData(char *id, char *opr, int *numSensors);
		bool getSensorData(char *wellID, char *type, char *className,
			char *displayName, double *min, double *max, char *units, char *unitAbbrev);
        void createWellInfoFile();
        void createSensorInfoFile();
		string getFileName();
		void printWellData(); // For testing only

};


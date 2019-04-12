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



#define _CRT_SECURE_NO_WARNINGS
#include "Simulation.h"

using namespace std;

Simulation::Simulation(void){}
Simulation::~Simulation(void){}

/*Menu displayed all the time to remind user of their options*/
void genericMenuFunc(){
	cout << endl;
	cout << "=====================================" << endl;
	cout << "| Press 'w' to add or remove wells   |" << endl;
	cout << "| Press 's' to add or remove sensors |" << endl;
	cout << "| Press 'q' to quit simulation       |" << endl;
	cout << "=====================================" << endl;
	cout << endl;
}

/*When asking user for either wells or sensors to remove or add
  The input is a char that looks like a number.  This functions
  converts that numeric looking char to an int that way I can
  iterate with a for loop */
char intToChar(int x){
    string str;
    stringstream ss;
    ss << x;
    str = ss.str();
    return *const_cast<char*>(str.c_str());
}

/* Does opposite of intToChar, transforms char to int*/
int charToInt(char letter){
	int i_letter;
	i_letter = letter - '0';
	return i_letter;
}

/* Reads user input selection 1 to however many wells and displays them to screen
If remove then visibility set to true if adding a well the visibility set to false
Function takes references to well vector and char letter input to increase speed*/
void numberedWellsToDisplay(vector<Well*> &w, char &letter, bool visibility){
	for(int i = 0; i<w.size(); i++){
		if(letter == intToChar(i+1)){
			w[i]->setVisibility(visibility);
			break;
		}
	}
}

/*Same as the numberedWellsToDisplay except dealing with sensors*/
void numberedSensorsToDisplay(vector<Sensor*> &s, char &letter, bool visibility){
	for(int i = 0; i<s.size(); i++){
		if(letter == intToChar(i+1)){
			s[i]->setVisibility(visibility);
			break;
		}
	}
}


/*Displays wells to user to the screen.  If visible, then display well otherwise do not
This function returns a bool that way if nothing is there I can handle that case with 
and display custom cout statements*/
bool vectorDisplayMenuWell(vector<Well*> &w, bool visiblity){
	bool somethingThere = false;
	for(int i = 0; i<w.size(); i++){
		if(w[i]->getVisibility() == visiblity){
			somethingThere = true;
			cout << i+1 << "\t" << w[i]->getWellID() << endl;
		}
	}

	return somethingThere;
}


/*Same as above, except this function is overloaded with the character letter
this way I can get the numbers of the displayed and matched them if on screen and if so
disallow the ones not aviliable so those wells are not affected

Example, if wells 1 and 3 are displayed, I don't want the user to affect wells
2,4,5 and 6*/
bool vectorDisplayMenuWell(vector<Well*> &w, bool visiblity, char &chLetter){
	vector<int> displayedNumbers;
	bool somethingThere = false;
	for(int i = 0; i<w.size(); i++){
		if(w[i]->getVisibility() == visiblity){
			somethingThere = true;
			displayedNumbers.push_back(i+1);
			cout << i+1 << "\t" << w[i]->getWellID() << endl;
		}
	}

	return somethingThere;
}

/*If sensor is visible display it to screen othersise do not*/
bool vectorDisplayMenuSensor(vector<Sensor*> &s, bool visiblity){
	bool somethingThere = false;
	for(int i = 0; i<s.size(); i++){
		if(s[i]->getVisibility() == visiblity){
			somethingThere = true;
			cout << i+1 << "\t" << s[i]->getSensorType() << endl;
		}
	}
	return somethingThere;
}

/*Get index of a well vector in case I need to use an iterator to 
advance the pointer to a well to remove a well.  May consider
deleting this function as it is not used currently*/
int indexOfVector(vector<Well*> wellVec, string id){
    int index = -1;
    for(int i = 0; i<wellVec.size(); i++){
        if(wellVec[i]->getWellID() == id){
            index = i;
            break;
        }
    }
    return index;
}

/*This function acts more like a module to condense the code down.*/
void userAddWells(vector<Well*> &w, char &chLetter, bool &someToDisp){
	cout << "Availiable Wells:" << endl;
	someToDisp = vectorDisplayMenuWell(w, false);
	if(!someToDisp){
		cout << "Nothing to display press enter to continue" << endl;
	}else{
		cout << "\nplease enter a number above and then press enter " << endl;
	}
	chLetter = _getch();
	cout << chLetter << endl;
	//chLetter = _getch();
	numberedWellsToDisplay(w, chLetter, true);
	cout << chLetter << endl;
}

void userRemoveWells(vector<Well*> &w, char &chLetter, bool &someToDisp){
	cout << "Monitored Wells: " << endl;
	someToDisp = vectorDisplayMenuWell(w, true);
	if(!someToDisp){
		cout << "Nothing to display press enter to continue" << endl;
	}else{
		cout << "\nplease enter a number above and then press enter " << endl;
	}
	chLetter = _getch();
	cout << chLetter << endl;
	//chLetter = _getch();
	numberedWellsToDisplay(w, chLetter, false);
	cout << chLetter << endl;
}

/*When a user selects a sensor to remove, the user is given a list of 
 wells so he or she can add or remove sensors.  If user selects a number
 from the list that isn't displayed the sensor gets removed from the wrong well.
 This function prevents that from happening by ensuring that only the wells displayed
 can be affected which is the desired result, so the correct choice is any well displayd
 to the screen from which a sensor is being removed or added
*/
bool isOnlyDisplayedWellsShowing(vector<Well*> &w, char &chLetter){
	bool correctChoice = false;
	for(int i = 0; i<w.size(); i++){
		if(w[i]->getVisibility() == true){
			if(chLetter == intToChar(i+1)){
				correctChoice = true;
				break;
			}
		}
	}
	return correctChoice;
}




/*acts as a module to condense the code down, takes in references because I don't want to 
recreate wells or sensors, speed is important to the customer because of the 5 second interval*/
void userAddSensors(vector<Well*> &w, int wellIndex, char &chLetter, bool &someToDisp){
	cout << "Aviliable Sensors" << endl;
	vector<Sensor*> sensors1 = w[wellIndex]->getSensors();
	someToDisp = vectorDisplayMenuSensor(sensors1, false);
	if(!someToDisp){
		cout << "Nothing to display press enter to continue" << endl;
	}else{
		cout << "\nplease enter a number above and then press enter " << endl;
	}
	chLetter = _getch();
	cout << chLetter << endl;
	//chLetter = _getch();
	numberedSensorsToDisplay(sensors1, chLetter, true);
	sensors1.clear();
}

/*Remove sensors*/
void userRemoveSensors(vector<Well*> &w, int wellIndex, char &chLetter, bool &someToDisp, int &sCount){
	cout << "Monitored Sensors:" << endl;
	vector<Sensor*> sensors1 = w[wellIndex]->getSensors();
	for(int j = 0; j<sensors1.size(); j++){
		sensors1.resize(sCount);
		if(sensors1[j]->getVisibility() == true){
			cout << "\t" << j+1 << " " << sensors1[j]->getSensorType() << endl;
		}
	}
	cout << "Enter a number from above and press enter" << endl;
	chLetter = _getch();
	cout << chLetter << endl;
	numberedSensorsToDisplay(sensors1, chLetter, false);
	sensors1.clear();
}

/*initialize and run the program.  Asks user for filename for oil parser, then if given correct file
creates well objects and stores in vector*/
void Simulation::init(){
	string fileName;
	cout << "Enter a file to begin simulation " << endl;
	cin >> fileName;

	XMLOilParser oilParser(fileName);
	oilParser.createSensorInfoFile();
		
	//vector<Well*> wells;
	//vector<Sensor*> sensors;
	char wellId[256], wellOperator[256];
	int sensorCount;
	bool moreWells = true;

	while(moreWells){
		moreWells = oilParser.getWellData(wellId, wellOperator, &sensorCount);
		Well *well = new Well();
		well->setWellID(wellId);
		well->setWellOperator(wellOperator);
		wells.push_back(well);
	}

	//The parser is set up to where if no more <Well> is found then set to false
	//the while loop runs that last time and ends up pushing a copy of the last
	//well, so I pop the last well to have only one of them instead of two.
	wells.pop_back();

	/* This code was obtained in the hints section provided on Dr. Coleman's website
	http://www.cs.uah.edu/~rcoleman/CS307/ProgAssign/Prog1Hints.html
	this code being the time struct, setting the timer and the keyboard detection code*/
	struct _timeb   tStruct;
    double          thisTime;
    double          outputTime;
    bool            done = false;  // while loop flag

	_ftime(&tStruct);

	thisTime = tStruct.time + (((double)(tStruct.millitm)) / 1000.0); // Convert to double
	outputTime = thisTime + 5.0; // Set next 5 second interval time
	
	int  hit;
	char ch;
	bool somethingToDisplay = false;  // used alot, this flag will let me know if any well or sensor is displayed to screen


	while(!done){ //keep going unti user quits (q)
		hit = _kbhit(); //See if a key has been pressed
		if (hit) {
			ch = _getch();	// Get the key pressed
			if(ch == 'q'){
				break;
			}else if(ch == 'w'){ // well selection
				cout << "Do you want to add or remove a well from the monitored list?" << endl;
				cout << "Enter 'a' (add) or 'r' (remove) and press enter" << endl;
				ch = _getch();
				if(ch == 'a'){ //if adding a well
					userAddWells(wells, ch, somethingToDisplay);
				}else if(ch == 'r'){ // if removing a well
					userRemoveWells(wells, ch, somethingToDisplay);
				}else if(ch != 'a' || ch != 'r'){ //if neither add or remove display invalid
					cout << "invalid selection " << endl;
				}
			}else if(ch == 's'){ //sensor selection
				cout << "Select a well from the list below:" << endl;
				somethingToDisplay = vectorDisplayMenuWell(wells, true, ch);
				if(!somethingToDisplay){
					cout << "Nothing to display press enter to continue" << endl;
				}else{
					cout << "\nplease enter a number above " << endl;
				}

				ch = _getch();
				 
				//this ensures only the wells displayed on the screen can be affected
				bool correctChoice = isOnlyDisplayedWellsShowing(wells, ch);

				if(correctChoice){
					for(int x = 0; x<oilParser.getSensorCount(); x++){
						if(ch == intToChar(x+1)){
							cout << "Do you want to add or remove sensor a sensor from the monitored list?" << endl;
							cout << "Enter 'a' (add) or 'r' (remove) and press enter" << endl << endl;
							ch = _getch();
							if(ch == 'a'){
								userAddSensors(wells, x, ch, somethingToDisplay);
							}else if(ch == 'r'){
								userRemoveSensors(wells, x, ch, somethingToDisplay, sensorCount);
							}
							break;
						}				
					}
				}
			}
		}

		//seed the timer
		/*timer code obtained from Dr. Coleman's website hint section
		http://www.cs.uah.edu/~rcoleman/CS307/ProgAssign/Prog1Hints.html
		*/
		_ftime(&tStruct);
		thisTime = tStruct.time + (((double)(tStruct.millitm)) / 1000.0); // Convert to double
        // Check for 5 second interval to print status to screen
        if(thisTime >= outputTime) {
			genericMenuFunc();
			cout << "State of monitered wells..." << endl << endl;
			//printing to screen
			for(int i = 0; i<wells.size(); i++){
			    int j = 0;
				if(wells[i]->getVisibility() == true){
					FormatHelper::formatOilTextBlock(wells[i]->getWellID(), wells[i]->getWellOperator());
					vector<Sensor*> theSensors = wells[i]->getSensors();	
					theSensors.resize(sensorCount); //need to resize otherwise sensors compound, need this and clearing vector
					for(j = 0; j<theSensors.size(); j++){
						if(theSensors[j]->getVisibility() == true){
							FormatHelper::formatSensorTextBlock(theSensors[j]->getSensorType(), theSensors[j]->getReading(), theSensors[j]->getSensorUnitsAbbr());			
						}
					}

					//sensors are cleared from the vector since they are always auto generated, otherwise the
					//sensors will compound
					theSensors.clear();
					cout << endl << endl;
				}
			}

			
            outputTime += 5.0; // Set time for next 5 second interval
        }

	}
}

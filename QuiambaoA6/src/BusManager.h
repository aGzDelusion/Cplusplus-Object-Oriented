/*
 * BusManager.h
 *
 *  Created on: Oct 30, 2019
 *      Author: capta
 */

#ifndef BUSMANAGER_H_
#define BUSMANAGER_H_
#define PTR_ARRSIZE 50	//for PTR Arraysize
#include "Bus.h"

class BusManager
{
private:
	Bus *ptrArray[PTR_ARRSIZE]{nullptr}; //initialize and declare array of pointers pointing to Bus object
	void displayCH();
	string catcher; //string object for handling file and also input from user.
	ifstream busData;	//for reading the file
public:
	//Constructor
	BusManager();

	// Processor
	void process();

	//Cleanup
	void cleanup();


};



#endif /* BUSMANAGER_H_ */

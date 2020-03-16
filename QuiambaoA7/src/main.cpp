//============================================================================
// Name        : QuiambaoA7.cpp
// Author      : Darwish Quiambao
// Version     :
// Copyright   : 
// Description : Assignment 7 with Inheritance (Vehicle reader that subcategorizes each vehicle depending on their type of: Bus, Railcar, or Helicopter)
//============================================================================

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

#include "Vehicles.h"

const short int PTR_ARRSIZE = 50, //for pointer array size
				ARRAY_IDSIZE = 150; //for ID Array later to store IDs searched
int main() {
	string reader; //for reading file
	Vehicle *ptrArray[PTR_ARRSIZE]{nullptr}; //Pointer Array to store objects of Base Class Vehicles
	ifstream vehicles;	//input filestream object for reading the file

	vehicles.open("C:\\COMSC200\\a7data.txt");
		if(!vehicles.is_open())
		{
			cout << "File not found..." << endl << "Terminating program..." << endl;
			return 1;
		}
		// PART 1 Reading File and Displaying:
			short int counter = 0; //counter for while loop
			while(!getline(vehicles, reader, '\n').eof())
			{
				//ptrArray[counter] = new Vehicle(reader.substr(0, 4), reader.substr(4, 15), reader.substr(19, 8), reader.substr(27, 8), stoi(reader.substr(35, 3)), reader.at(38));
					if(reader.at(0) == 'B')
					{
						ptrArray[counter] = new Bus(reader.substr(0, 4), reader.substr(4, 15), reader.substr(19, 8), reader.substr(27, 8), stoi(reader.substr(35, 3)), reader.at(38), stoi(reader.substr(39, 7)), reader.substr(46, 9), reader.at(55));
						counter++;
					}
					if(reader.at(0) == 'R')
					{
						ptrArray[counter] = new Railcar(reader.substr(0, 4), reader.substr(4, 15), reader.substr(19, 8), reader.substr(27, 8), stoi(reader.substr(35, 3)), reader.at(38), stoi(reader.substr(39, 3)), reader.substr(42, 5));
						counter++;
					}
					if(reader.at(0) == 'H')
					{
						ptrArray[counter] = new Helicopter(reader.substr(0, 4), reader.substr(4, 15), reader.substr(19, 8), reader.substr(27, 8), stoi(reader.substr(35, 3)), reader.at(38), stoi(reader.substr(39, 5)), stoi(reader.substr(44, 4)));
						counter++;
					}
			}


	for (int i = 0; ptrArray[i] != nullptr; i++)
	{
		if(ptrArray[i]->getID().at(0) == 'B'){
		cout << ptrArray[i]->getID() << " " << ptrArray[i]->getMfg() << " " << ptrArray[i]->getservDate()
			 << " " << ptrArray[i]->getinspDate() << ptrArray[i]->getCapacity() << ptrArray[i]->getStatus()
			 << " " << dynamic_cast<Bus*>(ptrArray[i])->getMileage() << " " << dynamic_cast<Bus*>(ptrArray[i])->getTireSize()
			 << " " << dynamic_cast<Bus*>(ptrArray[i])->getFuelType() << endl; //ADD Bus Class members
		}

		if(ptrArray[i]->getID().at(0) == 'R'){
				cout << ptrArray[i]->getID() << " " << ptrArray[i]->getMfg() << " " << ptrArray[i]->getservDate()
					 << " " << ptrArray[i]->getinspDate() << ptrArray[i]->getCapacity() << ptrArray[i]->getStatus()
					 << " " << dynamic_cast<Railcar*>(ptrArray[i])->getPwr() << " " << dynamic_cast<Railcar*>(ptrArray[i])->getMotor() //preferred over static_cast; used when derived is unsure
					 << endl;
		}

		if(ptrArray[i]->getID().at(0) == 'H'){
				cout << ptrArray[i]->getID() << " " << ptrArray[i]->getMfg() << " " << ptrArray[i]->getservDate()
					 << " " << ptrArray[i]->getinspDate() << ptrArray[i]->getCapacity() << ptrArray[i]->getStatus()
					 << " " << dynamic_cast<Helicopter*>(ptrArray[i])->getAirframeHrs() << " " << dynamic_cast<Helicopter*>(ptrArray[i])->getPowerplantHrs()
					 << endl;
		}
	}
	reader.clear();
	//Part 2:

	cout << "Enter a Vehicle ID: ";
	getline(cin, reader);
	string ID[ARRAY_IDSIZE]; //for ID storing
	counter = 0; //to increment array index for ID
	while(reader != "0"){
		bool found = false;

		for(int i = 0; ptrArray[i] != nullptr; i++)
		{
			if(reader == ptrArray[i]->getID())
			{
					found = true;
					cout << "\nVehicle ID found!" << endl;
					ID[counter] = reader;//ptrArray[i]->getID(); //stores ID entered into string Array
					ptrArray[i]->display();
					ptrArray[i]->maintenanceCheck();
			}
		}
		
		if(!found)
			cout << "Vehicle ID not found...\nPlease enter a valid Vehicle ID!" << endl;

		counter++;
		// Re-enter Vehicle ID
		cout << "\nEnter a Vehicle ID: ";
		getline(cin, reader);
	}

	cout << "\nDisplaying vehicles one last time: " << endl;
	//Display vehicles altogether with updated statuses..
	for(int i = 0; ptrArray[i] != nullptr; i++)
	{
		ptrArray[i]->display();
		cout << endl;
	}

	//(1) Display vehicles entered:
	cout << "====Vehicle IDs entered====" << endl;
	for(int i = 0; ptrArray[i] != nullptr; i++)
	{
		for(int j = 0; !ID[j].empty(); j++)//for-loop for searching ID array with evaluation set to if ID at index is empty or not
		{
			if(ptrArray[i]->getID() == ID[j])
			{
				ptrArray[i]->display();
				cout << endl;
			}
		}
	}
	//(2) Display vehicles due for maintenance
	cout << "\nDisplaying vehicles due for maintenance..." << endl
		 <<"============= Vehicles Due for Maintenance =============" << endl;
	for(int i = 0; ptrArray[i] != nullptr; i++)
	{
		if(ptrArray[i]->getStatus() == 'M')
		{
			ptrArray[i]->display();
			cout << endl;
		}
	}

	cout << "Thank you for using the program!" << endl;

	//For deleting dynamically allocated objects!
	cout << endl << endl;
	for(int i = 0; ptrArray[i] != nullptr; i++){
		delete ptrArray[i];
		cout << "Deleted object pointer " << i+1 << endl;
	}

	return 0;
}

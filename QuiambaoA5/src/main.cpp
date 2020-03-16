#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
#include "functions.h"
#include "Bus.h"
///Banana
const short int PTR_ARRSIZE = 50;
int main()
{
	string catcher; //string object for handling file and also input from user.
	static Bus busArray[PTR_ARRSIZE]; //initialize and declare array of pointers pointing to Bus object
	ifstream busData; //for reading the file

	//PHASE 1: Reading and Displaying Data
	busData.open("C:\\COMSC200\\a4data.txt");
		if(!busData.is_open())
		{
			cout << "File not found..." << endl
				 << "Exiting Program..." << endl;
			return 1;
		}

				short int i = 0; // for counter in reading file - while loop
				while(!getline(busData, catcher, '\n').eof())
				{
					busArray[i].setBusID(catcher.substr(0, 5));
					busArray[i].setManufacturer(catcher.substr(5, 10));
					busArray[i].setCapacity(stoi(catcher.substr(15, 3)));
					busArray[i].setMileage(stoi(catcher.substr(18, 7)));
					busArray[i].setStatus(catcher.at(25));
					busArray[i].updateBus();	//updates buscount, average miles, and total miles.
					i++;
				}
				busData.close();	//Closes file

			displayCH(); // display Column Header
				for(int j = 0; busArray[j].getStatus() != '0'; j++)
				  {
				     cout << left << busArray[j].getID() << "\t"
				          << busArray[j].getMfg() << "\t\t" << busArray[j].getCapacity() << "\t"
				          << busArray[j].getMileage() << "\t" << busArray[j].getStatus() << "\t"<< endl;
				  }
			cout <<"---end of list---" << endl;

			catcher.clear();

			// PHASE 2: Transaction Processing Phase
			char status, in;	//Status = for updating status of bus, and in = for user input
			string temp;	//temp variable for holding BUS ID string.
			cout << "Enter transaction code \nm = add maintenance record, "
					"\nl = display maintenance history, \nc = compare buses, "
					"\na = display bus count and average number of miles \nx = exit: \n";

			getline(cin, catcher);	//user input
			stringstream(catcher) >> in >> temp >> status;	//to move input into appropriate fields.
			in = tolower(in); //converts to upper case for evaluation later.

			string maintDate, maintType, maintMech; //vars for maintHist Class.
		while(in != 'x')
		{

			if(in == 'm')
			{
				cout << "Enter Bus ID: ";
				getline(cin, temp);
				for(int i = 0; busArray[i].getStatus() != '0'; i++)
						{
							if(busArray[i].getID() == temp)
							{
								cout << "Enter maintenance date: " << endl;
								getline(cin, maintDate);

								cout << "Enter maintenance type: " << endl;
								getline(cin, maintType);

								cout << "Enter mechanic name: " << endl;
								getline(cin, maintMech);

									busArray[i].maintH[busArray[i].activeElem].maintDate = maintDate;
									busArray[i].maintH[busArray[i].activeElem].maintType = maintType;
									busArray[i].maintH[busArray[i].activeElem].maintMechanic = maintMech;
									cout << busArray[i].maintH[busArray[i].activeElem].maintDate << " " <<
											busArray[i].maintH[busArray[i].activeElem].maintType << " " <<
											busArray[i].maintH[busArray[i].activeElem].maintMechanic << endl;
									cout << "Maintenance element added to bus " << busArray[i].getID() << endl;
									busArray[i].activeElem++;
							}
						}
			}


			if(in == 'l')
			{
				cout << "Enter Bus ID: ";
				getline(cin, temp);
				for(int i = 0; busArray[i].getStatus() != '0'; i++)
				{
					if (busArray[i].getID() == temp)
					{
						for(int j = 0; busArray[i].maintH[j].maintDate.empty() != true; j++)
						{
							cout << "Maintenance History of Bus " << busArray[i].getID() << ": " << endl;
							cout << "History #" << j+1 << ": " << busArray[i].maintH[j].maintDate
								 << " " << busArray[i].maintH[j].maintType << " " << busArray[i].maintH[j].maintMechanic << endl;
						}
					}
				}
			}

			if(in == 'c')
			{
				string temp2;
				cout << "Enter first Bus ID: ";
				getline(cin, temp);

				cout << "Enter second Bus ID: ";
				getline(cin, temp2);

				for(int i = 0; busArray[i].getStatus() != '0'; i++)
					{
						if(busArray[i].getID() == temp)
						{
							for(int j = 0; busArray[j].getStatus() != '0'; j++)
							{
								if(busArray[j].getID() == temp2)
								{
									if(busArray[j] < busArray[i])
										cout << "Bus " << busArray[i].getID() << " has more elements than Bus " << busArray[j].getID() << endl;
									else
										cout << "Bus " << busArray[i].getID() << " has equal or more elements than Bus " << busArray[j].getID() << endl;
								}
							}
						}
					}
			}


			//Trying to display the static variables here:
			if(in == 'a')
			{
				for(int i = 0; busArray[i].getStatus() != '0'; i++)
				{
					cout << " Bus Count: " << busArray[i].getBusCount() << endl;
					cout << " Average Miles: " << busArray[i].getAverageMiles() << endl << endl;
				}
			}

			cout << "\nEnter transaction code: \nm = add maintenance record "
					"\nl = display maintenance history \nc = compare buses "
					"\na = display bus count and average number of miles \nx = exit: \n";
			getline(cin, catcher);
			stringstream(catcher) >> in >> temp >> status;
			in = tolower(in);
		}
		cout << "Thank you for using the program!" << endl;
	return 0;
}

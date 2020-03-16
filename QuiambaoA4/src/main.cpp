#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
#include "functions.h"
#include "Bus.h"

const short int PTR_ARRSIZE = 50;
int main()
{
	string catcher; //string object for handling file and also input from user.
	Bus *ptrArray[PTR_ARRSIZE]{nullptr}; //initialize and declare array of pointers pointing to Bus object
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

					ptrArray[i] = new Bus(catcher.substr(0, 5), catcher.substr(5, 10), stoi(catcher.substr(15, 3)), stoi(catcher.substr(18, 7)), catcher.at(25));
					i++;
				}


			displayCH(); // display Column Header
				for(int j = 0; ptrArray[j] != nullptr; j++ )
				  {
				     cout << left << ptrArray[j]->getID() << "\t"
				          << ptrArray[j]->getMfg() << "\t\t" << ptrArray[j]->getCapacity() << "\t"
				          << ptrArray[j]->getMileage() << "\t" << ptrArray[j]->getStatus() << "\t"<< endl;
				  }
			cout <<"---end of list---" << endl;

			catcher.clear();

			// PHASE 2: Transaction Processing Phase
			char status, in;	//Status = for updating status of bus, and in = for user input
			string temp;	//temp variable for holding BUS ID string.
			cout << "Enter transaction code (D = display, L = list a bus, C = change status, X = exit): ";
			getline(cin, catcher);	//user input
			stringstream(catcher) >> in >> temp >> status;	//to move input into appropriate fields.
			in = toupper(in); //converts to upper case for evaluation later.

		while(in != 'X')
		{
			if(in == 'D')
			{
				displayCH();
				for(int j = 0; ptrArray[j] != nullptr; j++ )
					{
						cout << left << ptrArray[j]->getID() << "\t"
							 << ptrArray[j]->getMfg() << "\t\t" << ptrArray[j]->getCapacity() << "\t"
							 << ptrArray[j]->getMileage() << "\t" << ptrArray[j]->getStatus() << "\t"<< endl;
					}
				cout <<"---end of list---" << endl;
			}


			if(in == 'L')
			{
				bool found = false;
				for(int i = 0; ptrArray[i] != nullptr; i++)
				{
					if (ptrArray[i]->getID() == temp)
					{
						displayCH();
						cout << left << ptrArray[i]->getID() << "\t"
							 << ptrArray[i]->getMfg() << "\t\t" << ptrArray[i]->getCapacity() << "\t"
							 << ptrArray[i]->getMileage() << "\t" << ptrArray[i]->getStatus() << "\t"<< endl;
						found = true;
					}
				}
				if(!found)
				{
					cout << "Not found!" << endl;
				}
			}

			if(in == 'C')
			{
				bool found = false;
				for(int i = 0; ptrArray[i] != nullptr; i++)
					{
						if(ptrArray[i]->getID() == temp)
						{
							ptrArray[i]->setStatus(status);
							cout << "Success!" << endl;
							found = true;
						}
					}
				if (!found)
					cout << "Not Found!" << endl;
			}

			cout << "Enter transaction code (D = display, L = list a bus, C = change status, X = exit): ";
			getline(cin, catcher);
			stringstream(catcher) >> in >> temp >> status;
			in = toupper(in);
		}
		cout << "Thank you for using the program!" << endl;
	return 0;
}

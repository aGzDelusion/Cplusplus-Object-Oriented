//============================================================================
// Name        : A2.cpp
// Author      : Darwish Quiambao
// Version     :
// Copyright   : 
// Description : Assignment 2
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstring>

using namespace std;
#include "Student.h"
#include "age.h"
///Goes into header file

short int ARRAY_SIZE = 100;

int main() {
	ifstream inputFile; //Declare file input object

	Student * ptrToStudent = nullptr;
	//char arrayForRead[]; //Declare & initialize a c-string array of size 52
	Student* stdntPtrArray[100]{ nullptr }; // declare & initialize array of pointers.
	string writeString;
	char arrayForRead[53]{ '\0' };

	//Open text file at pathname *CHANGE*
	inputFile.open("C:\\COMSC200\\a2data.txt"); //Open File in Drive E (my local drive)
	if (!inputFile.is_open())
	{
		cout << "File not found!" << endl;
		cout << "Exiting program..." << endl;
		return 1;
	}

	// Start Processing input from File a2data.txt
		int i = 0; // declare and initialize counter variable for use in the while loop and indexing.
		inputFile.read(arrayForRead, 52); //Read from file and store into array ofCharacters
		writeString = arrayForRead; //Copy array of chars into a string object.

		while (!inputFile.eof())
		{
			arrayForRead[52] = '\0';

			//for (int i = 0; i < 53; i++)


				stdntPtrArray[i] = new Student; //dynamically allocate a Student Object and store it into the array of pointers

				// Process the record and store them into the Student Member variables
				stdntPtrArray[i]->fName = writeString.substr(0, 10);
				stdntPtrArray[i]->mInitial = arrayForRead[10];
				stdntPtrArray[i]->lName = writeString.substr(20, 20);
				stdntPtrArray[i]->collegeCode = arrayForRead[40];
				stdntPtrArray[i]->locationCode = stoi(writeString.substr(41, 2));
				stdntPtrArray[i]->seqCode = stoi(writeString.substr(44, 6));
				stdntPtrArray[i]->age = stoi(writeString.substr(49, 3));

				i++; //increment counter variable.

				inputFile.read(arrayForRead, 52);
				writeString = arrayForRead;


				//writeString = arrayForRead;
				//cout << skipws << writeString;
					//cout << arrayForRead << endl;


		}

		cout << left << "First Name" << "  " << "Middle Initial" << "\t" << "Last Name" << "\t "
			<< "College Code" << "\t " << "Location Code" << "\t   " << "Sequence Code" << "\t"
			<< "Age" << endl;
		cout << left << "===========================================================" <<
						"===========================================================" << endl;
		for (int i = 0; stdntPtrArray[i] != NULL; i++)
			{

			cout << left
				<< stdntPtrArray[i]->fName << "\t  "
				<< stdntPtrArray[i]->mInitial << "\t\t"
				<< stdntPtrArray[i]->lName << "\t"
				<< stdntPtrArray[i]->collegeCode << "\t\t"
				<< stdntPtrArray[i]->locationCode << "\t\t"
				<< stdntPtrArray[i]->seqCode << "\t\t"
				<< stdntPtrArray[i]->age << "\t" << endl;

			}


		cout << "The Average Age of Students is: " << ageCalc(stdntPtrArray, ptrToStudent) << endl;
			//<< "and the Youngest Student is: " << ptrToStudent->age;

		// outputFile.write(address of a char array, length);
		// outputFile (a, 11);
		for(int i=0; i < ARRAY_SIZE;i++)
			delete stdntPtrArray[i];

		inputFile.close();
	return 0;
}

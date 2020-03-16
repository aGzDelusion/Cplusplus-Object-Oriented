/*
 * STRINGH.cpp
 *
 *  Created on: Nov 27, 2019
 *      Author: dquiambao197
 */

#include <iostream>
#include <string>

using namespace std;

#include "STRINGH.h"

string200::string200(int sz)
{
	size = sz;
	k = new string[size];
}

string200::string200()
{
	size = 100;
	k = new string[size];
}

string200::~string200()
{
	delete [] k;
	k = nullptr;
	cout << "successfully deleted string items" << endl;
}

string& string200::operator[](int position)
{
	if(position >= size)
	{
		cout << "Array index out of bounds!" << endl;
		exit(0);
	}
	return k[position];
}

//============================================================================
// Name        : QuiambaoA8.cpp
// Author      : Darwish Quiambao
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

#include "STRING.h"

int main()
{
	string200 <string> test(10);
	int i;
	test[0] = "abcde";
	cout << "main: first element " << test[0] << endl;
	for (i = 0; i < 10; i++)
	{
		test[i] = test[0].substr(0, 5) + to_string(i);
	}
	cout << "main: done with load 1, now displaying the array" << endl;
	for (i = 0; i < 10; i++)
	{
		cout << "array[" << i << "] = -->" << test[i] << "<--" << endl;
	}


	string200 <float> test2(10);
	test2[0] = 1.1;
	for (i = 1; i < 10; i++)
	{
		test2[i] = test2[i - 1] + 1.1;
	}
	cout << "main: done with load 2, now displaying the array" << endl;
	for (i = 0; i < 10; i++)
	{
		cout << "array[" << i << "] = " << test2[i] << endl;
	}
	cout << "main: now testing with subscript[10]" << endl;
	test[10] = "qwerty";
	cout << "main: after the test with subscript[10]" << endl;
	return 0;
}


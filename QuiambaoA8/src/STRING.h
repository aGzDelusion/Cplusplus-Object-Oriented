#pragma once
/*
* STRINGH.h
*
*  Created on: Nov 27, 2019
*      Author: dquiambao197
*/

#ifndef STRING_H_
#define STRING_H_

template <typename T1>
class string200
{
	int size;	//size of container
	T1 * k;	// pointer to a dynamically allocated array of strings
public:
	string200(int);	//constructor with parameter for size
	string200();	//default constructor sets size to 100
	~string200();	//destructor
	void func_throw(int);
	T1& operator [] (const int&);	//[] operator overloading for out of bounds checking
};


template <typename T1>
string200<T1>::string200(int sz)
{
	size = sz;
	k = new T1[size];
}

template <typename T1>
string200<T1>::string200()
{
	size = 100;
	k = new T1[size];
}

template <typename T1>
string200<T1>::~string200()
{
	delete[] k;
	//k = nullptr;
	cout << "successfully deleted string items" << endl;
}

template <typename T1>
void string200<T1>::func_throw(int position)
{
	//string s = "Array index out of bounds!";
	throw string("Array index out of bounds at position ");
	throw position;
	//throw std::runtime_error("Array index out of bounds! ");
	return;
}

template <typename T1>
T1& string200<T1>::operator[](const int &position)
{
	if (position >= size)
	{
		func_throw(position);
	}
	return k[position];


}

#endif /* STRINGH_H_ */

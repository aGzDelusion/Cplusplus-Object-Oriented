/*
 * STRINGH.h
 *
 *  Created on: Nov 27, 2019
 *      Author: dquiambao197
 */

#ifndef STRINGH_H_
#define STRINGH_H_

class string200
{
	int size;	//size of container
	string * k;	// pointer to a dynamically allocated array of strings
public:
	string200(int);	//constructor with parameter for size
	string200();	//default constructor sets size to 100
	~string200();	//destructor
	string& operator[](int);	//[] operator overloading for out of bounds checking
};

#endif /* STRINGH_H_ */

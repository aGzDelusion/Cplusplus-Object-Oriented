#pragma once
#ifndef STUDENT_H
#define STUDENT_H
#include <string>

struct Student
{
	std::string fName;
	char mInitial = NULL;
	std::string lName;
	char collegeCode = NULL;
	int locationCode = NULL;
	int seqCode = NULL;
	short int age = NULL;
};

#endif
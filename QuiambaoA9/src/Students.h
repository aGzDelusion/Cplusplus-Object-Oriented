/*
 * Students.h
 *
 *  Created on: Dec 1, 2019
 *      Author: capta
 */

#ifndef STUDENTS_H_
#define STUDENTS_H_


struct grades
{
	string deptAbbrev;
	int courseNumber;
	int creditHrs;
	char grade;
};


struct students
{
	string studentID;
	string studentName;
	vector<grades> grade;
};



#endif /* STUDENTS_H_ */

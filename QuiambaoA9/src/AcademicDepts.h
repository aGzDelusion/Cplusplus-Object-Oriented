/*
 * AcademicDepts.h
 *
 *  Created on: Dec 3, 2019
 *      Author: capta
 */

#ifndef ACADEMICDEPTS_H_
#define ACADEMICDEPTS_H_

class AcademicDept
{
	string abbreviation;	//member variable for department abbreviation
	string dept_name;	//member variable for dept name.
	map<string, string> aDept;
public:
	AcademicDept(char *);	//default constructor
	bool findDeptName(string, string &);
};


#endif /* ACADEMICDEPTS_H_ */

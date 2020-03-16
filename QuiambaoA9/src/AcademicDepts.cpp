/*
 * AcademicDepts.cpp
 *
 *  Created on: Dec 3, 2019
 *      Author: capta
 */

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <iterator>
using namespace std;
#include "AcademicDepts.h"

AcademicDept::AcademicDept(char *argv)
{
	string reader, temp;
	ifstream deptData(argv);

	while(!(getline(deptData, reader, '\n')).eof())
	{
		abbreviation = reader.substr(0, 5); //reader.find(' ') from 0 until first whitespace..
		dept_name = reader.substr(5, 20);
		aDept.insert(pair<string, string>(abbreviation, dept_name));
	}
};

bool AcademicDept::findDeptName(string deptAbbrev, string &name)
{
	map<string, string>::iterator map_it;
	map_it = aDept.find(deptAbbrev);
	if(map_it != aDept.end())
		name = map_it->second;
	else
		name = "No transcript";

	return ((map_it != aDept.end()) ? true : false);
}

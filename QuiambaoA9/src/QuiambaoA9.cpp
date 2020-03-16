//============================================================================
// Name        : QuiambaoA9.cpp
// Author      : Darwish Quiambao
// Version     : Final Release 2.0
// Copyright   : DarwishQuiambao
// Description : Final assignment involving C++ STL
//============================================================================
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
#include <iterator>
#include <map>
#include <exception>
using namespace std;
#include "Students.h"
#include "AcademicDepts.h"
int main(int argCount, char *studentsData[])
{
	vector<grades>::iterator gr_it;
	vector<students *>::iterator stu_it;
	vector<students *> ptrVect;

	string read_in;	//for reading in file
	students *s; //for parsing read string for student data
	grades g; //for parsing read string for grades data
	if(argCount < 4 )	//Check if argument count is valid
	{
		std::cerr << "Usage: " << studentsData[0] << "<filename>" << endl;
		return -1;
	}
	ifstream student_file(studentsData[1]);	//for reading the file thru argument
	if(!student_file.is_open()){
		cout << "File not found!" << endl;
		return -1;
	}
	//getline()

	while(!(getline(student_file, read_in, '\n')).eof())
	{
		if(read_in.at(0) == '1')
		{
			s = new students;
			s->studentID = read_in.substr(1, 6);
			s->studentName = read_in.substr(7, 19);
			ptrVect.push_back(s);
		}
		else if(read_in.at(0) == '2')
		{
			g.courseNumber = stoi(read_in.substr(6, 3));
			g.deptAbbrev = read_in.substr(1, 5);
			g.creditHrs = stoi(read_in.substr(10, 1));
			g.grade = read_in.at(11);
			s->grade.push_back(g);
		}
	}

	student_file.close();	//first file closed
	read_in.clear();	//string read clear

	for(stu_it = ptrVect.begin(); stu_it != ptrVect.end(); stu_it++)
	{
		cout << endl << (*stu_it)->studentName << " " << (*stu_it)->studentID << endl << endl;
			 for(gr_it = (*stu_it)->grade.begin(); gr_it != (*stu_it)->grade.end(); gr_it++)
			{
				 cout << gr_it->deptAbbrev << " " << gr_it->courseNumber << " "
					  << gr_it->creditHrs << " " << gr_it->grade << endl;
				 if(gr_it->creditHrs == 0)
					 cout << "No transcript";
			}
	}

	/// 2. ACADEMIC DEPARTMENTS - AcademicDepts.h & .cpp
		//to read the file a9.ini using parameter from argument list, studentsData[2]
		AcademicDept dept(studentsData[2]);
		for(stu_it = ptrVect.begin(); stu_it != ptrVect.end(); stu_it++)
			for(gr_it = (*stu_it)->grade.begin(); gr_it != (*stu_it)->grade.end(); gr_it++)
				dept.findDeptName(gr_it->deptAbbrev, gr_it->deptAbbrev);
		/////////////////////////////////////////////////////////////////////////////////
	/// 3. GRADE REPORT
		double GPA = 0.0, totalGPA = 0.0 , temp = 0.0;	//for GPA calculation
		int hrs = 0;
		cout << "-------------------------------------------------------------" << endl
			 << "Student Report - As of " << studentsData[3] << endl
			 << "-------------------------------------------------------------" << endl;

		for(stu_it = ptrVect.begin(); stu_it != ptrVect.end(); stu_it++)
		{

			cout << endl <<(*stu_it)->studentName << "\t\t\t" << (*stu_it)->studentID
				 << endl;
			GPA = 0.0, totalGPA = 0.0, temp = 0.0, hrs = 0; //reset values every student iteration
			for(gr_it = (*stu_it)->grade.begin(); gr_it != (*stu_it)->grade.end(); gr_it++)
			{
				//Phase 4: GPA calculation and Display of Students
				switch(gr_it->grade)
				{
				case 'A':
					GPA = 4.0 * gr_it->creditHrs;
					break;

				case 'B':
					GPA = 3.0 * gr_it->creditHrs;
					break;

				case 'C':
					GPA = 2.0 * gr_it->creditHrs;
					break;

				case 'D':
					GPA = 1.0 * gr_it->creditHrs;
					break;

				case 'F':
					GPA = 0.0 * gr_it->creditHrs;
					break;

				default:
					cout << "No Transcript";
					break;
				}
				temp += GPA;
				cout << left << setw(20) << gr_it->deptAbbrev << "\t" << setw(5)
					 << gr_it->courseNumber << "\t" << setw(4)
					 << gr_it->creditHrs << "\t"
					 << gr_it->grade << endl;
				hrs += gr_it->creditHrs;
			}

			if(GPA == 0.0 && hrs == 0)
					cout << left << "-------------------------------------------------------------" << endl
						 << "No Transcript" << endl << "-------------------------------------------------------------" << endl;

			else{
				totalGPA = temp/hrs;
				cout << left << "-------------------------------------------------------------" << endl << "GPA: "
					 << setprecision(3) << totalGPA << endl
					 << "-------------------------------------------------------------" << endl;
			}
		}
		read_in.clear();
		///Phase 5: Queries
		cout << endl << "Enter one of the following selections or type 'exit' to exit: " << endl
			 << "A - Search for a specific course name and course number " << endl
			 << "B - Search for course name ONLY (Will need Student ID later)" << endl;
		getline(cin, read_in);
		while(read_in != "exit")
		{
			int courseNum = 0;	//for query of course number
			if(read_in == "A")
			{
				cout << "Enter a *VALID* class name and *VALID* course number to search for: ";
				getline(cin, read_in);
				stringstream(read_in) >> read_in >> courseNum;
				cout << "=========================================================================" << endl;
				for(stu_it = ptrVect.begin(); stu_it != ptrVect.end(); stu_it++)
				{
					///Iterate through vector of student courses inside vector of pointers to students
					for(gr_it = (*stu_it)->grade.begin(); gr_it != (*stu_it)->grade.end(); gr_it++)
						{
							if(read_in == gr_it->deptAbbrev && courseNum == gr_it->courseNumber)
								switch(gr_it->grade)
									{
										case 'F':
											cout << (*stu_it)->studentName <<  " with a student ID of '" << (*stu_it)->studentID  << "' has NOT yet received a passing grade in "
												 << gr_it->deptAbbrev << " " << gr_it->courseNumber << endl << endl;
											break;
										default:
											cout << (*stu_it)->studentName << " with a student ID of '" << (*stu_it)->studentID  << "' already passed "
												 << gr_it->deptAbbrev << " " << gr_it->courseNumber << endl << endl;
									}
						}
					}
				}
			else if(read_in == "B")
			{
				///Check if B is input
				cout << "Enter Student ID: ";
				getline(cin, read_in);
				for(stu_it = ptrVect.begin(); stu_it != ptrVect.end(); stu_it++)
				{
					if(read_in == (*stu_it)->studentID)
					{
						string show; //for viewing GPA getline
						bool flag = false;
						cout << "Student: " << (*stu_it)->studentName << endl << endl;
						cout << "Enter a *VALID* course name: ";
						getline(cin, read_in);
						cout << "Input 'Yes' to view GPA: ";
						getline(cin, show);
						//since strings cant use tolower or toupper methods directly..
							if(show == "Yes" || show == "yes" || show == "yES" || show == "yEs" || show == "YeS")
								flag = true;
							GPA = 0.0, totalGPA = 0.0, hrs = 0, temp = 0.0;
							cout << endl << (*stu_it)->studentName << "\t\t" << (*stu_it)->studentID << endl;
								for(gr_it = (*stu_it)->grade.begin(); gr_it != (*stu_it)->grade.end(); gr_it++)
								{
									if(read_in == gr_it->deptAbbrev && flag == false)
									{
										cout << left << setw(20) << endl
											 <<	gr_it->deptAbbrev << "\t" << setw(5) << gr_it->courseNumber << "\t"
											 << setw(4) << gr_it->creditHrs << "\t" << gr_it->grade;
									}
									else if(read_in == gr_it->deptAbbrev && flag == true)
									{
										switch(gr_it->grade)
										{
											case 'A':
												GPA = 4.0 * gr_it->creditHrs;
												break;

											case 'B':
												GPA = 3.0 * gr_it->creditHrs;
												break;

											case 'C':
												GPA = 2.0 * gr_it->creditHrs;
												break;

											case 'D':
												GPA = 1.0 * gr_it->creditHrs;
												break;

											case 'F':
												GPA = 0.0 * gr_it->creditHrs;
												break;

											default:
												cout << "No Transcript";
												break;
										}
										temp += GPA;
										cout << left << setw(20) << gr_it->deptAbbrev << "\t" << setw(5)
											 << gr_it->courseNumber << "\t" << setw(4)
											 << gr_it->creditHrs << "\t"
											 << gr_it->grade << endl;
										hrs += gr_it->creditHrs;
									}
								}
							if(flag == true){
							totalGPA = temp/hrs;
							cout << left << "-------------------------------------------------------------" << endl << "Total GPA for Courses: "
								 << setprecision(3) << totalGPA << endl
								 << "-------------------------------------------------------------" << endl << endl;
							}
						}
					}
			}

			cout << endl << endl << "-------------------------------------------------------------" << endl
				 << "Enter one of the following selections or type 'exit' to exit: " << endl
				 << "A - Search for a specific course name and course number " << endl
				 << "B - Search for course name ONLY (Will need Student ID later)" << endl;
				 getline(cin, read_in);
		}

	cout << endl << "================ END OF PROGRAM ================" << endl;
	for(size_t i = 0; i < ptrVect.size(); i++)
		delete ptrVect.at(i);	//delete pointers stored

	for(size_t i = 0; i <ptrVect.size(); i++)
		ptrVect.pop_back();	//clear all elements in vector

	return 0;
}

//============================================================================
// Name        : QuiambaoA3.cpp
// Author      : Darwish Quiambao
// Version     :
// Copyright   : 
// Description : Assignment 3
//============================================================================

#include <iostream>
using namespace std;

#include "Payroll.h"

int main() {
	Payroll employee;
	float hours = 0.0, rate = 0.0; //variables for input

		cout << "Enter work hours (or enter a negative value to exit): "; //get hours from console
		cin >> hours;


		while(hours >= 0.0)
		{

			employee.setHours(hours);	//use setter for object employee to set the member variable hours with provided input

			cout << "Enter pay rate: ";
			cin.ignore() >> rate;	//inputs pay rate
			employee.setRate(rate);

			cout << "Hours = " << employee.getHours() << ", Rate = " << employee.getRate() << endl;

			employee.computeWork(); //computes work using provided hours and rate.

			std::cout << "Regular Pay = $" << employee.getRegPay() << ", Overtime Pay = $" << employee.getOvertimePay()
					  << ", Total Pay = $" << (employee.getRegPay()+employee.getOvertimePay()) << std::endl;

			cout << "Enter work hours (or enter a negative value to exit): ";
			cin.ignore() >> hours;
			employee.setHours(hours);

		}

		cout << "Thank you for using the program!" << endl;

	return 0;
}

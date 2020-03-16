/*
 * Payroll.cpp
 *
 *  Created on: Oct 1, 2019
 *      Author: Darwish Quiambao
 */

//Implementation file for member variables and methods of class Payroll.

#include "Payroll.h"
#include <iostream>

Payroll::Payroll() //default constructor.
	{
		regularPay = 0.0;
		overtimePay = 0.0;
		workHours = 0.0;
		hourlyRate = 0.0;
	}

Payroll::~Payroll(){} //C++ implicit destructor

///Getter functions
float Payroll::getHours() //returns workHours from public members
{
	return workHours;
}

float  Payroll::getOvertimePay() //returns overtime pay private variable
{
	return overtimePay;
}

float Payroll::getRate() //
{
	return hourlyRate;
}

float Payroll::getRegPay() //returns regular pay private variable
{
	return regularPay;
}

///Setter functions
void Payroll::setHours(const float &hours)
{
	workHours = hours; //assigns the passed hours into workhours variable
}

void Payroll::setRate(const float &rate)
{
	hourlyRate = rate;
}

void Payroll::computeWork() //Calculates pay for employee
{
	float overtimeHour = 0.0;
	const float OVERTIME_HOUR = 40.0, OVERTIME_PAYRATE = 1.5; //Used to subtract from regular work hours
	if(workHours > OVERTIME_HOUR)
		overtimeHour = workHours - OVERTIME_HOUR;

		overtimePay = overtimeHour * hourlyRate * OVERTIME_PAYRATE;
		regularPay = workHours * hourlyRate;

}

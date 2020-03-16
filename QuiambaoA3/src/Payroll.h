/*
 * Payroll.h
 *
 *  Created on: Oct 1, 2019
 *      Author: Darwish Quiambao
 */

#ifndef PAYROLL_H_
#define PAYROLL_H_

class Payroll
{
//since class is private by default, no need to use keyword private when above public
	float regularPay;
	float overtimePay;

public:
	float workHours;
	float hourlyRate;

	//default constructors and destructors
	Payroll();
	~Payroll();

	//getter functions
	float getHours(); //Getter function to get hours.
	float getRate(); //Getter function to get rate.
	float getRegPay(); //Getter function to regular pay.
	float getOvertimePay(); //Getter function to OvertimePay.

	//setter functions
	void setHours(const float &); //setter for hours of work
	void setRate(const float &); //setter for hourly rate

	//Method for calculation
	void computeWork();
};


#endif /* PAYROLL_H_ */

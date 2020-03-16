/*
 * Vehicles.cpp
 *
 *  Created on: Nov 15, 2019
 *      Author: capta
 */
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#include "Vehicles.h"

Vehicle::Vehicle(string vehID, string manufacturer, string serviceDate, string inspectionDate, int cap, char stat)
{
	id = vehID;
	mfg = manufacturer;
	servDate = serviceDate;
	inspDate = inspectionDate;
	capacity = cap;
	status = stat;
}

string Vehicle::getID() const //getter for Vehicle ID
{
	return id;
}
string Vehicle::getMfg() const //getter for Manufacturer
{
	return mfg;
}
string Vehicle::getservDate() const//getter for date entered service
{
	return servDate;
}
string Vehicle::getinspDate() const//getter for last inspection
{
	return inspDate;
}
int Vehicle::getCapacity() const//capacity getter
{
	return capacity;
}
char Vehicle::getStatus() const//status getter
{
	return status;
}
void Vehicle::setID(string ID) //setter for Vehicle ID
{
	id = ID;
}
void Vehicle::setMfg(string manufacturer) //setter for Manufacturer
{
	mfg = manufacturer;
}
void Vehicle::setservDate(string serviceDate) //setter for date entered service in YYYYMMDD
{
	servDate = serviceDate;
}
void Vehicle::setinspDate(string inspectionDate) //setter for last inspection in YYYYMMDD
{
	inspDate = inspectionDate;
}

void Vehicle::setCapacity(int cap) //capacity setter
{
	capacity = cap;
}
void Vehicle::setStatus(char stat) //status setter
{
	status = stat;
}

void Vehicle::display() const
{
	cout << "Vehicle ID: " << this->id << ", Manufacturer: " << this->mfg << endl << "Date entered service: " << this->servDate << ", Last Inspection Date: " << this->inspDate
		 << ", Capacity: " << this->capacity << ", Status: " << this->status << endl;
}

void Vehicle::maintenanceCheck()
{
	cout << "Maintenance Check: Vehicles" << endl;
}

Vehicle::~Vehicle(){};

// Bus Class
Bus::Bus(string vehID, string manufacturer, string serviceDate, string inspectionDate, int cap, char stat, int miles, string tiresize, char fueltype)
: Vehicle(vehID, manufacturer, serviceDate, inspectionDate, cap, stat)
{
	mileage = miles;
	tireSize = tiresize;
	fuelType = fueltype;
}

int Bus::getMileage() const
{
	return mileage;
}

string Bus::getTireSize() const
{
	return tireSize;
}

char Bus::getFuelType() const
{
	return fuelType;
}

void Bus::setMileage(int miles)
{
	mileage = miles;
}

void Bus::setTireSize(string tiresize)
{
	tireSize = tiresize;
}

void Bus::setFuelType(char fueltype)
{
	fuelType = fueltype;
}

void Bus::display() const
{
	Vehicle::display();
	cout << "Bus mileage since last inspection: " << this->mileage << ", Tire Size: " << this->tireSize
		 << ", Fuel Type: " << this->fuelType << endl;
}

void Bus::maintenanceCheck()
{
	//If Bus Mileage since last inspection is greater than 25,000 Miles, inspection is required
	const int INSP_MILES = 25000; //Mileage
	if(this->getMileage() > INSP_MILES)
	{
		cout << "Maintenance required...\nChanging status to 'M'" << endl;
		this->setStatus('M');
	}
}

Bus::~Bus(){};

//RailCar Functions

Railcar::Railcar(string vehID, string manufacturer, string serviceDate, string inspectionDate, int cap, char stat, int power, string motorType)
: Vehicle(vehID, manufacturer, serviceDate, inspectionDate, cap, stat)
{
	pwr = power;
	motor = motorType;
}

int Railcar::getPwr() const
{
	return pwr;
}

string Railcar::getMotor() const
{
	return motor;
}

void Railcar::setPwr(int power)
{
	pwr = power;
}

void Railcar::setMotor(string motortype)
{
	motor = motortype;
}

void Railcar::display() const
{
	Vehicle::display();
	cout << "Power-On time since last inspection: " << this->pwr << ", Motor Type: " << this->motor << endl;
}

void Railcar::maintenanceCheck()
{
	//If Power-On Time since last inspection is 100 Days or Higher, maintenance is required.
	const int INSP_TIME = 100; //Days
		if(this->getPwr() >= INSP_TIME)
		{
			cout << "Maintenance required...\nChanging status to 'M'" << endl;
			this->setStatus('M');
		}
}

Railcar::~Railcar(){};

//Helicopter functions
Helicopter::Helicopter(string vehID, string manufacturer, string serviceDate, string inspectionDate, int cap, char stat, int aframeHours, int pplantHours)
: Vehicle(vehID, manufacturer, serviceDate, inspectionDate, cap, stat)
{
	airframeHrs = aframeHours;
	powerplantHrs = pplantHours;
}

int Helicopter::getAirframeHrs() const
{
	return airframeHrs;
}

int Helicopter::getPowerplantHrs() const
{
	return powerplantHrs;
}

void Helicopter::setAirframeHrs(int aframe)
{
	airframeHrs = aframe;
}
void Helicopter::setPowerplantHrs(int pplant)
{
	powerplantHrs = pplant;
}

void Helicopter::display() const
{
	Vehicle::display();
	cout << "Airframe Hours since last inspection: " << this->airframeHrs << ", Powerplant Hours since last inspection: "
		 << this->powerplantHrs << endl;
}

void Helicopter::maintenanceCheck()
{	//If airframe hours since last inspection is 1000 hours or longer, or the engine
	//hours since last inspection is 750 hours or greater..maintenance required.
	const int MAINT_REQ_AF = 1000,
			  MAINT_REQ_PP = 750;
	if(this->getAirframeHrs() >= MAINT_REQ_AF || this->getPowerplantHrs() >= MAINT_REQ_PP)
	{
		cout << "Maintenance required...\nChanging status to 'M'" << endl;
		this->setStatus('M');
	}
}

Helicopter::~Helicopter(){};



//End of Constructors, Mutators and Accessors

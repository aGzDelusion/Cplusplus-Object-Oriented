#include "Bus.h"

Bus::Bus()
{
	bus_ID = "0";
	manufacturer = "0";
	capacity = 0;
	mileage = 0;
	status = '0';
	activeElem = 0;
	busCount = 0;
}
//MaintHist Bus::maintH[25];
int Bus::busCount = 0;
float Bus::averageMiles = 0;
int Bus::totalMileage = 0;

std::string Bus::getID()
{
	return bus_ID;
}

float Bus::getAverageMiles()
{
	return averageMiles;
}

int Bus::getBusCount()
{
	return busCount;
}

std::string Bus::getMfg()
{
	return manufacturer;
}

int Bus::getCapacity()
{
	return capacity;
}

int Bus::getMileage()
{
	return mileage;
}

char Bus::getStatus()
{
	return status;
}

void Bus::setStatus(char &stat)
{
	status = stat;
}

//setter for busID
void Bus::setBusID(std::string id)
{
	bus_ID = id;
}
void Bus::setManufacturer(std::string mfg) //setter for mfg member variable
{
	manufacturer = mfg;
}

void Bus::setCapacity(int cap) //setter for capacity member variable
{
	capacity = cap;
}

void Bus::setMileage(int miles)	//setter for mileage member variable
{
	mileage = miles;
}

void Bus::updateBus()
{
	busCount++;
	totalMileage += mileage;
	averageMiles = (totalMileage + mileage)/busCount; //how to calculate?
}

bool Bus::operator < (Bus &bus2) //for comparing
{
	return (activeElem < bus2.activeElem ? true : false);
}

#include "Bus.h"

Bus::Bus(std::string ID, std::string mfg, int cap, int miles, char stat)
{
  bus_ID = ID;
  manufacturer = mfg;
  capacity = cap;
  mileage = miles;
  status = stat;
}

std::string Bus::getID()
{
	return bus_ID;
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

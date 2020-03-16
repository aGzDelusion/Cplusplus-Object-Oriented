/*
 * Vehicles.h
 *
 *  Created on: Nov 15, 2019
 *      Author: capta
 */

#ifndef VEHICLES_H_
#define VEHICLES_H_

class Vehicle
{
protected:
	string id, //vehicle id
		   mfg, //manufacturer
		   servDate, //date entered service in YYYYMMDD
		   inspDate; //date of last inspection in YYYYMMDD
	int capacity;	//capacity
	char status;	// A when active and may be scheduled
				// I vehicle inactive and excluded from scheduling
				// M vehicle is currently in maintenance and is excluded from scheduling

public:
	Vehicle(string, string, string, string, int, char); //constructor
	string getID() const; //getter for Vehicle ID
	string getMfg() const; //getter for Manufacturer
	string getservDate() const; //getter for date entered service
	string getinspDate() const; //getter for last inspection
	int getCapacity() const; //capacity getter
	char getStatus() const; //status getter
	void setID(string); //setter for Vehicle ID
	void setMfg(string); //setter for Manufacturer
	void setservDate(string); //setter for date entered service in YYYYMMDD
	void setinspDate(string); //setter for last inspection in YYYYMMDD
	void setCapacity(int); //capacity setter
	void setStatus(char); //status setter

	//display function VF
	virtual void display() const;
	virtual void maintenanceCheck();
	virtual ~Vehicle(); //virtual destructor

};

class Bus : public Vehicle
{
protected:
	int mileage; //current mileage
	string tireSize; //tire size
	char fuelType; // G - gasoline, P - Propane, E - Electric
public:
	Bus(string, string, string, string, int, char, int, string, char); //constructor
	//Accessor functions
	int getMileage() const;
	string getTireSize() const;
	char getFuelType() const;

	//Mutator functions
	void setMileage(int); //receives int
	void setTireSize(string); //receives string
	void setFuelType(char); //G - gas, P - Propane, E- Electric

	//virtual functions
	virtual void display() const;
	virtual void maintenanceCheck();
	virtual ~Bus();
};

class Railcar : public Vehicle
{
protected:
	int pwr; //current power-on time in days
	string motor; //motor type

public:
	//using Vehicle::Vehicle;
	Railcar(string, string, string, string, int, char, int, string); //Railcar constructor
	//Accessor functions
	int getPwr() const;
	string getMotor() const;

	//Mutator functions
	void setPwr(int);
	void setMotor(string);

	//virtual functions
	virtual void display() const;
	virtual void maintenanceCheck();
	virtual ~Railcar();
};

class Helicopter : public Vehicle
{
protected:
	int airframeHrs, //current airframe flight time in hours
		powerplantHrs; //current engine time in hours

public:
	Helicopter(string, string, string, string, int, char, int, int);
	//Accessor functions
	int getAirframeHrs() const;
	int getPowerplantHrs() const;

	//Mutator functions
	void setAirframeHrs(int);
	void setPowerplantHrs(int);

	//Virtual Functions
	virtual void display() const;
	virtual void maintenanceCheck();
	virtual ~Helicopter();
};

#endif /* VEHICLES_H_ */

#ifndef BUS_H
#define BUS_H

#include <string>

class Bus
{
    std::string bus_ID;
    std::string manufacturer;
    int capacity;
    int mileage;
    char status;
  
  public:
    Bus(std::string, std::string, int, int, char);  //prototyped class constructor
    std::string getID(); //getter for ID
    std::string getMfg();  //getter for manufacturer
    int getCapacity();  //getter for capacity
    int getMileage(); //getter for mileage
    char getStatus(); //getter for status
    void setStatus(char&); //setter for status.
};

#endif

#ifndef BUS_H
#define BUS_H

#include <string>

class MaintHist
{
  public:
    std::string maintDate;
    std::string maintType;
    std::string maintMechanic;
};

class Bus
{
    std::string bus_ID;
    std::string manufacturer;
    int capacity;
    int mileage;
    char status;
    static int busCount;
    static int totalMileage;
    static float averageMiles;

  public:
    Bus();
    MaintHist maintH[25];
    int activeElem;

    //getters
    std::string getID(); //getter for ID
    std::string getMfg();  //getter for manufacturer
    int getCapacity();  //getter for capacity
    int getMileage(); //getter for mileage
    char getStatus(); //getter for status
    float getAverageMiles();
    int getBusCount();
    //setters
    void setStatus(char&); //setter for status.
    void setBusID(std::string);	//setter for busID
    void setManufacturer(std::string); //setter for mfg member variable
    void setCapacity(int); //setter for capacity member variable
    void setMileage(int);	//setter for mileage member variable

    void updateBus();
    bool operator < (Bus &);
};

//Maintenance History class


#endif

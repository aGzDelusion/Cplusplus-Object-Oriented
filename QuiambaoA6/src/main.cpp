#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
//#include "functions.h"
#include "Bus.h"
#include "BusManager.h"


int main()
{
	BusManager busMgr;
	busMgr.process();
	busMgr.cleanup();

	cout << "Thank you for using the program!" << endl;
	return 0;
}

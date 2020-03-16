#include "age.h"
#include <iostream>

int  ageCalc(Student* stdntPtrArray[], Student * &ptr)
{
	int sumAge = 0, temp = 0, i = 0;
	
	for (i = 0; stdntPtrArray[i] != NULL; i++) {
		
		sumAge = (sumAge + stdntPtrArray[i]->age);
		
		temp = stdntPtrArray[i]->age;
		if (temp > stdntPtrArray[i]->age) {
			temp = stdntPtrArray[i]->age;
			ptr = stdntPtrArray[i];
		}
		
	}
	

	sumAge = sumAge / i;
	
	return sumAge;
}

#pragma once
#include "Car.h"

class Volvo : public Car
{
private:

public:
	Volvo() : Car(65, 12, 110) { this->name = new char[6]; name[0] = 'V', name[1] = 'o', name[2] = 'l', name[3] = 'v', name[4] = 'o', name[5] = '\0'; };
	int getFuelCapacity();
	double getFuelConsumption();
	double getAverageSpeed();
	char* getName();
};


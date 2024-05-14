#pragma once
#include "Car.h"

class BMW : public Car
{
private:

public:
	BMW() : Car(75, 13, 135) { this->name = new char[4]; name[0] = 'B', name[1] = 'M', name[2] = 'W', name[3] = '\0'; };
	int getFuelCapacity();
	double getFuelConsumption();
	double getAverageSpeed();
	char* getName();
};



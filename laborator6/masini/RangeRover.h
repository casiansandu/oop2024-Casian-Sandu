#pragma once
#include "Car.h"

class RangeRover : public Car
{
private:

public:
	RangeRover() : Car(75, 14, 115) { this->name = new char[3]; name[0] = 'R', name[1] = 'R', name[2] = '\0'; };
	int getFuelCapacity();
	double getFuelConsumption();
	double getAverageSpeed();
	char* getName();
};


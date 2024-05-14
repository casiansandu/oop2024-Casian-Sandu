#pragma once
#include "Car.h"

class Fiat : public Car
{
private:

public:
	Fiat() : Car(75, 10, 80) { this->name = new char[5]; name[0] = 'F', name[1] = 'i', name[2] = 'a', name[3] = 't', name[4] = '\0'; };
	int getFuelCapacity();
	double getFuelConsumption();
	double getAverageSpeed();
	char* getName();
};


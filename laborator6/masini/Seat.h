#pragma once
#include "Car.h"

class Seat : public Car
{
private:

public:
	Seat() : Car(15, 7, 90) { this->name = new char[5]; name[0] = 'S', name[1] = 'e', name[2] = 'a', name[3] = 't', name[4] = '\0'; };
	int getFuelCapacity();
	double getFuelConsumption();
	double getAverageSpeed();
	char* getName();
};


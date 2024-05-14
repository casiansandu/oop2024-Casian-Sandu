#include "Volvo.h"

int Volvo::getFuelCapacity()
{
	return this->fuel_capacity;
}

double Volvo::getFuelConsumption()
{
	return this->fuel_consumption;
}

double Volvo::getAverageSpeed()
{
	return this->average_speed;
}

char* Volvo::getName()
{
	return this->name;
}
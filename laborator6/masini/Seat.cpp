#include "Seat.h"

int Seat::getFuelCapacity()
{
	return this->fuel_capacity;
}

double Seat::getFuelConsumption()
{
	return this->fuel_consumption;
}

double Seat::getAverageSpeed()
{
	return this->average_speed;
}

char* Seat::getName()
{
	return this->name;
}
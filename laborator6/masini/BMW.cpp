#include "BMW.h"

int BMW::getFuelCapacity()
{
	return this->fuel_capacity;
}

double BMW::getFuelConsumption()
{
	return this->fuel_consumption;
}

double BMW::getAverageSpeed()
{
	return this->average_speed;
}

char* BMW::getName()
{
	return this->name;
}
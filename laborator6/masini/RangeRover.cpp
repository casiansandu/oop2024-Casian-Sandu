#include "RangeRover.h"

int RangeRover::getFuelCapacity()
{
	return this->fuel_capacity;
}

double RangeRover::getFuelConsumption()
{
	return this->fuel_consumption;
}

double RangeRover::getAverageSpeed()
{
	return this->average_speed;
}

char* RangeRover::getName()
{
	return this->name;
}
#include "Fiat.h"

int Fiat::getFuelCapacity()
{
	return this->fuel_capacity;
}

double Fiat::getFuelConsumption()
{
	return this->fuel_consumption;
}

double Fiat::getAverageSpeed()
{
	return this->average_speed;
}

char* Fiat::getName()
{
	return this->name;
}
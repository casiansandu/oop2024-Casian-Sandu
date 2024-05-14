#include "Car.h"

void Car::setFuelCapacity(int newCapacity)
{
	this->fuel_capacity = newCapacity;
}

void Car::setFuelConsumption(double newConsumption)
{
	this->fuel_consumption = newConsumption;
}

void Car::setAverageSpeed(double newSpeed)
{
	this->average_speed = newSpeed;
}

int Car::getFuelCapacity()
{
	return this->fuel_capacity;
}

double Car::getFuelConsumption()
{
	return this->fuel_consumption;
}

double Car::getAverageSpeed()
{
	return this->average_speed;
}

Car::Car(const Car& n)
{
	this->average_speed = n.average_speed;
	this->fuel_capacity = n.fuel_capacity;
	this->fuel_consumption = n.fuel_consumption;
}

char* Car::getName()
{
	return this->name;
}


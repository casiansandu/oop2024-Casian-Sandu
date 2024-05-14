#pragma once
#include "Weather.h"

class Car
{
protected:
	int fuel_capacity;
	double fuel_consumption;
	double average_speed;
	char* name;
public:
	Car() : fuel_capacity(55), fuel_consumption(10), average_speed(110) { this->name = new char[5]; name[0] = 'C', name[1] = 'a', name[2] = 'r', name[3] = '\0'; };
	Car(int val1, double val2, double val3) { this->fuel_capacity = val1;
												this->fuel_consumption = val2; 
												this->average_speed = val3; 
												this->name = new char[4]; name[0] = 'C', name[1] = 'a', name[2] = 'r', name[3] = '\0';
	};
	Car(const Car& n);
	void setFuelCapacity(int newCapacity);
	void setFuelConsumption(double newConsumption);
	void setAverageSpeed(double newSpeed);
	virtual int getFuelCapacity();
	virtual double getFuelConsumption();
	virtual double getAverageSpeed();
	virtual char* getName();
};

#include "Circuit.h"
#include <iostream>

void Circuit::setLength(int newLength)
{
	this->length = newLength;
}

void Circuit::setWeather(Weather weather)
{
	if (weather == Weather::Sunny) this->weather_modif = 3;
	else if (weather == Weather::Rain) this->weather_modif = 2;
	else this->weather_modif = 1;
}

void Circuit::addCar(Car* newCar)
{
	Car* aux = new Car[this->number_of_participants + 1];
	for (int i = 0; i < this->number_of_participants; i++)
		aux[i] = this->participants[i];
	aux[this->number_of_participants] = *newCar;
	delete[]this->participants;
	this->participants = aux;
	this->number_of_participants++;
}

void Circuit::addDNF(Car *newDNF)
{
	Car* aux = new Car[this->number_of_DNF + 1];
	for (int i = 0; i < this->number_of_DNF; i++)
		aux[i] = this->DNF[i];
	aux[this->number_of_DNF] = *newDNF;
	delete[]this->DNF;
	this->DNF = aux;
	this->number_of_DNF++;
}

void Circuit::addFinishers(Car* newFinisher)
{
	Car* aux = new Car[this->number_of_finishers + 1];
	for (int i = 0; i < this->number_of_finishers; i++)
		aux[i] = this->finishers[i];
	aux[this->number_of_finishers] = *newFinisher;
	delete[]this->finishers;
	this->finishers = aux;
	this->number_of_finishers++;
}

void Circuit::race()
{
	int ok;
	for (int i = 0; i < this->number_of_participants; i++)
	{
		ok = 1;
		if (this->participants[i].getFuelCapacity() * this->participants[i].getFuelConsumption() < this->length * this->laps)
			ok = 0;

		if (!ok)
		{
			this->addDNF(&this->participants[i]);
		}
		else
		{
			this->addFinishers(&this->participants[i]);
		}
	}

	for (int i = 0; i < this->number_of_finishers - 1; i++)
	{
		for (int j = i; j < this->number_of_finishers; j++)
		{
			if (this->finishers[i].getAverageSpeed() < this->finishers[j].getAverageSpeed())
			{
				Car* aux = new Car;
				*aux = this->finishers[i];
				this->finishers[i] = this->finishers[j];
				this->finishers[j] = *aux;
			}
		}
	}
}

double Circuit::getCarSpeed(int index)
{
	if (index < this->number_of_participants)
		return (this->participants[index].getAverageSpeed() * this->weather_modif / 3.f);
	return 0;
}

void Circuit::showWhoDidNotFinish()
{
	for (int i = 0; i < this->number_of_DNF; i++)
		std::cout << this->DNF[i].getName() << ' ';
}

void Circuit::showFinishers()
{
	for (int i = 0; i < this->number_of_finishers; i++)
	{
		std::cout << this->finishers[i].getName() << ' ' << (this->laps * this->length)/this->finishers[i].getAverageSpeed() << '\n';
	}
}
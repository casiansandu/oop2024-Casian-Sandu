#pragma once
#include "Weather.h"
#include "Car.h"
#include "BMW.h"
#include "Seat.h"
#include "RangeRover.h"
#include "Volvo.h"
#include "Fiat.h"

class Circuit
{
private:
	int length;
	int laps;
	int weather_modif;
	int number_of_participants;
	void addDNF(Car* masina);
	void addFinishers(Car* masina);
	int number_of_DNF;
	int number_of_finishers;
	Car* finishers;
	Car* DNF;
	Car* participants;
public:
	Circuit() : length(5), laps(70), weather_modif(3), number_of_participants(0), number_of_DNF(0), number_of_finishers(0),
				finishers(nullptr), DNF(nullptr), participants(nullptr){ };
	double getCarSpeed(int index);
	void setLength(int newLength);
	void setWeather(Weather weather);
	void race();
	void addCar(Car* newCar);
	void showWhoDidNotFinish();
	void showFinishers();
};


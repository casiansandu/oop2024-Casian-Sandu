#pragma once
#include "Movie.h"

class MovieSeries
{
private:
	Movie *filme[16];
	int count;
public:
	void init();
	bool add(Movie *mov);
	void print();
	void sort();
};


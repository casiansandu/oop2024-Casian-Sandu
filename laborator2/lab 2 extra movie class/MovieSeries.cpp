#include "MovieSeries.h"
#include <iostream>

void MovieSeries::init()
{
	this->count = 0;
}

bool MovieSeries::add(Movie* mov)
{
	if (this->count > 15) return false;
	else
	{
		this->filme[this->count] = mov;
		this->count++;
	}
}

void MovieSeries::print()
{
	for (int i = 0; i < this->count; i++)
	{
		std::cout << this->filme[i]->get_name() << '\n';
		std::cout << this->filme[i]->get_length() << " minute" << '\n';
		std::cout << this->filme[i]->get_score() << " scor" << '\n';
		std::cout << "an lansare: " << this->filme[i]->get_year() << '\n';
		std::cout << '\n';
	}
}

void MovieSeries::sort()
{
	Movie *aux;
	for (int i = 0; i < this->count - 1; i++)
	{
		for (int j = i + 1; j < this->count; j++)
		{
			if (this->filme[i]->get_year() < this->filme[j]->get_year())
			{
				aux = this->filme[i];
				this->filme[i] = this->filme[j];
				this->filme[j] = aux;
			}
		}
	}
}
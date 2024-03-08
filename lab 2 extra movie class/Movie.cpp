#include "Movie.h"
#include <time.h>
#include <cstring>

bool Movie::set_name(const char new_name[])
{
	if (strlen(new_name) < 256)
	{
		memcpy(this->name, new_name, strlen(new_name) + 1);
		return true;
	}
	else return false;
}

bool Movie::set_score(float new_score)
{
	if (new_score >= 0 && new_score <= 10)
	{
		this->score = new_score;
		return true;
	}
	else return false;
}

bool Movie::set_year(int new_year)
{
	int an_actual = 1970 + time(NULL) / 60 / 60 / 24 / 365;
	if (new_year >= 1900 && new_year <= an_actual)
	{
		this->release_year = new_year;
		this->years_since_release = an_actual - new_year;
		return true;
	}
	else return false;
}

bool Movie::set_length(int new_length)
{
	if (new_length >= 0)
	{
		this->length = new_length;
		return true;
	}
	else return false;
}


char* Movie::get_name()
{
	return this->name;
}

float Movie::get_score()
{
	return this->score;
}

int Movie::get_year()
{
	return this->release_year;
}

int Movie::get_length()
{
	return this->length;
}

int Movie::get_years_since_release()
{
	return this->years_since_release;
}


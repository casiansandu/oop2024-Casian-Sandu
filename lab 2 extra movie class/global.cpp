#include "global.h"
#include <cstring>

int movie_compare_name(Movie* mov1, Movie* mov2)
{
	if (strcmp(mov1->get_name(), mov2->get_name()) > 0) return -1;
	else if (strcmp(mov1->get_name(), mov2->get_name()) == 0) return 0;
	else return 1;
}

int movie_compare_year(Movie* mov1, Movie* mov2)
{
	if (mov1->get_year() > mov2->get_year()) return 1;
	else if (mov1->get_year() == mov2->get_year()) return 0;
	else return -1;
}

int movie_compare_score(Movie* mov1, Movie* mov2) 
{
	if (mov1->get_score() > mov2->get_score()) return 1;
	else if (mov1->get_score() == mov2->get_score()) return 0;
	else return -1;
}

int movie_compare_length(Movie* mov1, Movie* mov2)
{
	if (mov1->get_length() > mov2->get_length()) return 1;
	else if (mov1->get_length() == mov2->get_length()) return 0;
	else return -1;
}

int movie_compare_passed_years(Movie* mov1, Movie* mov2)
{
	if (mov1->get_years_since_release() > mov2->get_years_since_release()) return 1;
	else if (mov1->get_years_since_release() == mov2->get_years_since_release()) return 0;
	else return -1;
}


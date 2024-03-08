#pragma once

class Movie
{
private:
	int release_year;
	int length;
	char name[256];
	float score;
	int years_since_release;

public:
	bool set_name(const char new_name[]);
	bool set_score(float new_score);
	bool set_year(int new_year);
	bool set_length(int new_length);
	char* get_name();
	float get_score();
	int get_year();
	int get_length();
	int get_years_since_release();
};


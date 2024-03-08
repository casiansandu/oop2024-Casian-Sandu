#define _CRT_SECURE_NO_WARNINGS
#include "Students.h"

void Students::setName(const char nume[])
{
	strcpy(this->name, nume);
}

char* Students::getName()
{
	return this->name;
}

bool Students::setMathGrade(float grade)
{
	if (grade > 10) return false;
	else
	{
		this->mathGrade = grade;
		return true;
	}
}

bool Students::setEnglishGrade(float grade)
{
	if (grade > 10) return false;
	else
	{
		this->englishGrade = grade;
		return true;
	}
}

bool Students::setHistoryGrade(float grade)
{
	if (grade > 10) return false;
	else
	{
		this->historyGrade = grade;
		return true;
	}
}

float Students::getMathGrade()
{
	if (this->mathGrade)
		return this->mathGrade;
	return 0;
}

float Students::getEnglishGrade()
{
	if (this->englishGrade)
		return this->englishGrade;
	return 0;
}

float Students::getHistoryGrade()
{
	if (this->historyGrade)
		return this->historyGrade;
	return 0;
}

float Students::getAverageGrade()
{
	return (this->mathGrade + this->englishGrade + this->historyGrade) / 3.0f;
}

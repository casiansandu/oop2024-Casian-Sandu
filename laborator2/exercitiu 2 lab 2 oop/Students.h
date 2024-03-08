#pragma once
#include <cstring>

class Students
{
	char name[50];
	float mathGrade;
	float englishGrade;
	float historyGrade;
public:
	char* getName();
	void setName(const char nume[]);

	bool setMathGrade(float grade);
	float getMathGrade();
	bool setEnglishGrade(float grade);
	float getEnglishGrade();
	bool setHistoryGrade(float grade);
	float getHistoryGrade();
	float getAverageGrade();
};


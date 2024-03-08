#include <iostream>
#include "global.h"

using namespace std;

int main()
{
	Students Casian;
	Casian.setName("Sandu Casian");
	Casian.setEnglishGrade(11);

	Casian.setEnglishGrade(9);
	Casian.setHistoryGrade(7);
	Casian.setMathGrade(10);


	Students Matei;
	Matei.setName("Popa Matei");
	Matei.setEnglishGrade(11);

	Matei.setEnglishGrade(10);
	Matei.setHistoryGrade(9);
	Matei.setMathGrade(10);

	cout << cmpAverageGrade(&Casian, &Matei) << '\n';
	cout << cmpName(&Casian, &Matei);


	return 0;
}
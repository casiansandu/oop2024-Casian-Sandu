#include "global.h"

int cmpName(Students* student1, Students* student2)
{
	if (strcmp(student1->getName(), student2->getName()) == 0) return 0;
	else if (strcmp(student1->getName(), student2->getName()) > 0) return 1;
	else return -1;
}

int cmpEngGrade(Students* student1, Students* student2)
{
	if (student1->getEnglishGrade() == student2->getEnglishGrade()) return 0;
	else if (student1->getEnglishGrade() > student2->getEnglishGrade()) return 1;
	else return -1;
}

int cmpMathGrade(Students* student1, Students* student2)
{
	if (student1->getMathGrade() == student2->getMathGrade()) return 0;
	else if (student1->getMathGrade() > student2->getMathGrade()) return 1;
	else return -1;
}

int cmpHistGrade(Students* student1, Students* student2)
{
	if (student1->getHistoryGrade() == student2->getHistoryGrade()) return 0;
	else if (student1->getHistoryGrade() > student2->getHistoryGrade()) return 1;
	else return -1;
}

int cmpAverageGrade(Students* student1, Students* student2)
{
	if (student1->getAverageGrade() == student2->getAverageGrade()) return 0;
	else if (student1->getAverageGrade() > student2->getAverageGrade()) return 1;
	else return -1;
}

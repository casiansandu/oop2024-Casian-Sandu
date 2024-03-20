#include <iostream>
#include "Sort.h"

using namespace std;

int main()
{
	Arr v("3,1,30,40,0,90,7,3");
	v.QuickSort(true);
	v.Print();

	return 0;
}
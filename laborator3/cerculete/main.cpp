#include <iostream>
#include "Canvas.h"

using namespace std;

int main()
{
	Canvas x(150, 150);
	x.DrawLine(0, 0, 40, 40, 'x');
	x.DrawRect(50, 50, 70, 70, 'c');
	x.Print();


	return 0;
}
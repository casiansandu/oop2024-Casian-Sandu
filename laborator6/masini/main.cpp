#include <iostream>
#include "Car.h"
#include "Circuit.h"

using namespace std;

int main()
{
	Circuit c;
	c.setLength(10);
	c.addCar(new BMW());
	c.addCar(new Seat());
	c.addCar(new Volvo());
	c.addCar(new Fiat());
	c.addCar(new BMW());
	c.race();

	c.showFinishers();
	cout << '\n';
	c.showWhoDidNotFinish();

	return 0;
}

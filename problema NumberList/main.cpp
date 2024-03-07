#include <iostream>
#include "NumberList.h"

using namespace std;

int main()
{
	NumberList lista;
	lista.Init();

	for (int i = 0; i < 9; i++)
	{
		lista.Add(-1 * i);
	}

	lista.Add(10);
	lista.Add(11); ///nu il adauga pe 11 deoarece intrece countul de 10

	lista.Print(); ///vector nesortat

	lista.Sort();

	lista.Print(); ///vector sortat
	
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include "Math.h"

int Math::Add(int a, int b)
{
	return a + b;
}

int Math::Add(int a, int b, int c)
{
	return a + b + c;
}

double Math::Add(double a, double b)
{
	return a + b;
}

double Math::Add(double a, double b, double c)
{
	return a + b + c;
}

int Math::Mul(int a, int b)
{
	return a * b;
}

int Math::Mul(int a, int b, int c)
{
	return a * b * c;
}

double Math::Mul(double a, double b)
{
	return a * b;
}

double Math::Mul(double a, double b, double c)
{
	return a * b * c;
}

int Math::Add(int count, ...)
{
	va_list arg;
	va_start(arg, count);

	int suma = 0;

	for (int i = 0; i < count; i++)
		suma += va_arg(arg, int);
	va_end(arg);
	return suma;
}

char* Math::Add(const char* a, const char* b)
{
	int l1, l2, i = 0, nr, t = 0, lgmax;

	if (strlen(a) > strlen(b))
	{
		lgmax = strlen(a) + 1;
	}
	else lgmax = strlen(b) + 1;

	l1 = strlen(a) - 1;
	l2 = strlen(b) - 1;

	char* sol = new char[lgmax + 1];

	while ((l1 - i) >= 0 && (l2 - i) >= 0)
	{
		nr = (a[l1 - i] - '0') + (b[l2 - i] - '0') + t;
		t = nr / 10;
		sol[lgmax - 1 - i] = (nr % 10 + '0');
		i++;
	}

	if (l1 - i == -1)
	{
		while (l2 - i + 1 > 0)
		{
			nr = (b[l2 - i] - '0') + t;
			t = nr / 10;
			sol[lgmax - 1 - i] = (nr % 10 + '0');
			i++;
		}
	}
	else if (l2 - i == -1)
	{
		while (l1 - i + 1 > 0)
		{
			nr = (a[l1 - i] - '0') + t;
			t = nr / 10;
			sol[lgmax - 1 - i] = (nr % 10 + '0');
			i++;
		}
	}

	sol[lgmax] = NULL;

	if (t)
	{
		sol[0] = (t + '0');
		return sol;
	}
	else return (sol + 1);

}

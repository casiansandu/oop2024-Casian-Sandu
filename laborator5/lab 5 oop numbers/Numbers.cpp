#include "Numbers.h"
#include <iostream>

int transformChar(int base, int digits, char* val)
{
	int nr = 0, p = 1;
	if (base <= 10)
	{
		for (int k = digits - 1; k >= 0; k--)
		{
			nr = nr + p * (val[k] - '0');
			p *= base;
		}
	}
	else
	{
		for (int k = digits - 1; k >= 0; k--)
		{
			if (val[k] >= '0' && val[k] <= '9')
				nr = nr + p * (val[k] - '0');
			else nr = nr + p * (10 + (val[k] - 'A'));

			p *= base;
		}
	}
	return nr;
}

char* transformInt(int val)
{
	int nrCifre = 1;
	int aux = val;
	while (aux > 9) nrCifre++, aux /= 10;
	aux = nrCifre;

	char* numar = new char[nrCifre + 1];

	nrCifre--;
	while (nrCifre >= 0) numar[nrCifre] = (val % 10 + '0'), val /= 10, nrCifre--;
	numar[aux] = NULL;
	return numar;
}

Number::Number()
{
	this->base = 10;
	this->value = new char[2];
	this->value[1] = NULL;
	this->value[0] = '0';
	this->digitCount = 1;
}

Number::Number(const char* valoare, int baza)
{
	int nrCifre = 0;
	while (valoare[nrCifre]) nrCifre++;

	this->value = new char[nrCifre + 1];

	for (int k = 0; k < nrCifre; k++) this->value[k] = valoare[k];

	(this->value)[nrCifre] = NULL;
	this->base = baza;
	this->digitCount = nrCifre;
}

Number::Number(int valoare)
{
	int nrCifre = 1;
	int aux = valoare;
	while (aux > 9) nrCifre++, aux /= 10;
	aux = nrCifre;

	this->base = 10;
	this->digitCount = nrCifre;
	this->value = new char[nrCifre + 1];
	
	nrCifre--;
	while (nrCifre >= 0) this->value[nrCifre] = (valoare % 10 + '0'), valoare /= 10, nrCifre--;
	this->value[aux] = NULL;
}

Number::Number(Number& n)
{
	int k = n.GetDigitsCount();
	this->base = n.GetBase();
	this->digitCount = k;
	this->value = new char[k + 1];
	for (int i = 0; i < k; i++) this->value[i] = n.value[i];
	this->value[k] = NULL;
}

void Number::Print()
{
	std::cout << this->value << '\n';
}

int Number::GetBase()
{
	return this->base;
}

int Number::GetDigitsCount()
{
	return this->digitCount;
}

void Number::SwitchBase(int newBase)
{
	int nr = transformChar(this->base, this->digitCount, this->value);
	int nrCifre = 0;

	int t = 1;
	while (t <= nr) t *= newBase, nrCifre++;

	delete[]this->value;
	this->value = new char[nrCifre + 1];
	int valoare;

	for (int k = nrCifre - 1; k >= 0; k--)
	{
		valoare = nr % newBase;

		if (valoare > 9) this->value[k] = ('A' + (valoare - 10));
		else this->value[k] = ('0' + valoare);

		nr /= newBase;
	}
	this->value[nrCifre] = NULL;
	this->digitCount = nrCifre;
	this->base = newBase;
}

char* Number::GetValue()
{
	return this->value;
}

int Number::operator>(Number& n)
{
	int a = transformChar(this->base, this->digitCount, this->value);
	int b = transformChar(n.GetBase(), n.GetDigitsCount(), n.value);
	if (a > b) return 1;
	else return 0;
}

int Number::operator>=(Number& n)
{
	int a = transformChar(this->base, this->digitCount, this->value);
	int b = transformChar(n.GetBase(), n.GetDigitsCount(), n.value);
	if (a >= b) return 1;
	else return 0;
}

int Number::operator<(Number& n)
{
	int a = transformChar(this->base, this->digitCount, this->value);
	int b = transformChar(n.GetBase(), n.GetDigitsCount(), n.value);
	if (a < b) return 1;
	else return 0;
}

int Number::operator<=(Number& n)
{
	int a = transformChar(this->base, this->digitCount, this->value);
	int b = transformChar(n.GetBase(), n.GetDigitsCount(), n.value);
	if (a <= b) return 1;
	else return 0;
}

int Number::operator==(Number& n)
{
	int a = transformChar(this->base, this->digitCount, this->value);
	int b = transformChar(n.GetBase(), n.GetDigitsCount(), n.value);
	if (a == b) return 1;
	else return 0;
}

void Number::operator=(const int val)
{
	int i = 0;
	this->value = transformInt(val);
	for (i = 0; this->value[i]; i++)
	{ }
	this->digitCount = i;
	int aux = this->base;
	this->base = 10;
	this->SwitchBase(aux);
}

void Number::operator=(Number* n)
{
	this->base = n->GetBase();
	this->digitCount = n->GetDigitsCount();
	delete[]this->value;
	this->value = new char[this->digitCount + 1];

	for (int i = 0; i < this->digitCount; i++)
		this->value[i] = n->value[i];

	this->value[this->digitCount] = NULL;
}

void Number::operator=(Number& n)
{
	this->base = n.GetBase();
	this->digitCount = n.GetDigitsCount();
	delete[]this->value;
	this->value = new char[this->digitCount + 1];

	for (int i = 0; i < this->digitCount; i++)
		this->value[i] = n.value[i];

	this->value[this->digitCount] = NULL;
}

Number* operator+(Number& n1, Number& n2)
{
	int a = transformChar(n1.GetBase(), n1.GetDigitsCount(), n1.value);
	int b = transformChar(n2.GetBase(), n2.GetDigitsCount(), n2.value);
	a = a + b;

	char* p = transformInt(a);

	Number* dr = new Number;
	dr->base = 10;
	dr->value = p;

	int i;
	for (i = 0; dr->value[i]; i++)
	{ }
	dr->digitCount = i;

	if (n1.GetBase() > n2.GetBase()) dr->SwitchBase(n1.GetBase()), dr->base = n1.GetBase();
	else dr->SwitchBase(n2.GetBase()), dr->base = n2.GetBase();


	return dr;
}

Number* operator+(Number* n1, Number& n2)
{
	int a = transformChar(n1->GetBase(), n1->GetDigitsCount(), n1->value);
	int b = transformChar(n2.GetBase(), n2.GetDigitsCount(), n2.value);
	a = a + b;

	char* p = transformInt(a);

	Number* dr = new Number;
	dr->base = 10;
	dr->value = p;

	int i;
	for (i = 0; dr->value[i]; i++)
	{
	}
	dr->digitCount = i;

	if (n1->GetBase() > n2.GetBase()) dr->SwitchBase(n1->GetBase()), dr->base = n1->GetBase();
	else dr->SwitchBase(n2.GetBase()), dr->base = n2.GetBase();


	return dr;
}

Number* operator+(Number& n1, Number* n2)
{
	int a = transformChar(n1.GetBase(), n1.GetDigitsCount(), n1.value);
	int b = transformChar(n2->GetBase(), n2->GetDigitsCount(), n2->value);
	a = a + b;

	char* p = transformInt(a);

	Number* dr = new Number;
	dr->base = 10;
	dr->value = p;

	int i;
	for (i = 0; dr->value[i]; i++)
	{ }
	dr->digitCount = i;

	if (n1.GetBase() > n2->GetBase()) dr->SwitchBase(n1.GetBase()), dr->base = n1.GetBase();
	else dr->SwitchBase(n2->GetBase()), dr->base = n2->GetBase();


	return dr;
}

Number* operator-(Number& n1, Number& n2)
{
	int a = transformChar(n1.GetBase(), n1.GetDigitsCount(), n1.value);
	int b = transformChar(n2.GetBase(), n2.GetDigitsCount(), n2.value);
	a = a - b;

	if (a >= 0)
	{
		char* p = transformInt(a);

		Number* dr = new Number;
		dr->base = 10;
		dr->value = p;

		int i;
		for (i = 0; dr->value[i]; i++)
		{ }
		dr->digitCount = i;

		if (n1.GetBase() > n2.GetBase()) dr->SwitchBase(n1.GetBase()), dr->base = n1.GetBase();
		else dr->SwitchBase(n2.GetBase()), dr->base = n2.GetBase();


		return dr;
	}
}

Number* operator-(Number* n1, Number& n2)
{
	int a = transformChar(n1->GetBase(), n1->GetDigitsCount(), n1->value);
	int b = transformChar(n2.GetBase(), n2.GetDigitsCount(), n2.value);
	a = a - b;

	if (a >= 0)
	{
		char* p = transformInt(a);

		Number* dr = new Number;
		dr->base = 10;
		dr->value = p;

		int i;
		for (i = 0; dr->value[i]; i++)
		{ }
		dr->digitCount = i;

		if (n1->GetBase() > n2.GetBase()) dr->SwitchBase(n1->GetBase()), dr->base = n1->GetBase();
		else dr->SwitchBase(n2.GetBase()), dr->base = n2.GetBase();


		return dr;
	}
}

Number* operator-(Number& n1, Number* n2)
{
	int a = transformChar(n1.GetBase(), n1.GetDigitsCount(), n1.value);
	int b = transformChar(n2->GetBase(), n2->GetDigitsCount(), n2->value);
	a = a - b;

	if (a >= 0)
	{
		char* p = transformInt(a);

		Number* dr = new Number;
		dr->base = 10;
		dr->value = p;

		int i;
		for (i = 0; dr->value[i]; i++)
		{ }
		dr->digitCount = i;

		if (n1.GetBase() > n2->GetBase()) dr->SwitchBase(n1.GetBase()), dr->base = n1.GetBase();
		else dr->SwitchBase(n2->GetBase()), dr->base = n2->GetBase();


		return dr;
	}
}

void operator+=(Number& n1, Number& n2)
{
	n1 = n1 + n2;
}

void operator-=(Number& n1, Number& n2)
{
	n1 = n1 - n2;
}

void Number::operator--()
{
	int k = this->digitCount;
	char* p = new char[k];
	for (int i = 0; i < k - 1; i++) p[i] = this->value[i];
	p[k - 1] = NULL;
	delete[]this->value;
	this->value = p;
}

void Number::operator--(int val)
{
	char* p = new char[this->digitCount];
	memcpy(p, this->value + 1, digitCount);
	delete[]this->value;
	this->value = p;
	this->digitCount--;
}

void Number::operator=(const char* s)
{
	int i = 0;
	for (i = 0; s[i]; i++)
	{ }
	char* p = new char[i + 1];
	delete[]this->value;
	memcpy(p, s, i);
	this->value = p;
	this->value[i] = NULL;
	this->digitCount = i;

	int aux = this->base;
	this->base = 10;
	this->SwitchBase(aux);
}


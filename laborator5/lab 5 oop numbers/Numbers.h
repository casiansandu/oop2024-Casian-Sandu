#pragma once

class Number
{
private:
	int base;
	int digitCount;
	char* value;
public:
	Number(const char* valoare, int baza);
	Number(int valoare);
	Number();
	Number(Number& n);

	~Number() { delete[] value; };

	int operator>(Number& n);
	int operator>=(Number& n);
	int operator<(Number& n);
	int operator<=(Number& n);	
	int operator==(Number& n);
	void operator=(const int val);
	void operator=(Number& n);
	void operator=(Number* n);
	void operator=(const char* s);
	friend Number* operator+(Number& n1, Number& n2);
	friend Number* operator+(Number* n1, Number& n2);
	friend Number* operator+(Number& n1, Number* n2);
	friend Number* operator-(Number& n1, Number& n2);
	friend Number* operator-(Number* n1, Number& n2);
	friend Number* operator-(Number& n1, Number* n2);
	friend void operator+=(Number& n1, Number& n2);
	friend void operator-=(Number& n1, Number& n2);
	void operator--();
	void operator--(int val);


	void SwitchBase(int newBase);
	void Print();
	char* GetValue();
	int  GetDigitsCount();
	int  GetBase();
};

int transformChar(int base, int digits, char *val);

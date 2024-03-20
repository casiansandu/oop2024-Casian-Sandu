#include "Sort.h"
#include "time.h"
#include <stdlib.h>
#include <iostream>

Arr::Arr(int nr_elem, int min, int max)
{
	this->nr_elemente = nr_elem;
	this->vector = new int[nr_elem];
	time_t t;
	srand((unsigned)time(&t));
	for (int i = 0; i < nr_elem; i++)
		vector[i] = min + rand() % (min - max + 1);
}

Arr::Arr() : vector(new int[6] {1, 2, 3, 4, 5, 6}) 
{
	this->nr_elemente = 6;
}

Arr::Arr(int count, ...)
{
	this->nr_elemente = count;
	this->vector = new int[count];
	va_list arg;
	va_start(arg, count);

	for (int i = 0; i < count; i++)
		this->vector[i] = va_arg(arg, int);
	va_end(arg);
}

Arr::Arr(const char a[])
{
	int count = 0;
	for (int i = 0; a[i]; i++)
	{
		if (a[i] == ',')
			count++;
	}

	this->nr_elemente = count + 1;
	this->vector = new int[count + 1];

	int nr = 0, k = 0;

	for (int i = 0; a[i]; i++)
	{
		if (a[i] != ',')
		{
			nr = nr * 10 + (a[i] - '0');
		}
		else
		{
			this->vector[k] = nr;
			k++;
			nr = 0;
		}
	}
	this->vector[k] = nr;

}

void Arr::Print()
{
	for (int i = 0; i < this->GetElementsCount(); i++)
		std::cout << this->vector[i] << ' ';
}

int Arr::GetElementsCount()
{
	return this->nr_elemente;
}

int Arr::GetElementFromIndex(int index)
{
	if (index < this->nr_elemente)
		return this->vector[index];
	else return false;
}

void Arr::BubbleSort(bool ascendent)
{
	int aux;
	if (ascendent == true)
	{
		for (int i = 0; i < this->GetElementsCount() - 1; i++)
		{
			for (int j = i + 1; j < this->GetElementsCount(); j++)
			{
				if (this->vector[i] > this->vector[j])
				{
					aux = this->vector[i];
					this->vector[i] = this->vector[j];
					this->vector[j] = aux;
				}
			}
		}
	}
	else
	{
		for (int i = 0; i < this->GetElementsCount() - 1; i++)
		{
			for (int j = i + 1; j < this->GetElementsCount(); j++)
			{
				if (this->vector[i] < this->vector[j])
				{
					aux = this->vector[i];
					this->vector[i] = this->vector[j];
					this->vector[j] = aux;
				}
			}
		}
	}
}

void Arr::InsertSort(bool ascendent)
{
	int j, aux;
	if (ascendent == true)
	{
		for (int i = 0; i < this->nr_elemente; i++)
		{
			j = i;
			while (j && this->vector[j - 1] > this->vector[j])
			{
				aux = this->vector[j - 1];
				this->vector[j - 1] = this->vector[j];
				this->vector[j] = aux;
				j--;
			}
		}
	}
	else
	{
		for (int i = 0; i < this->nr_elemente; i++)
		{
			j = i;
			while (j && this->vector[j - 1] < this->vector[j])
			{
				aux = this->vector[j - 1];
				this->vector[j - 1] = this->vector[j];
				this->vector[j] = aux;
				j--;
			}
		}
	}
}


int Arr::partition(int* arr, int st, int dr, bool tip)
{
	int pivot = arr[st];

	int count = 0;
	if (tip == true)
		for (int i = st + 1; i <= dr; i++) 
		{
			if (arr[i] <= pivot)
				count++;
		}
	else
		for (int i = st + 1; i <= dr; i++)
		{
			if (arr[i] >= pivot)
				count++;
		}

	int pivotIndex = st + count;
	int aux;
	aux = arr[pivotIndex];
	arr[pivotIndex] = arr[st];
	arr[st] = aux;

	int i = st, j = dr;
	
	if (tip == true)
	{
		while (i < pivotIndex && j > pivotIndex)
		{
			while (arr[i] <= pivot)
			{
				i++;
			}

			while (arr[j] > pivot)
			{
				j--;
			}

			if (i < pivotIndex && j > pivotIndex)
			{
				aux = arr[i];
				arr[i] = arr[j];
				arr[j] = aux;
				i++;
				j--;
			}
		}
	}
	else
	{
		while (i < pivotIndex && j > pivotIndex)
		{
			while (arr[i] >= pivot)
			{
				i++;
			}

			while (arr[j] < pivot)
			{
				j--;
			}

			if (i < pivotIndex && j > pivotIndex)
			{
				aux = arr[i];
				arr[i] = arr[j];
				arr[j] = aux;
				i++;
				j--;
			}
		}
	}

	return pivotIndex;
}

void Arr::quickk(int* arr, int st, int dr, bool tip)
{
	if (st >= dr)
		return;

	int p = this->partition(arr, st, dr, tip);

	quickk(arr, st, p - 1, tip);

	quickk(arr, p + 1, dr, tip);
}

void Arr::QuickSort(bool ascendent)
{
	this->quickk(this->vector, 0, this->GetElementsCount() - 1, ascendent);
}
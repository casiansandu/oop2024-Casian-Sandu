#pragma once
#include <cstdarg>

class Arr
{
	int* vector;
    int nr_elemente;
    int partition(int *arr, int st, int dr, bool tip);
    void quickk(int *arr, int st, int dr, bool tip);
public:
    Arr(int nr_elem, int min, int max);
    Arr(int count, ...);
    Arr(const char a[]);
    Arr();
    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int GetElementsCount();
    int GetElementFromIndex(int index);
};



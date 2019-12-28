#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "utils.h"

void fill(int ar[], int size, int a, int b)
{
    for (int i = 0; i < size; ++i)
        ar[i] = a + rand() % (b - a + 1);
}

void print(const int a[], int size, int w)
{
    for (int i = 0; i < size; ++i)
        std::cout << std::setw(w) << a[i];
}

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

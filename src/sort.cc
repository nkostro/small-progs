/* Sort array in either decreasing or increasing order.
 * Educational program.
 *
 * @author Nikolai Kostromitin
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

void fill(int ar[], int size, int a, int b);
void sort(int ar[], int size, bool is_decreasing);
void print(const int a[], int size, int width);

int main()
{
    const int size = 10;
    int a[size];

    fill(a, size, -100, 201);

    const int width = 5;
    std::cout << "Before sort: ";
    print(a, size, width);
    std::cout << std::endl;

    bool is_decreasing = true;
    if (is_decreasing)
        std::cout << "... sorting in decreasing order\n";
    else
        std::cout << "... sorting in increasing order\n";
    sort(a, size, is_decreasing);

    std::cout << "After sort: ";
    print(a, size, width);
    std::cout << std::endl;
}

void fill(int ar[], int size, int a, int b)
{
    srand(time(NULL));
    for (int i = 0; i < size; ++i)
        ar[i] = rand() % b + a;
}

void swap(int *a, int *b) { int t = *a; *a = *b; *b = t; }

typedef bool (*cmp_t)(int, int);

void sort(int a[], int size, cmp_t cmp)
{
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size - i - 1; ++j)
            if (cmp(a[j], a[j+1]))
                swap(&a[j], &a[j+1]);
}

bool cmp_lt(int a, int b) { return a < b; }

bool cmp_gt(int a, int b) { return a > b; }

void sort(int a[], int size, bool is_decreasing)
{
    if (is_decreasing)
        sort(a, size, [] (int a, int b) { return a < b; });
    else
        sort(a, size, [] (int a, int b) { return a > b; });
}

void print(const int a[], int size, int w)
{
    for (int i = 0; i < size; ++i)
        std::cout << std::setw(w) << a[i];
}

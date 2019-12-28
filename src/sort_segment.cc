/* Sort array segment between first and last negative elements.
 * Educational program.
 *
 * @author Nikolai Kostromitin
 */

#include <iostream>
#include <iomanip>

void fill(int ar[], int size, int a, int b);
void sort(int a[], int size);
void print(const int a[], int size, int width);

int main()
{
    const int size = 10;
    int a[size];

    srand(time(NULL));
    fill(a, size, -100, 100);

    const int width = 5;
    std::cout << "Before sort: ";
    print(a, size, width);
    std::cout << std::endl;

    sort(a, size);

    std::cout << "After sort: ";
    print(a, size, width);
    std::cout << std::endl;
}

void fill(int ar[], int size, int a, int b)
{
    for (int i = 0; i < size; ++i)
        ar[i] = rand() % (b - a + 1) + a;
}

void swap(int *a, int *b) { int t = *a; *a = *b; *b = t; }

void sort(int a[], int begin, int end)
{
    for (int i = begin + 1; i < end; ++i)
        for (int j = i; j > begin && a[j] < a[j-1]; --j)
            swap(&a[j], &a[j-1]);
}

void sort(int a[], int size)
{
    int begin;
    for (begin = 0; a[begin] >= 0; ++begin)
        ;
    int end;
    for (end = size - 1; a[end] >= 0; --end)
        ;
    sort(a, begin + 1, end);
}

void print(const int a[], int size, int w)
{
    for (int i = 0; i < size; ++i)
        std::cout << std::setw(w) << a[i];
}

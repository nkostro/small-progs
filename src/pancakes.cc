/* Weird pancakes' array sorting algorithm.
 * The only operation allowed with pancakes array is reverting order of pancakes starting from any index to the end of array.
 *
 * @author Nikolai Kostromitin
 */

#include <iostream>
#include <iomanip>
#include <ctime>

#include "utils.h"

void sort(int a[], int size);

int main()
{
    const int size = 10;
    int pancakes_sizes[size];

    srand(time(NULL));
    fill(pancakes_sizes, size, -100, 100);

    const int width = 4;
    std::cout << "Before sort: ";
    print(pancakes_sizes, size, width);
    std::cout << std::endl;

    sort(pancakes_sizes, size);

    std::cout << "After sort:  ";
    print(pancakes_sizes, size, width);
    std::cout << std::endl;
}

int get_max_index(const int a[], int size)
{
    int max = a[0];
    int max_idx = 0;

    for (int i = 1; i < size; ++i)
        if (a[i] > max) {
            max = a[i];
            max_idx = i;
        }

    return max_idx;
}

void sort(int a[], int size)
{
    for (int i = 0; i < size; ++i) {
        int max_idx = i + get_max_index(a+i, size-i);
        for (int j = max_idx, k = size-1; j < k; ++j, --k)
            swap(&a[j], &a[k]);
        for (int j = i, k = size-1; j < k; ++j, --k)
            swap(&a[j], &a[k]);
    }
}

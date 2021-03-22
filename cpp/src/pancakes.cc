/* Weird pancakes' array sorting algorithm.
 * The only operation allowed with array is reverting order of elements
 * starting from any index to the end of array.
 *
 * @author Nikolai Kostromitin
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

void initArray(int array[], int size, int beginValue, int endValue);
void printArray(const int array[], int size);
void pancakesSort(int pancakes[], int size);


int main()
{
    setlocale(LC_ALL, "ru_RU");
    srand(time(NULL));

    const int size = 20;
    int pancakes[size];

    initArray(pancakes, size, 0, 100);

    std::cout << "Before sort: ";
    printArray(pancakes, size);
    std::cout << '\n';

    pancakesSort(pancakes, size);

    std::cout << "After sort:  ";
    printArray(pancakes, size);
    std::cout << '\n';
}

void initArray(int array[], int size, int beginValue, int endValue)
{
    for (int i = 0; i < size; ++i)
        array[i] = beginValue + rand() % (endValue - beginValue);
}

void printArray(const int array[], int size)
{
    if (size < 1)
        return;

    std::cout << array[0];
    for (int i = 1; i < size; ++i)
        std::cout << ' ' << array[i];
}

int getIndexOfMax(const int array[], int startIndex, int endIndex)
{
    if (startIndex < 0 || endIndex < startIndex)
        return -1;

    int max = array[startIndex];
    int index = startIndex;

    for (int i = startIndex + 1; i < endIndex; ++i) {
        if (array[i] > max) {
            max = array[i];
            index = i;
        }
    }

    return index;
}

void flipPancakes(int pancakes[], int startIndex, int endIndex)
{
    for (int i = startIndex, j = endIndex - 1; i < j; ++i, --j) {
        int temp = pancakes[i];
        pancakes[i] = pancakes[j];
        pancakes[j] = temp;
    }
}

void pancakesSort(int pancakes[], int size)
{
    for (int i = 0; i < size; ++i) {
        int indexOfMax = getIndexOfMax(pancakes, i, size);
        flipPancakes(pancakes, indexOfMax, size);
        flipPancakes(pancakes, i, size);
    }
}


//  +--*--+
//  | *|* |
//  |* | *|
//  *--+--*
//  |* | *|
//  | *|* |
//  +--*--+

#include <iostream>


void paint_diamond(int side);


int main()
{
    paint_diamond(11);
}


void paint_diamond(int side)
{
    const int middle = side / 2;
    const char star = '*';
    const char blank = ' ';

    for (int i = 0; i < middle; ++i) {
        for (int j = middle; j >= 0; --j)
            if (i == j)
                std::cout << star;
            else
                std::cout << blank;

        for (int j = middle+1; j < side; ++j)
            if (i + middle == j)
                std::cout << star;
            else
                std::cout << blank;

        std::cout << std::endl;
    }

    for (int i = 0; i < side; ++i) {
        for (int j = 0; j < middle+1; ++j)
            if (i == j)
                std::cout << star;
            else
                std::cout << blank;

        for (int j = side-1; j > middle; --j)
            if (i + middle + 1 == j)
                std::cout << star;
            else
                std::cout << blank;

        std::cout << std::endl;
    }
}

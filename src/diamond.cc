/* Draws diamond with given side to the stdout.
 *
 * @author Nikolai Kostromitin
 */

#include <iostream>

void draw_diamond(unsigned side);


int main()
{
    unsigned side;
    std::cin >> side;
    if (side % 2 == 0)
        ++side;

    draw_diamond(side);
}

// side == 9
//
//     *
//    * *
//   *   *
//  *     *
// *       *
//  *     *
//   *   *
//    * *
//     *

void draw_diamond(unsigned side)
{
    const unsigned middle = side / 2;
    const char star = '*';
    const char blank = ' ';

    for (unsigned i = 0; i < side; ++i) {
        for (unsigned j = 0; j < side; ++j) {
            if (i + j == middle || i + j == side - 1 + middle)
                std::cout << star;
            else if (i + middle == j || i == j + middle)
                std::cout << star;
            else
                std::cout << blank;
        }
        std::cout << std::endl;
    }
}

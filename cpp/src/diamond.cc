/* Draws diamond with given width to the stdout.
 *
 * @author Nikolai Kostromitin
 */

#include <iostream>

void draw_diamond(unsigned width);


int main()
{
    unsigned width;
    std::cout << "Input diamond's width: ";
    std::cin >> width;
    if (width % 2 == 0)
        ++width;

    draw_diamond(width);
}

// width == 9
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

void draw_diamond(unsigned width)
{
    const unsigned middle = width / 2;
    const char star = '*';
    const char blank = ' ';

    for (unsigned i = 0; i < width; ++i) {
        for (unsigned j = 0; j < width; ++j) {
            if (i + j == middle || i + j == width - 1 + middle)
                std::cout << star;
            else if (i + middle == j || i == j + middle)
                std::cout << star;
            else
                std::cout << blank;
        }
        std::cout << std::endl;
    }
}

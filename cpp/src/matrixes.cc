/* Calculate production of 2 matrixes
 * (made for educational purposes).
 *
 * @author Nikolai Kostromitin
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>


int main()
{
    const int nrows = 4;
    const int ncols = 4;

    srand(time(NULL));

    int matrix_A[nrows][ncols];
    int matrix_B[nrows][ncols];

    const int a = 0;
    const int b = 10;

    // initialize matrixes
    for (int i = 0; i < nrows; ++i)
        for (int j = 0; j < ncols; ++j)
            matrix_A[i][j] = a + rand() % (b-a+1);

    for (int i = 0; i < nrows; ++i)
        for (int j = 0; j < ncols; ++j)
            matrix_B[i][j] = a + rand() % (b-a+1);

    // calculate matrixes' production
    int matrix_C[nrows][ncols] = {};

    for (int row = 0; row < nrows; ++row)
        for (int col = 0; col < ncols; ++col)
            for (int k = 0; k < nrows; ++k)
                matrix_C[row][col] += matrix_A[row][k] *
                                      matrix_B[k][col];

    const int field_width = 4;
    // print header
    std::cout << "A" << std::setw(field_width * ncols) << ' ' << "\tB";
    std::cout << std::setw(field_width * ncols) << ' ' << "\tC\n";

    // print matrixes and their product to stdout
    for (int i = 0; i < nrows; ++i) {
        for (int j = 0; j < ncols; ++j)
            std::cout << std::setw(field_width) << matrix_A[i][j];
        std::cout << '\t';

        for (int j = 0; j < ncols; ++j)
            std::cout << std::setw(field_width) << matrix_B[i][j];
        std::cout << '\t';

        for (int j = 0; j < ncols; ++j)
            std::cout << std::setw(field_width) << matrix_C[i][j];
        std::cout << std::endl;
    }
}

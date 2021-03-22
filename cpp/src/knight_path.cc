#include <iostream>
#include <cctype>

#define BOARD_SIZE 8

typedef bool board_t [BOARD_SIZE][BOARD_SIZE];
typedef int path_t [BOARD_SIZE*BOARD_SIZE][2];

bool is_valid_cell(int x, int y);
bool get_path(board_t board, int x, int y, int number_of_moves, path_t path);
void print_path(path_t path);


int main()
{
    board_t board = {};
    int x_pos, y_pos;

    std::cout << "Enter coordinate of knight's position (A1-H" << BOARD_SIZE << "): ";
    x_pos = std::toupper(std::cin.get()) - 'A';
    std::cin >> y_pos;

    if (!is_valid_cell(x_pos, y_pos - 1))
        return 1;

    path_t path = {};
    get_path(board, x_pos, y_pos - 1, 1, path);

    std::cout << std::endl;
    print_path(path);
}


bool get_path(board_t board, int x, int y, int nmoves, path_t path)
{
    static int offsets[][2] = {
        { 1,  2}, { 2,  1}, { 2, -1}, { 1, -2},
        {-1, -2}, {-2, -1}, {-2,  1}, {-1,  2},
    };

    board[x][y] = true;

    if (nmoves == BOARD_SIZE*BOARD_SIZE) {
        path[nmoves-1][0] = x;
        path[nmoves-1][1] = y;
        return true;
    }

    for (int i = 0; i < 8; ++i) {
        int next_x = x + offsets[i][0];
        int next_y = y + offsets[i][1];
        if (is_valid_cell(next_x, next_y) && !board[next_x][next_y]) {
            if (get_path(board, next_x, next_y, nmoves+1, path)) {
                path[nmoves-1][0] = x;
                path[nmoves-1][1] = y;
                return true;
            }
        }
    }

    board[x][y] = false;

    return false;
}


bool is_valid_cell(int x, int y)
{
    return x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE;
}


void print_path(path_t path)
{
    for (unsigned i = 0; i < BOARD_SIZE*BOARD_SIZE; ++i) {
        std::cout << (char)(path[i][0] + 'A') << path[i][1] + 1;
        std::cout << (i != 0 && (i+1) % BOARD_SIZE == 0 ? '\n' : ' ');
    }
    std::cout << std::endl;
}

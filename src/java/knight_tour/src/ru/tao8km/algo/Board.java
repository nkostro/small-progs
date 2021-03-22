package ru.tao8km.algo;

import java.util.Arrays;

class Board {
    private final int side;
    private final Cell[][] board;

    public Board(int side) {
        this.side = side;

        board = new Cell[side][side];
        for (int i = 0; i < side; ++i) {
            for (int j = 0; j < side; ++j) {
                board[i][j] = new Cell((char) ('A' + j), 1 + i);
            }
        }
    }

    public int getSide() {
        return side;
    }

    public int getTotalCells() {
        return side * side;
    }

    public Cell getCell(int row, int col) {
        return board[row][col];
    }

    public Cell getCell(char letter, int digit) {
        return getCell(digit - 1, letter - 'A');
    }

    @Override
    public String toString() {
        return Arrays.deepToString(board);
    }
}


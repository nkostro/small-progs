package ru.yandex.emailbin.algo;

import java.io.PrintWriter;
import java.util.Arrays;

class KnightTour {
    private final Cell[] tour;

    public KnightTour(int length) {
        tour = new Cell[length];
    }

    @Override
    public String toString() {
        return Arrays.toString(tour);
    }

    public void setCell(Cell cell, int pos) {
        tour[pos] = cell;
    }
}


package ru.tao8km.algo;

class Cell {
    private final char letter;
    private final int digit;
    private int rank;
    private boolean isVisited = false;

    public Cell(char letter, int digit) {
        this.letter = letter;
        this.digit = digit;
    }

    public char getLetter() {
        return letter;
    }

    public int getDigit() {
        return digit;
    }

    public int getRank() {
        return rank;
    }

    public void setRank(int rank) {
        this.rank = rank;
    }

    public boolean isVisited() {
        return isVisited;
    }

    public void isVisited(boolean isVisited) {
        this.isVisited = isVisited;
    }

    public void decrementRank() {
        --rank;
    }

    public void incrementRank() {
        ++rank;
    }

    @Override
    public String toString() {
        return String.format("%c%d", letter, digit);
    }

    public static boolean isValidCell(char letter, int digit, int side) {
        return letter >= 'A' && letter < 'A' + side &&
               digit >= 1 && digit < 1 + side;
    }
}

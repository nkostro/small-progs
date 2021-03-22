package ru.tao8km.game.flood_it;

import java.util.Arrays;
import java.util.Random;

public class Board {
    private final int rows;
    private final int cols;
    private final Color[] colorValues;
    private final Cell[][] board;

    public Board(int rows, int cols) {
        this.rows = rows;
        this.cols = cols;
        colorValues = Color.values();
        board = new Cell[rows][cols];
        fillBoard();
    }

    /**
     * Flood board with given color starting from top left cell.
     *
     * @return true - if board is flooded with single color; false - otherwise
     */
    public boolean flood(Color color) {
        Color topLeft = board[0][0].getColor();
        if (topLeft == color) {
            return false;
        }

        floodRecursively(topLeft, color, 0, 0);
        return isBoardSingleColored();
    }

    private void floodRecursively(Color oldColor, Color newColor, int i, int j) {
        board[i][j].setColor(newColor);
        if (i < rows - 1 && board[i + 1][j].getColor() == oldColor)
            floodRecursively(oldColor, newColor, i + 1, j);
        if (i > 0 && board[i - 1][j].getColor() == oldColor)
            floodRecursively(oldColor, newColor, i - 1, j);
        if (j < cols - 1 && board[i][j + 1].getColor() == oldColor)
            floodRecursively(oldColor, newColor, i, j + 1);
        if (j > 0 && board[i][j - 1].getColor() == oldColor)
            floodRecursively(oldColor, newColor, i, j - 1);
    }

    private boolean isBoardSingleColored() {
        Color firstColor = board[0][0].getColor();

        for (Cell[] row : board) {
            for (Cell cell : row) {
                if (cell.getColor() != firstColor) {
                    return false;
                }
            }
        }

        return true;
    }

    public Color getColor(int index) {
        return colorValues[index];
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();

        for (Cell[] row : board) {
            sb.append(Arrays.toString(row)).append('\n');
        }

        return sb.toString();
    }

    private void fillBoard() {
        Random rand = new Random();

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                int index = rand.nextInt();
                if (index < 0) {
                    index *= -1;
                }
                index = index % colorValues.length;

                board[i][j] = new Cell(colorValues[index]);
            }
        }
    }
}

class Cell {
    private Color color;

    public Cell(Color color) {
        this.color = color;
    }

    public void setColor(Color color) {
        this.color = color;
    }

    public Color getColor() {
        return color;
    }

    @Override
    public String toString() {
        return color.toString();
    }
}

enum Color {
    WHITE('W'), RED('R'), GREEN('G'), BLUE('B'), YELLOW('Y'), CYAN('C');

    final char color;
    static final String ALL_VALUES = "WRGBYC";

    Color(char color) {
        this.color = color;
    }

    @Override
    public String toString() {
        return String.valueOf(color);
    }
}

/**
 * Knight's tour solving algorithm using Warnsdorff's rule.
 *
 * Limitations: chess board must be square and has side greater than 5.
 *
 * @author Nikolai Kostromitin
 */
package ru.tao8km.algo;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class KnightTourSolver {
    private final int side;
    private final Board board;
    private final KnightTour tour;
    private final byte[][] ranks;
    private static final byte[][] RANKS_MATRIX_CORNER = {
        {2, 3, 4},
        {3, 4, 6},
        {4, 6, 8}
    };
    private static final int[][] KNIGHT_OFFSETS = {
        { -2, +1 }, { -1, +2 }, { +1, +2 }, { +2, +1 },
        { +2, -1 }, { +1, -2 }, { -1, -2 }, { -2, -1 }
    };

    public KnightTourSolver(int side) {
        this.side = side;
        board = new Board(side);
        tour = new KnightTour(side * side);
        ranks = new byte[side][side];

        fillRanks(side);
        for (int i = 0; i < ranks.length; ++i) {
            for (int j = 0; j < ranks[i].length; ++j) {
                int rank = ranks[i][j];
                board.getCell(i, j).setRank(rank);
            }
        }
    }

    public KnightTour findTour(char letter, int digit) {
        Cell fromCell = board.getCell(letter, digit);
        findTourRecursively(fromCell, 1);
        return tour;
    }

    private boolean findTourRecursively(Cell currentCell, int moveNumber) {
        currentCell.isVisited(true);
        currentCell.decrementRank();

        if (moveNumber == board.getTotalCells()) {
            tour.setCell(currentCell, moveNumber - 1);
            return true;
        }

        List<Cell> nextCells = new ArrayList<>();
        for (int[] offset : KNIGHT_OFFSETS) {
            char nextLetter = (char) (currentCell.getLetter() + offset[0]);
            int nextDigit = currentCell.getDigit() + offset[1];
            if (Cell.isValidCell(nextLetter, nextDigit, side)) {
                Cell cell = board.getCell(nextLetter, nextDigit);
                if (!cell.isVisited()) {
                    nextCells.add(cell);
                }
            }
        }

        Collections.sort(nextCells, (Cell left, Cell right) -> {
            return left.getRank() - right.getRank();
        });
        for (Cell nextCell : nextCells) {
            if (findTourRecursively(nextCell, moveNumber + 1)) {
                tour.setCell(currentCell, moveNumber - 1);
                return true;
            }
        }

        currentCell.isVisited(false);
        currentCell.incrementRank();
        return false;
    }

    private void fillRanks(int side) {
        for (int t = 0; t < 4; ++t) {
            fillCorner(side);
            Matrices.rotate(ranks);
        }
    }

    private void fillCorner(int side) {
        for (int i = 0; i < side / 2; ++i) {
            for (int j = 0; j < side / 2; ++j) {
                if (i < RANKS_MATRIX_CORNER.length) {
                    if (j < RANKS_MATRIX_CORNER[i].length)
                        ranks[i][j] = RANKS_MATRIX_CORNER[i][j];
                    else
                        ranks[i][j] = ranks[i][j-1]; // spread last column right
                } else {
                    ranks[i][j] = ranks[i-1][j]; // spread last row down
                }
            }
        }
    }

    public static void main(String[] args) {
        if (args.length < 3)
            throw new IllegalArgumentException("Provide arguments: side start_letter start_digit");
        int side = Integer.parseInt(args[0]);
        char letter = args[1].charAt(0);
        int digit = Integer.parseInt(args[2]);
        KnightTourSolver solver = new KnightTourSolver(side);
        KnightTour tour = solver.findTour(letter, digit);
        System.out.println(tour);
    }
}

package ru.tao8km.game.flood_it;

import java.util.Scanner;

public class FloodIt {
    private final Board board;
    private final Scanner scanner = new Scanner(System.in);

    public FloodIt(int rows, int cols) {
        board = new Board(rows, cols);
    }

    public boolean play(int maxMovesNumber) {
        printMessage("Welcome to the game.\n");

        for (int i = 0; i < maxMovesNumber; ++i) {
            printMessage(String.format("Move: %d/%d\n", i + 1, maxMovesNumber));
            printMessage("Colors: 1 - white, 2 - red, 3 - green, 4 - blue, 5 - yellow, 6 - cyan.");
            printMessage(board.toString());

            Color color = getColorFromPlayer();
            if (board.flood(color)) {
                printMessage(board.toString());
                printMessage("Win!");
                return true;
            }
            printMessage("\033[H\033[2J"); // ANSI escape code for clearing the console
        }

        printMessage("Game over.");
        return false;
    }

    private Color getColorFromPlayer() {
        int colorCode;
        do {
            printMessage("Enter color: ");
            try {
                colorCode = getColor();
            } catch (NumberFormatException e) {
                printMessage(e.getMessage());
                colorCode = 0;
            }
        } while (colorCode < 1 || colorCode > 6);

        return board.getColor(colorCode - 1);
    }

    private void printMessage(String message) {
        System.out.println(message);
        System.out.flush();
    }

    private int getColor() {
        return Integer.parseInt(scanner.nextLine());
    }

    public static void main(String[] args) {
        // TODO get settings from args
        FloodIt game = new FloodIt(5, 5);
        game.play(50);
    }
}

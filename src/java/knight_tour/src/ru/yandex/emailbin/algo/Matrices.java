/**
 * Matrices related methods.
 *
 * @author Nikolai Kostromitin
 */
package ru.yandex.emailbin.algo;

public class Matrices {
    /**
     * Rotate matrix clockwise by 90 degrees.
     */
    public static void rotate(byte[][] matrix) {
        transpose(matrix);
        for (int i = 0; i < matrix.length; ++i) {
            reverse(matrix[i]);
        }
    }

    public static void transpose(byte[][] matrix) {
        int side = matrix.length;
        for (int i = 0; i < side-1; ++i) {
            for (int j = i+1; j < side; ++j) {
                byte temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
    }

    public static void reverse(byte[] array) {
        for (int i = 0, j = array.length - 1; i < j; ++i, --j) {
            byte temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
}


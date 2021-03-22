/**
 * Weird sorting algorithm with only one operation allowed - reverse order of a part of array
 * till the end of it.
 *
 * Imagine that these are pancakes of different diameters in an array.
 */
package ru.tao8km.algo;

import java.util.Arrays;
import java.util.Random;

public class PancakesSort {
    public static void main(String[] args) {
        final int size = 15;
        int[] numbers = new int[size];

        fillArray(numbers, 0, 100);
        System.out.println("Before sort: " + Arrays.toString(numbers));
        sort(numbers);
        System.out.println("After sort:  " + Arrays.toString(numbers));
    }

    /**
     * Sort pancakes in decreasing order.
     */
    public static void sort(int[] pancakes) {
        for (int i = 0; i < pancakes.length; ++i) {
            int indexOfMax = getIndexOfMaxValue(pancakes, i, pancakes.length);
            flipPancakes(pancakes, indexOfMax, pancakes.length);
            flipPancakes(pancakes, i, pancakes.length);
        }
    }

    /**
     * Fill array with random nonnegative values from range [lowerBound; upperBound).
     */
    private static void fillArray(int[] numbers, int lowerBound, int upperBound) {
        Random rand = new Random();
        for (int i = 0; i < numbers.length; ++i) {
            numbers[i] = lowerBound + rand.nextInt() % (upperBound - lowerBound);
            if (numbers[i] < 0) {
                numbers[i] *= -1;
            }
        }
    }

    private static int getIndexOfMaxValue(int[] numbers, int lowerIndex, int upperIndex) {
        int max = numbers[lowerIndex];
        int index = lowerIndex;

        for (int i = lowerIndex + 1; i < upperIndex; ++i) {
            if (numbers[i] > max) {
                max = numbers[i];
                index = i;
            }
        }

        return index;
    }

    /**
     * Reverse order of pancakes from range [lowerIndex; upperIndex).
     */
    private static void flipPancakes(int[] pancakes, int lowerIndex, int upperIndex) {
        for (int i = lowerIndex, j = upperIndex - 1; i < j; ++i, --j) {
            int temp = pancakes[i];
            pancakes[i] = pancakes[j];
            pancakes[j] = temp;
        }
    }
}

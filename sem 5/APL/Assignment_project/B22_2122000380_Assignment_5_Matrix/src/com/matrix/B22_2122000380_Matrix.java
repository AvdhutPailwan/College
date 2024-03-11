package com.matrix;

import java.util.List;
import java.util.Scanner;

class B22_2122000380_Matrix {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter a Matrix string with embedded new lines:");
        String input = scanner.nextLine();

        scanner.close();
//      Sample Input : 9 8 7\n5 3 2\n6 6 7
        String[] rowsInput = input.split("\\\\n");
        Matrix matrix = new Matrix(rowsInput);

        // Get rows and columns
        int[] row2 = matrix.getRow(2);
        int[] column1 = matrix.getColumn(1);

        System.out.println("Row 2: " + java.util.Arrays.toString(row2));
        System.out.println("Column 1: " + java.util.Arrays.toString(column1));

        // Get all rows and columns
        List<int[]> rows = matrix.getRows();
        List<int[]> columns = matrix.getColumns();

        System.out.println("All rows:");
        for (int[] row : rows) {
            System.out.println(java.util.Arrays.toString(row));
        }

        System.out.println("All columns:");
        for (int[] column : columns) {
            System.out.println(java.util.Arrays.toString(column));
        }
    }
}
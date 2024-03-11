package com.matrix;

import java.util.ArrayList;
import java.util.List;

public class Matrix {
    private final int[][] matrix;

    Matrix(String[] rows) {
        //write your own implementation here
        int noOfRows = rows.length;
        int noOfColumns = rows[0].split(" ").length;

        matrix = new int[noOfRows][noOfColumns];

        for (int i = 0; i < noOfRows; i++) {
            String[] cols = rows[i].split(" ");
            for (int j = 0; j < noOfColumns; j++) {
                matrix[i][j] = Integer.parseInt(cols[j]);
            }
        }

    }

    int[] getRow(int rowNumber) {
        //write your own implementation here
        return matrix[rowNumber - 1];
    }

    int[] getColumn(int columnNumber) {
        int[] column = new int[matrix.length];
        for (int i = 0; i < matrix.length; i++) {
            column[i] = matrix[i][columnNumber - 1];
        }
        return column;
    }

    List<int[]> getRows() {
        List<int[]> rows = new ArrayList<>();
        for (int i = 1; i <= matrix.length; i++) {
            rows.add(getRow(i));
        }
        return rows;
    }

    List<int[]> getColumns() {
        List<int[]> columns = new ArrayList<>();
        for (int i = 1; i <= matrix[0].length; i++) {
            columns.add(getColumn(i));
        }
        return columns;
    }
}

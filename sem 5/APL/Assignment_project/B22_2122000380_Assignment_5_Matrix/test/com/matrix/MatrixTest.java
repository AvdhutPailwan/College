package com.matrix;

import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class MatrixTest {

    String[] row = {"9 8 7", "5 3 2", "6 6 7"};
    Matrix obj = new Matrix(row);

    @org.junit.jupiter.api.Test
    void getRow() {
        int[] arr = {9, 8, 7};
        assertArrayEquals(arr, obj.getRow(1));
        arr[0] = 5;
        arr[1] = 3;
        arr[2] = 2;
        assertArrayEquals(arr, obj.getRow(2));
        arr[0] = 6;
        arr[1] = 6;
        arr[2] = 7;
        assertArrayEquals(arr, obj.getRow(3));
    }

    @org.junit.jupiter.api.Test
    void getColumn() {
        int[] column = {9, 5, 6};
        assertArrayEquals(column, obj.getColumn(1));

        column[0] = 8;
        column[1] = 3;
        column[2] = 6;
        assertArrayEquals(column, obj.getColumn(2));

        column[0] = 7;
        column[1] = 2;
        column[2] = 7;
        assertArrayEquals(column, obj.getColumn(3));
    }

    @org.junit.jupiter.api.Test
    void getRows() {
        int[] row1 = {9, 8, 7}, row2 = {5, 3, 2}, row3 = {6, 6, 7};
        List<int[]> rows = obj.getRows();
        assertArrayEquals(row1, rows.get(0));
        assertArrayEquals(row2, rows.get(1));
        assertArrayEquals(row3, rows.get(2));
    }

    @org.junit.jupiter.api.Test
    void getColumns() {
        int[] col1 = {9,5,6}, col2 = {8,3,6}, col3 = {7,2,7};
        List<int[]> cols = obj.getColumns();
        assertArrayEquals(col1, cols.get(0));
        assertArrayEquals(col2, cols.get(1));
        assertArrayEquals(col3, cols.get(2));
    }
}
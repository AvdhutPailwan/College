package com.pascaltrianglegenerator;

public interface ConstructTriangle {
    default int[][] constructIntTriangle(int rows){
        // calculate number of columns since the spaces will be taken by zeros,
        // so my int[][] will look like for rows = 4
        // 0001000
        // 0010100
        // 0102010
        // 1030301
        int cols = (2*rows) - 1;
        int[][] intTriangle = new int[rows][cols];

        // from where to start modifying array e.g. intTriangle[][start] and end is the index where I'll stop
        int start = rows-1, end;

        // first row operation
        intTriangle[0][start] = 1;

        // operation from 2nd row till last row
        for(int i = 1; i<rows; i++){
            start -= 1;
            end = start + (i * 2);
            intTriangle[i][start] = intTriangle[i][end] = 1;
            for(int j = start+2; j< end; j+=2){
                intTriangle[i][j] = intTriangle[i-1][j-1] + intTriangle[i-1][j+1];
            }
        }

        return intTriangle.clone();
    }
}

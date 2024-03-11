package com.updatedpascaltrianglegenerator;

public class Pascals {
    private String[] triangle;

    String[] constructTriangle(int rows){

        if(rows < 1) throw new IllegalArgumentException("Number of rows should be positive!");

        int[][] triangle = new int[rows][rows];
        this.triangle = new String[rows];
        StringBuilder row = new StringBuilder();
        triangle[0][0] = 1;
        row.append(triangle[0][0]);
        this.triangle[0] = row.toString();
        for(int i = 1; i<rows ; i++){
            row.delete(0, row.length());

            for(int j = 1; j<i; j++){
                triangle[i][j] = triangle[i-1][j] + triangle[i-1][j+1];
                row.append(triangle[i][j]);
                row.append(" ");
            }
            this.triangle[i] = row.toString();
        }
        return this.triangle.clone();
    }

    public static void main(String[] args) {
        Pascals obj = new Pascals();
        String[] temp = obj.constructTriangle(5);

        for(String i : temp){
            System.out.println(i);
        }
    }
}

package com.pascaltrianglegenerator;

public class CustomPascals implements ConstructTriangle {

    private String[] triangle;

    String[] getTriangle() {
        return this.triangle;
    }

    String[] constructTriangle(int rows, char c) {
        // Throw exception on invalid argument value
        if(rows < 1) throw new IllegalArgumentException("Number of rows should be positive!");

        // In this approach I've first calculated the triangle in the int[][] array and then converted it to String[]
        int[][] intTriangle = constructIntTriangle(rows);

        // convert int[][] to String[]

        this.triangle = new String[rows];
        StringBuilder stringTriangle = new StringBuilder();

        for(int i = 0; i < rows; i++){
            stringTriangle.delete(0,stringTriangle.length());
            int j;
            for (j = 0; intTriangle[i][j]==0; j++){
                stringTriangle.append(" ");
            }
            stringTriangle.append(intTriangle[i][j++]);
            for(;intTriangle[i][j]!=1 && i!=0;j++){
                if(intTriangle[i][j] == 0){
                    stringTriangle.append(c);
                }
                else {
                    stringTriangle.append(intTriangle[i][j]);
                }
            }
            if(i!=0)stringTriangle.append(intTriangle[i][j]);
            this.triangle[i] = stringTriangle.toString();
        }

        return this.triangle.clone();
    }
    boolean equals(CustomPascals obj){
        String[] tri = obj.getTriangle();
        if(tri.length != this.triangle.length) return false;
        for(int i = 0; i<this.triangle.length; i++){
            if(!this.triangle[i].equals(tri[i])) return false;
        }
        return true;
    }
}

package com.pascaltrianglegenerator;

public class Pascals implements ConstructTriangle{

    // store the triangle of the object
    private String[] triangle;

    String[] constructTriangle(int rows) {
        // Throw exception on invalid argument value
        if(rows < 1) throw new IllegalArgumentException("Number of rows should be positive!");

        // In this approach I've first calculated the triangle in the int[][] array and then converted it to String[]
        int cols = (2*rows) - 1;
        int[][] intTriangle = constructIntTriangle(rows);

        // convert int[][] to String[]
        /*

         0001000         1
         0010100   ~    1 1
         0102010   ~   1 2 1
         1030301      1 3 3 1

        */
        this.triangle = new String[rows];
        StringBuilder stringTriangle = new StringBuilder();

        for(int i = 0; i < rows; i++){
            stringTriangle.delete(0,stringTriangle.length());
            for (int j = 0; j<cols; j++){
                if(intTriangle[i][j] == 0){
                    stringTriangle.append(" ");
                }
                else {
                    stringTriangle.append(intTriangle[i][j]);
                }
            }
            this.triangle[i] = stringTriangle.toString();
        }

        return this.triangle.clone();
    }
    String[] getTriangle(){
        return this.triangle.clone();
    }

    boolean equals(Pascals obj){
        String[] tri = obj.getTriangle();
        if(tri.length != this.triangle.length) return false;
        for(int i = 0; i<this.triangle.length; i++){
            if(!this.triangle[i].equals(tri[i])) return false;
        }
        return true;
    }

}

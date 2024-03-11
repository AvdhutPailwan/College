package com.gameoflife;

import java.util.HashSet;
import java.util.Random;
import java.util.Set;

public class GameOfLife {
    // true --> alive
    // false --> dead
    // Rules
    // For a space that is populated:
    // Each cell with one or no neighbors dies, as if by solitude.
    //
    // Each cell with four or more neighbors dies, as if by overpopulation.
    //
    // Each cell with two or three neighbors survives.
    //
    // For a space that is empty or unpopulated:
    // Each cell with three neighbors becomes populated.


    // store board of cells
    private boolean[][] boardOfCells;

    // store unique board of cells in string format
    private Set<String> uniqueConfigurations;

    // constructor ---> initialize instance variables and randomly generate first board
    public GameOfLife(int n){
        boardOfCells = new boolean[n][n];
        this.uniqueConfigurations = new HashSet<>();
        Random random = new Random();
        int populate = random.nextInt((n*n) + 1);

        int row, col;
        for(int i = 0; i<populate; i++){
            row = random.nextInt(n);
            col = random.nextInt(n);
            boardOfCells[row][col] = true;
        }
        uniqueConfigurations.add(this.toString());
    }

    // getter for board of cells
    public boolean[][] getBoardOfCells() {
        return boardOfCells;
    }

    // method to assigns next generation configuration of board of cells
    public boolean[][] populateNextGeneration(){
        boolean[][] temp = clone2DArray(this.boardOfCells);
        temp = nextGeneration(temp);
        boardOfCells = clone2DArray(temp);
        this.uniqueConfigurations.add(this.toString());
        return temp;
    }

    // keeps the track of number of unique boards till now
    public int findUniqueBoardConfigurations(){
        return this.uniqueConfigurations.size();
    }

    // all are helper functions below written for coders convenience

    // calculates the next configuration of given board
    private boolean[][] nextGeneration(boolean[][] tempBoardOfCells){
        boolean[][] temp = clone2DArray(tempBoardOfCells);
        for(int i = 0; i<temp.length; i++){
            for (int j = 0; j < temp[0].length; j++) {
                temp[i][j] = checkNeighbours(i, j);
            }
        }
        return temp;
    }

    // convert the GameOfLife object into string
    @Override
    public String toString(){
        StringBuilder s = new StringBuilder();
        for (boolean[] boardOfCell : this.boardOfCells) {
            for (boolean b : boardOfCell) {
                s.append(b ? 'x' : '.');
            }
        }
        return s.toString();
    }

    // to clone the 2D array
    private boolean[][] clone2DArray(boolean[][] toClone){
        boolean[][] cloned = new boolean[toClone.length][];
        for (int i = 0; i < toClone.length; i++) {
            cloned[i] = toClone[i].clone();
        }
        return cloned;
    }

    // determine the cell is living or not
    private boolean checkNeighbours(int row, int col){
        int count = 0;
        try{
            if(boardOfCells[row-1][col-1]) count++;
        } catch (ArrayIndexOutOfBoundsException ignored){}
        try{
            if(boardOfCells[row-1][col]) count++;
        } catch (ArrayIndexOutOfBoundsException ignored){}
        try{
            if(boardOfCells[row-1][col+1]) count++;
        } catch (ArrayIndexOutOfBoundsException ignored){

        }
        try{
            if(boardOfCells[row][col+1]) count++;
        } catch (ArrayIndexOutOfBoundsException ignored){

        }
        try{
            if(boardOfCells[row+1][col+1]) count++;
        } catch (ArrayIndexOutOfBoundsException ignored){

        }
        try{
            if(boardOfCells[row+1][col]) count++;
        } catch (ArrayIndexOutOfBoundsException ignored){

        }
        try{
            if(boardOfCells[row+1][col-1]) count++;
        } catch (ArrayIndexOutOfBoundsException ignored){

        }
        try{
            if(boardOfCells[row][col-1]) count++;
        } catch (ArrayIndexOutOfBoundsException ignored){

        }
        if(boardOfCells[row][col]){
            return count > 1 && count < 4;
        } else {
            return count == 3;
        }
    }
}

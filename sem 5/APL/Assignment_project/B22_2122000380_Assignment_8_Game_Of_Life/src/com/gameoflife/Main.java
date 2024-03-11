package com.gameoflife;

public class Main {
    static void printBoard(int size, boolean[][] board){
        for (int i = 0; i<size; i++){
            for (int j = 0; j < size; j++) {
                if(board[i][j]){
                    System.out.print("1 ");
                }else {
                    System.out.print("0 ");
                }
            }
            System.out.println();
        }
    }
    public static void main(String[] args) {
        int size = 4;
        GameOfLife obj = new GameOfLife(size);
        System.out.println("Current Generation : ");
        printBoard(size, obj.getBoardOfCells());
        System.out.println("Next Generation : ");
        printBoard(size, obj.populateNextGeneration());
        System.out.println("The unique board configurations till now : ");
        System.out.println(obj.findUniqueBoardConfigurations());

    }
}

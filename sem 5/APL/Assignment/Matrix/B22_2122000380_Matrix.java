import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Matrix {
    private int[][] matrix;
    Matrix(String matrixAsString) {
        //write your own implementation here
        String[] rows = matrixAsString.split("\\\\n");
        int noOfRows = rows.length;
        int noOfColumns = rows[0].split(" ").length;

        matrix = new int[noOfRows][noOfColumns];

        for(int i = 0; i<noOfRows; i++){
            String[] cols = rows[i].split(" ");
            for (int j = 0; j<noOfColumns; j++){
                matrix[i][j] = Integer.parseInt(cols[j]);
            }
        }

    }

    int[] getRow(int rowNumber) {
        //write your own implementation here
        return matrix[rowNumber - 1];
    }
    int[] getColumn(int columnNumber){
        int[] column = new int[matrix.length];
        for(int i = 0; i < matrix.length; i++){
            column[i] = matrix[i][columnNumber-1];
        }
        return column;
    }
    List<int[]> getRows(){
        List<int[]> rows = new ArrayList<>();
        for(int i = 1; i<= matrix.length; i++){
            rows.add(getRow(i));
        }
        return rows;
    }
    List<int[]> getColumns(){
        List<int[]> columns = new ArrayList<>();
        for(int i = 1; i<=matrix[0].length; i++){
            columns.add(getColumn(i));
        }
        return columns;
    }
}
class B22_2122000380_Matrix {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter a Matrix string with embedded new lines:");
        String input = scanner.nextLine();

        scanner.close();
//      Sample Input : 9 8 7\n5 3 2\n6 6 7
        Matrix matrix = new Matrix(input);

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
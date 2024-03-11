import java.io.*;
import java.util.*;

public class ColumnarCipher { // Key for Columnar Transposition static final String key = "4312567";
    static Map<Character, Integer> keyMap = new HashMap<>();

    static void setPermutationOrder() {
        // Add the permutation order into the map for (int i = 0; i < key.length(); i++)
        // { keyMap.put(key.charAt(i), i);
    }

    }

    // Encryption
    static String encryptMessage(String msg) {
        int row, col;
        StringBuilder cipher = new StringBuilder();

        col = key.length();

        row = (int) Math.ceil((double) msg.length() / col);

        char[][] matrix = new char[row][col];

        for (int i = 0, k = 0; i < row; i++) {
            for (int j = 0; j < col;) {
                if (k < msg.length()) {
                    char ch = msg.charAt(k);
                    if (Character.isLetter(ch) || ch == ' ') {
                        matrix[i][j] = ch;
                        j++;
                    }
                    k++;
                } else {
                    matrix[i][j] = ' ';
                    j++;
                }
            }
        }
        for (Map.Entry<Character, Integer> entry : keyMap.entrySet()) {
            int columnIndex = entry.getValue();

            for (int i = 0; i < row; i++) {
                if (Character.isLetter(matrix[i][columnIndex]) || matrix[i][columnIndex] == ' '
                        || matrix[i][columnIndex] == '_') {
                    cipher.append(matrix[i][columnIndex]);
                }
            }
        }

        return cipher.toString();
    }

    // Decryption
    static String decryptMessage(String cipher) {
        int col = key.length();

        int row = (int) Math.ceil((double) cipher.length() / col);
        char[][] cipherMat = new char[row][col];
        int k = 0;
        for (int j = 0; j < col; j++) {
            for (int i = 0; i < row; i++) {
                cipherMat[i][j] = cipher.charAt(k);
                k++;
            }
        }

        int index = 0;
        for (Map.Entry<Character, Integer> entry : keyMap.entrySet()) {
            entry.setValue(index++);
        }
        char[][] decCipher = new char[row][col];
        for (int l = 0; l < key.length(); l++) {
            int columnIndex = keyMap.get(key.charAt(l));
            for (int i = 0; i < row; i++) {
                decCipher[i][l] = cipherMat[i][columnIndex];
            }
        }

        StringBuilder msg = new StringBuilder();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (decCipher[i][j] != '_') {
                    msg.append(decCipher[i][j]);
                }
            }
        }

        return msg.toString();
    }

    public static void main(String[] args) {         try { 
            /* Read plaintext from a .txt file */ 
            String filePath = "D:\\IS\\text.txt"; 
            String msg = readTextFromFile(filePath); 
 
            setPermutationOrder(); 
            String cipher = encryptMessage(msg);  
            String decryptedMsg = decryptMessage(cipher); 
 
            writeTextToFile(filePath, "Plaintext:\n" + msg + "\n\nEncrypted 
            Message:\n" + cipher + "\n\nDecrypted Message:\n" + decryptedMsg);             System.out.println("Results stored in: " + filePath); 
        } catch (Exception e) { 
            e.printStackTrace(); 
        } 
    }

    private static String readTextFromFile(String filePath) throws Exception {
        StringBuilder content = new StringBuilder();
        try (Scanner scanner = new Scanner(new FileReader(filePath))) {
            while (scanner.hasNextLine()) {
                content.append(scanner.nextLine()).append("\n");
            }
        }
        return content.toString();
    }

    private static void writeTextToFile(String filePath, String content) throws Exception {
        try (BufferedWriter bw = new BufferedWriter(new FileWriter(filePath))) {
            bw.write(content);
        }
    }
}

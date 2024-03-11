
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

class RailFenceCipher {
    int depth;

    String encryption(String plainText, int depth){
        int r = depth;
        int len = plainText.length();
        int c = len / depth;
        char[][] mat = new char[r][c];
        int k = 0;

        StringBuilder cipherText = new StringBuilder();
        for (int i = 0; i < c; i++) {
            for (int j = 0; j < r; j++) {
                if (k != len)
                    mat[j][i] = plainText.charAt(k++);
                else
                    mat[j][i] = 'X';
            }
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cipherText.append(mat[i][j]);
            }
        }
        return cipherText.toString();
    }

    String decryption(String cipherText, int depth) {
        int r = depth;
        int len = cipherText.length();
        int c = len / depth;
        char[][] mat = new char[r][c];
        int k = 0;

        StringBuilder plainText = new StringBuilder();

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                mat[i][j] = cipherText.charAt(k++);
            }
        }
        for (int i = 0; i < c; i++) {
            for (int j = 0; j < r; j++) {
                plainText.append(mat[j][i]);
            }
        }

        return plainText.toString();
    }
}

class RailFence {

    public static void main(String[] args) throws IOException{
        RailFenceCipher rf = new RailFenceCipher();
        int depth;

        String plainText;
        String cipherText;
        String decryptedText;
        String filePath;
        // Hardcoded file path
        filePath = System.getProperty("user.dir") + "/Exp 1/text1.txt";

        plainText = readTextFromFile(filePath);

        System.out.println("Enter depth for Encryption:");
        try (Scanner scn = new Scanner(System.in)) {
            depth = scn.nextInt();
        }

        cipherText = rf.encryption(plainText, depth);

        decryptedText = rf.decryption(cipherText, depth);
        // Write results back to the same file
        writeTextToFile(filePath, "Encrypted Text:\n" + cipherText +
                "\n\nDecrypted Text:\n" + decryptedText);
        System.out.println("Results stored in: " + filePath);
    }

    private static String readTextFromFile(String filePath) throws FileNotFoundException {
        StringBuilder content = new StringBuilder();
        try (Scanner scanner = new Scanner(new FileReader(filePath))) {
            while (scanner.hasNextLine()) {
                content.append(scanner.nextLine()).append("\n");
            }
        }
        return content.toString();
    }

    private static void writeTextToFile(String filePath, String content) throws IOException {
        try (BufferedWriter bw = new BufferedWriter(new FileWriter(filePath))) {
            bw.write(content);
        }
    }
}

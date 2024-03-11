import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class CaesarCipher {
    public static final int SECRETKEY = 3;

    public static String encrypt(String text) {
        StringBuilder result = new StringBuilder();

        for (int i = 0; i < text.length(); i++) {
            char ch = text.charAt(i);
            if (Character.isUpperCase(ch)) {
                char c = (char) ((ch + SECRETKEY - 65) % 26 + 65);
                result.append(c);
            } else {
                char c = (char) ((ch + SECRETKEY - 97) % 26 + 97);
                result.append(c);
            }
        }
        return result.toString();
    }

    public static String decrypt(String text) {
        StringBuilder result = new StringBuilder();

        for (int i = 0; i < text.length(); i++) {
            char ch = text.charAt(i);
            if (Character.isUpperCase(ch)) {
                char c = (char) ((ch - SECRETKEY - 65 + 26) % 26 + 65);
                result.append(c);
            } else {
                char c = (char) ((ch - SECRETKEY - 97 + 26) % 26 + 97);
                result.append(c);
            }
        }
        return result.toString();
    }

    public static void main(String[] args) {
        try (BufferedReader reader = new BufferedReader(new FileReader("input.txt"));
                BufferedWriter writer = new BufferedWriter(new FileWriter("output.txt"))) {

            String line;
            while ((line = reader.readLine()) != null) {
                String encrypted = encrypt(line);
                writer.write("Encrypted text: " + encrypted);
                writer.newLine();
                String decrypted = decrypt(encrypted);
                writer.write("Decrypted text: " + decrypted);
                writer.newLine();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
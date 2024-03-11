import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class FeedBackManager {
    public static void getAverageRating(int choice) {
        String productFilePath= "";
        HashMap<Integer, String> listOfProducts = getIndex();

        for (Map.Entry<Integer, String> entry : listOfProducts.entrySet()) {
            String value = entry.getValue();
            Integer key = entry.getKey();

            if(key==choice) {
                productFilePath = "res/"+value.replace(" ","_")+".csv";
            }
        }
        ArrayList<Integer> rating = getActualRating(productFilePath);

        double averageRating = 0;
        if (rating != null) {
            averageRating = rating.stream()
                    .mapToDouble(Integer::doubleValue)
                    .average()
                    .orElse(0.0);
        }
        System.out.println("Average Rating: "+averageRating);
    }

    public static ArrayList<Integer> getActualRating(String csvFilePath) {

        ArrayList<Integer> rating= new ArrayList<>();

        if (doesFileExist(csvFilePath)) {
            try (BufferedReader reader = new BufferedReader(new FileReader(csvFilePath))) {
                String line;

                // Read the header line (assuming the first line contains headers)
                String header = reader.readLine();
                String[] headers = header.split(",");

                // Read and process the remaining lines
                while ((line = reader.readLine()) != null) {
                    String[] values = line.split(",");
                    for(int i=0;i<values.length;i++) {
                        rating.add(Integer.valueOf(values[i]));
//                        System.out.println(headers[i]+"\n"+getRatingDescription(Integer.parseInt(values[i])));
                    }
                }
            } catch (IOException e) {
                System.out.println("error: "+e.getMessage());
                e.printStackTrace();
            }
        } else {
            System.out.println("Product Feed back does not exist.");
            return null;
        }
        return rating;
    }

    public static void readSelectedFeedback(int choice) {
        String productFilePath= "";
        HashMap<Integer, String> listOfProducts = getIndex();

        for (Map.Entry<Integer, String> entry : listOfProducts.entrySet()) {
            String value = entry.getValue();
            Integer key = entry.getKey();

            if(key==choice) {
                productFilePath = "res/"+value.replace(" ","_")+".csv";
            }
        }
        readDataFromCSV(productFilePath);
    }

    public static void readAllProductFeedBack() {
        HashMap<Integer, String> listOfProducts = getIndex();

        ArrayList<String> filesPaths = new ArrayList<>();

        List<Integer> list= new ArrayList<>();

        ArrayList<String> productName = new ArrayList<>();

        for (Map.Entry<Integer, String> entry : listOfProducts.entrySet()) {
            String value = entry.getValue();
            productName.add(value);
            String productFilePath = "res/"+value.replace(" ","_")+".csv";
//            System.out.println(productFilePath);
            filesPaths.add(productFilePath);
        }
        int count = 0;
        for(String path: filesPaths) {
            System.out.println("Product: "+ productName.get(count++));
            readDataFromCSV(path);
            System.out.println("----------------------------------------------------------------");
        }

    }

    public static void readDataFromCSV(String csvFilePath) {

        if (doesFileExist(csvFilePath)) {
            try (BufferedReader reader = new BufferedReader(new FileReader(csvFilePath))) {
                String line;

                // Read the header line (assuming the first line contains headers)
                String header = reader.readLine();
                String[] headers = header.split(",");

                // Read and process the remaining lines
                while ((line = reader.readLine()) != null) {
                    String[] values = line.split(",");
                    for(int i=0;i<values.length;i++) {
                        System.out.println(headers[i]+"\n"+getRatingDescription(Integer.parseInt(values[i])));
                    }
                }
            } catch (IOException e) {
                System.out.println("error: "+e.getMessage());
                e.printStackTrace();
            }
        } else {
            System.out.println("Product Feed back does not exist.");
            return;
        }
    }

    private static boolean doesFileExist(String filePath) {
        Path path = Paths.get(filePath);
        return Files.isReadable(path) && !Files.isDirectory(path);
    }

    // Helper method to get a description for the rating
    private static String getRatingDescription(int rating) {
        switch (rating) {
            case 1:
                return "Very Dissatisfied";
            case 2:
                return "Dissatisfied";
            case 3:
                return "Neutral";
            case 4:
                return "Satisfied";
            case 5:
                return "Very Satisfied";
            default:
                return "Invalid Rating";
        }
    }

    // read from Question.txt file
    public static List<String> getQuestionsFromTxt(String filePath) {
        List<String> lines = new ArrayList<>();

        try (BufferedReader br = new BufferedReader(new FileReader(filePath))) {
            String line;
            while ((line = br.readLine()) != null) {
                // Add each line to the ArrayList
                lines.add(line);
            }
        } catch (IOException e) {
            System.out.println("error: " + e.getMessage());
        }
        return lines;
    }

    // read from index.csv file
    public static HashMap<Integer, String> getIndex() {
        HashMap<Integer, String> lines = new HashMap<>();

        try (BufferedReader br = new BufferedReader(new FileReader("res/index.csv"))) {
            java.lang.String line;
            while ((line = br.readLine()) != null) {
                // Add each line to the ArrayList
                java.lang.String[] temp = line.split(", ");
                lines.put(java.lang.Integer.parseInt(temp[0]), temp[1]);
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        return lines;
    }

    public static void printIndex(HashMap<Integer, String> listOfProducts){
        for (Map.Entry<Integer, String> entry : listOfProducts.entrySet()) {
            Integer key = entry.getKey();
            String value = entry.getValue();
            System.out.println(key + ") " + value);
        }
    }
}

import java.io.*;
import java.util.*;

public class App {

    public static void main(String[] args) {

        System.out.println("--------------------------------------------------------------");
        System.out.println("|                                                             |");
        System.out.println("|              FeedBack Management System                     |");
        System.out.println("|                                                             |");
        System.out.println("--------------------------------------------------------------");

        // initialize scanner to take input from the user
        Scanner input = new Scanner(System.in);

        // condition to run loop
        boolean keepGoing = true;

        // used to get the choice of the user from the menu or to stop loop
        int choice;


        System.out.print("Enter you Name: ");
        String userName = input.nextLine();
        System.out.println("Hello "+userName+" please provide feedback :-) ");

        System.out.println("--------------------------------------------------------------");

        // read index.csv and store index and name of the product in hashmap
        HashMap<Integer, String> listOfProducts = FeedBackManager.getIndex();

        // read the list of questions for the feedback
        List<String> Questions = FeedBackManager.getQuestionsFromTxt("res/Question.txt");

        while (keepGoing) {
            System.out.println("Enter Product Id to give feedback ");

            // in menu print all the products from index
            FeedBackManager.printIndex(listOfProducts);
            choice = input.nextInt();

            // take the product of user's choice into consideration
            String productName = listOfProducts.get(choice);

            // create the relative file path for the product's own feedbacks where all the feedbacks of that product
            // will be stored.
            String productFilePath = "res/" + productName.replace(" ", "_") + ".csv";

            // create file and create column header
            if (!new File(productFilePath).exists()) {
                String firstLineOfNewFile = String.join(",", Questions);
                try (FileWriter productFileWriter = new FileWriter(productFilePath)) {
                    productFileWriter.write(firstLineOfNewFile);
                } catch (IOException e) {
                    System.out.println("Error inserting first line");
                }
            }

            // insert the ratings into their respective columns
            boolean toContinue = false;
            try (FileWriter productFileWriter = new FileWriter(productFilePath, true)) {
                StringBuffer prepareLine = new StringBuffer();
                for (String Question : Questions) {
                    System.out.println(Question);
                    int rating = input.nextInt();
                    if (rating > 5 || rating < 1) {
                        System.out.println("Invalid Rating!");
                        toContinue = true;
                        break;
                    }
                    prepareLine.append(rating).append(",");
                }
                if (toContinue) continue;
                prepareLine.deleteCharAt(prepareLine.length() - 1);
                productFileWriter.append("\n").append(prepareLine);
            } catch (IOException e) {
                throw new RuntimeException(e);
            }

            System.out.println("Would you like to continue? : (1/0)  where 1=yes and 0=no ");
            choice = input.nextInt();
            if (choice == 0) keepGoing = false;
        }
        input.close();
    }

}

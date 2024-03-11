import java.util.*;


public class AdminApp {

    public static void main(String[] args) {

        System.out.println("--------------------------------------------------------------");
        System.out.println("|                                                             |");
        System.out.println("|            FeedBack Management System Admin                 |");
        System.out.println("|                                                             |");
        System.out.println("--------------------------------------------------------------");

        Scanner input = new Scanner(System.in);
        boolean keepGoing = true;
        int choice;
        CalculateAverageRatingThread calculateAverageRatingThread;
        DisplayAllFeedbackThread displayAllFeedbackThread;
        DisplaySelectedFeedbackThread displaySelectedFeedbackThread;

        while (keepGoing) {
            System.out.println("Please Select from the following ");
            System.out.println("1) See All Product Feedback ");
            System.out.println("2) See Particular Product Feedback");
            System.out.println("3) See Average Rating Product");
            System.out.print("choice: ");
            choice = input.nextInt();

            switch (choice) {
                case 1: {
                    displayAllFeedbackThread = new DisplayAllFeedbackThread();
                    displayAllFeedbackThread.run();
                    break;
                }
                case 2: {
                    HashMap<Integer, String> data = FeedBackManager.getIndex();
                    FeedBackManager.printIndex(data);
                    System.out.print("Enter Product Id: ");
                    int userChoice = input.nextInt();
                    displaySelectedFeedbackThread = new DisplaySelectedFeedbackThread(userChoice);
                    displaySelectedFeedbackThread.run();
                    break;
                }
                case 3: {
                    HashMap<Integer, String> data = FeedBackManager.getIndex();
                    FeedBackManager.printIndex(data);
                    System.out.print("Enter Product Id: ");
                    int userChoice = input.nextInt();
                    calculateAverageRatingThread = new CalculateAverageRatingThread(userChoice);
                    calculateAverageRatingThread.run();
                    break;
                }
                default: {
                    keepGoing = false;
                }
            }


            System.out.println("Would you like to continue? : (1/0) where 1=yes and 0=no  ");
            choice = input.nextInt();
            if (choice == 0) keepGoing = false;
        }


        input.close();
    }

    static class CalculateAverageRatingThread implements Runnable {

        int choice;

        CalculateAverageRatingThread(int choice) {
            this.choice = choice;
        }

        @Override
        public void run() {
            FeedBackManager.getAverageRating(choice);
        }
    }

    static class DisplayAllFeedbackThread implements Runnable {
        @Override
        public void run() {
            FeedBackManager.readAllProductFeedBack();
        }
    }

    static class DisplaySelectedFeedbackThread implements Runnable {

        Integer choice;

        DisplaySelectedFeedbackThread(Integer choice) {
            this.choice = choice;
        }

        @Override
        public void run() {
            FeedBackManager.readSelectedFeedback(choice);
        }
    }


}

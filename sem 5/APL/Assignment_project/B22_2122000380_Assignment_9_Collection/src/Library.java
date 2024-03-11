import java.util.HashSet;
import java.util.Scanner;

public class Library {
    HashSet<Book> distinctTitles;

    boolean addBook(Book book){
        return distinctTitles.add(book);
    }

    boolean removeBook(Book book){
        return distinctTitles.remove(book);
    }

    boolean containsBook(Book book){
        return distinctTitles.contains(book);
    }

    void displayBooks(){
        if(!distinctTitles.isEmpty()){
            System.out.println("Distinct Titles in the Library:");
            for (Book book : distinctTitles) {
                System.out.println(book.getTitle());
            }
        }
    }

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int choice, accesionNum, edition;
        String title, author;
        double price;
        HashSet<Book> distinctTitles = new HashSet<>();

        // Sample book records
//        Book book1 = new Book(1, "Head First Java", "Kathy Sierra", 25.29, 2);
//        Book book2 = new Book(2, "Java: The Complete Reference", "Herbert Schildt", 30.79, 11);
//        Book book3 = new Book(3, "Head First Java", "Kathy Sierra", 25.95, 3);
//        Book book4 = new Book(4, "Design Patterns", "Erich Gamma", 19.86, 1);
//
//        // Add books to the HashSet to track distinct titles
//        distinctTitles.add(book1);
//        distinctTitles.add(book2);
//        distinctTitles.add(book3);
//        distinctTitles.add(book4);
//        System.out.println(distinctTitles.contains(new Book(1, "Jav: The Complete Reference", "Herbert", 5, 1)));
//        System.out.println("Distinct Titles in the Library:");
//        for (Book book : distinctTitles) {
//            System.out.println(book.getTitle());
//        }

        boolean keep_going = true;
        while(keep_going){
            System.out.print(" 1. add book\t 2. remove book\t 3. search book\t 4. display all\t 5. exit : ");
            choice = s.nextInt();
            s.nextLine();
            switch (choice){
                case 1:
                    System.out.print(" accesionNum : ");
                    accesionNum = s.nextInt();
                    s.nextLine();
                    System.out.print(" title : ");
                    title = s.nextLine();
                    System.out.print(" author : ");
                    author = s.nextLine();
                    System.out.print(" price : ");
                    price = s.nextDouble();
                    System.out.print(" edition : ");
                    edition = s.nextInt();
                    System.out.println(" Added : " + distinctTitles.add(new Book(accesionNum, title, author, price, edition)));

                    break;
                case 2:
                    System.out.print(" Title : ");
                    title = s.nextLine();
                    System.out.println(" Removed : " + distinctTitles.remove(new Book(1, title, "Erich Gamma", 3, 1)));
                    break;
                case 3:
                    System.out.print(" Title : ");
                    title = s.nextLine();
                    System.out.println(" Present : " + distinctTitles.contains(new Book(1, title, "Erich Gamma", 3, 1)));
                    break;
                case 4:
                    if(!distinctTitles.isEmpty()){
                        System.out.println("Distinct Titles in the Library:");
                        for (Book book : distinctTitles) {
                            System.out.println(book.getTitle());
                        }
                    }
                    break;
                case 5:
                    keep_going = false;
                    break;
                default:

            }
        }
    }
}

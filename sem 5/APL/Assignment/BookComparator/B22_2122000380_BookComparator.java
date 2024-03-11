
class WrongSubmissionException extends Exception {
    WrongSubmissionException(){
        super("The book is submitted by wrong student!");
    }
    WrongSubmissionException(String message){
        super(message);
    }
}

class Book {
    private String title, author, edition, price, issuedTo;

    public Book(String title, String author, String edition, String price) {
        this.title = title;
        this.author = author;
        this.edition = edition;
        this.price = price;
    }
    public void issuedTo(String student){
        this.issuedTo = student;
    }
    public void collectFrom(String student) throws WrongSubmissionException{
        if (this.issuedTo.equals(student)){
            issuedTo = null;
        }else throw new WrongSubmissionException("The book is submitted by " + student + " and was issued to " + this.issuedTo);
    }
    public boolean equals(Book book){
        return this.title.equals(book.title) && this.author.equals(book.author)  && this.edition.equals(book.edition);
    }
}
public class B22_2122000380_BookComparator {
    public static void main(String[] args) {
        // Driver-code
        Book book = new Book("Head First Java", "Kathy Sierra, Bert Bates & Trisha Gee","Third", "4962.00");
        book.issuedTo("John Doe");
        System.out.println("The book is issued to John Doe.");
        Book book1 = new Book("Head First Java", "Kathy Sierra, Bert Bates & Trisha Gee","Second", "4962.00");
        System.out.println("book and book1 with title Head First Java same?   :   " + book.equals(book1));
        try{
            book.collectFrom("John Doe");
            System.out.println("Book collected successfully.");
            book.issuedTo("john");
            System.out.println("Book assigned to john successfully.");
            book.collectFrom("Raj");
            System.out.println("Book collected successfully.");
        }catch (Exception e){
            System.out.println("An Error Occurred!");
            System.out.println(e.getMessage());
        }
    }
}
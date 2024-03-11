package com.bookcomparator;

public class B22_2122000380_BookComparator {
    public static void main(String[] args) {
        // Driver-code
        Book book = new Book("Head First Java", "Kathy Sierra, Bert Bates & Trisha Gee","Third", "4962.00");
        if(!book.issuedTo("John Doe")){
            System.out.println("Book is not assigned!");
        };
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
package com.bookcomparator;

public class Book {
    private final String title;
    private final String author;
    private final String edition;
    private final String price;
    private String issuedTo;

    public Book(String title, String author, String edition, String price) {
        this.title = title;
        this.author = author;
        this.edition = edition;
        this.price = price;
    }

    public boolean issuedTo(String student) {
        this.issuedTo = student;
        return this.issuedTo != null;
    }

    public void collectFrom(String student) throws WrongSubmissionException {
        if (this.issuedTo.equals(student)) {
            issuedTo = null;
        } else
            throw new WrongSubmissionException();
    }

    public boolean equals(Book book) {
        return this.title.equals(book.title) && this.author.equals(book.author) && this.edition.equals(book.edition);
    }
}

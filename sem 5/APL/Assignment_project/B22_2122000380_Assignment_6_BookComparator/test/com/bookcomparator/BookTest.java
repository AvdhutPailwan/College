package com.bookcomparator;

import static org.junit.jupiter.api.Assertions.*;

class BookTest {

    @org.junit.jupiter.api.Test
    void issuedTo() {
        Book sample = new Book("Head First Java", "Kathy Sierra, Bert Bates & Trisha Gee","Third", "4962.00");

        assertTrue(sample.issuedTo("John Doe"));
        assertFalse(sample.issuedTo(null));
    }

    @org.junit.jupiter.api.Test
    void collectFrom() {
        Book sample = new Book("Head First Java", "Kathy Sierra, Bert Bates & Trisha Gee","Third", "4962.00");

        assertTrue(sample.issuedTo("John Doe"));
        Exception e = assertThrows(WrongSubmissionException.class, () -> {
            sample.collectFrom("Hello World");
        });
        assertEquals("The book is submitted by wrong student!", e.getMessage());
    }

    @org.junit.jupiter.api.Test
    void testEquals() {
        Book sample1 = new Book("Head First Java", "Kathy Sierra, Bert Bates & Trisha Gee","Third", "4962.00");
        Book sample2 = new Book("Head First Java", "Kathy Sierra, Bert Bates & Trisha Gee","Second", "4962.00");
        Book sample3 = new Book("Head First Java", "Kathy Sierra","Third", "4962.00");
        Book sample4 = new Book("Head First", "Kathy Sierra, Bert Bates & Trisha Gee","Third", "4962.00");
        Book sample5 = new Book("Head First", "Kathy Sierra","First", "4962.00");
        Book sample = new Book("Head First Java", "Kathy Sierra, Bert Bates & Trisha Gee","Third", "4962.00");
        assertTrue(sample.equals(sample1));
        assertFalse(sample.equals(sample2));
        assertFalse(sample.equals(sample3));
        assertFalse(sample.equals(sample4));
        assertFalse(sample.equals(sample5));

    }
}
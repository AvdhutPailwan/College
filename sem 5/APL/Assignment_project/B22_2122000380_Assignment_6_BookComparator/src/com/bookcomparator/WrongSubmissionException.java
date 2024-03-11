package com.bookcomparator;

public class WrongSubmissionException extends Exception {
    WrongSubmissionException() {
        super("The book is submitted by wrong student!");
    }

    WrongSubmissionException(String message) {
        super(message);
    }
}

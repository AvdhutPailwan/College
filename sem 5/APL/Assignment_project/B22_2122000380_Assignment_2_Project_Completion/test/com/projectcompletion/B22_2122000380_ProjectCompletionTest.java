package com.projectcompletion;

import static org.junit.jupiter.api.Assertions.*;

class B22_2122000380_ProjectCompletionTest {
    B22_2122000380_ProjectCompletion obj = new B22_2122000380_ProjectCompletion();

    @org.junit.jupiter.api.Test
    void totalCompletion() {
        assertEquals(5, obj.totalCompletion());
    }

    @org.junit.jupiter.api.Test
    void remainingTime() {
        assertEquals(5, obj.remainingTime(0));
        assertEquals(4, obj.remainingTime(1));
        assertEquals(2, obj.remainingTime(2));
        assertEquals(1, obj.remainingTime(3));
        assertEquals(0.5, obj.remainingTime(4));
        assertEquals(0, obj.remainingTime(5));
    }
}
package com.birdwatcher;

import static org.junit.jupiter.api.Assertions.*;

class BirdWatcherTest {
    int[] birdsPerDay = { 2, 5, 0, 7, 4, 1 };
    BirdWatcher obj = new BirdWatcher(birdsPerDay);

    @org.junit.jupiter.api.Test
    void getLastWeek() {
        int[] array = {0, 2, 5, 3, 7, 8, 4};
        assertArrayEquals(array,obj.getLastWeek() );
    }

    @org.junit.jupiter.api.Test
    void getToday() {
        assertEquals(1, obj.getToday());
    }

    @org.junit.jupiter.api.Test
    void incrementTodaysCount() {
        obj.incrementTodaysCount();
        assertEquals(2,obj.getToday());
    }

    @org.junit.jupiter.api.Test
    void hasDayWithoutBirds() {
        assertTrue(obj.hasDayWithoutBirds());
    }

    @org.junit.jupiter.api.Test
    void getCountForFirstDays() {
        assertEquals(0, obj.getCountForFirstDays(0));
        assertEquals(2, obj.getCountForFirstDays(1));
        assertEquals(7, obj.getCountForFirstDays(2));
        assertEquals(7, obj.getCountForFirstDays(3));
        assertEquals(14, obj.getCountForFirstDays(4));
        assertEquals(18, obj.getCountForFirstDays(5));
        assertEquals(19, obj.getCountForFirstDays(6));
    }

    @org.junit.jupiter.api.Test
    void getBusyDays() {
        assertEquals(2, obj.getBusyDays());
    }
}
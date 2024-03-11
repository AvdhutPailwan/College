package com.pascaltrianglegenerator;

import static org.junit.jupiter.api.Assertions.*;

class PascalsTest {

    @org.junit.jupiter.api.Test
    void constructTriangle() {
        Pascals obj = new Pascals();

        // testcase 1
        String[] str = obj.constructTriangle(5);
        assertArrayEquals(new String[]{"    1    ", "   1 1   ", "  1 2 1  ", " 1 3 3 1 ", "1 4 6 4 1"}, str);

        // testcase 2
        Exception e = assertThrows(IllegalArgumentException.class, () -> {
            obj.constructTriangle(0);
        });

        assertEquals("Number of rows should be positive!", e.getMessage());

    }

    @org.junit.jupiter.api.Test
    void getTriangle() {
        Pascals obj = new Pascals();
        String[] str = obj.constructTriangle(5);
        assertArrayEquals(str, obj.getTriangle());
    }

    @org.junit.jupiter.api.Test
    void testEquals() {
        Pascals obj1 = new Pascals();
        Pascals obj2 = new Pascals();
        Pascals obj3 = new Pascals();

        obj1.constructTriangle(5);
        obj2.constructTriangle(5);
        obj3.constructTriangle(4);

        assertTrue(obj1.equals(obj2));
        assertFalse(obj1.equals(obj3));
    }
}
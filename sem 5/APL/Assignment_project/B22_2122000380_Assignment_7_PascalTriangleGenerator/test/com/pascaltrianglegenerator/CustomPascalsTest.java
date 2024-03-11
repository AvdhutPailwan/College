package com.pascaltrianglegenerator;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class CustomPascalsTest {

    @Test
    void getTriangle() {
        CustomPascals obj = new CustomPascals();
        String[] str = obj.constructTriangle(5,'-');
        assertArrayEquals(str, obj.getTriangle());
    }

    @Test
    void constructTriangle() {
        CustomPascals obj = new CustomPascals();

        // testcase 1
        String[] str = obj.constructTriangle(5,'-');
        assertArrayEquals(new String[]{"    1", "   1-1", "  1-2-1", " 1-3-3-1", "1-4-6-4-1"}, str);

        // testcase 2
        Exception e = assertThrows(IllegalArgumentException.class, () -> {
            obj.constructTriangle(0,'-');
        });

        assertEquals("Number of rows should be positive!", e.getMessage());
    }

    @Test
    void testEquals() {
        CustomPascals obj1 = new CustomPascals();
        CustomPascals obj2 = new CustomPascals();
        CustomPascals obj3 = new CustomPascals();

        obj1.constructTriangle(5, '*');
        obj2.constructTriangle(5, '*');
        obj3.constructTriangle(4, '*');

        assertTrue(obj1.equals(obj2));
        assertFalse(obj1.equals(obj3));
    }
}
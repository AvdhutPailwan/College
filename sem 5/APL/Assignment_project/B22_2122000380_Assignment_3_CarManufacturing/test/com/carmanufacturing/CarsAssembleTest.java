package com.carmanufacturing;

import static org.junit.jupiter.api.Assertions.*;

class CarsAssembleTest {
    CarsAssemble obj = new CarsAssemble();
    @org.junit.jupiter.api.Test
    void productionRatePerHour() {
        assertEquals(0, obj.productionRatePerHour(0));
        assertEquals(121, obj.productionRatePerHour(1));
        assertEquals(242, obj.productionRatePerHour(2));
        assertEquals(344.8500061035156, obj.productionRatePerHour(3));
        assertEquals(435.6000061035156, obj.productionRatePerHour(4));
        assertEquals(502.1499938964844, obj.productionRatePerHour(5));
    }

    @org.junit.jupiter.api.Test
    void workingItemsPerMinute() {
        assertEquals(0, obj.workingItemsPerMinute(0));
        assertEquals(2, obj.workingItemsPerMinute(1));
        assertEquals(4, obj.workingItemsPerMinute(2));
        assertEquals(5, obj.workingItemsPerMinute(3));
        assertEquals(7, obj.workingItemsPerMinute(4));
        assertEquals(8, obj.workingItemsPerMinute(5));
    }
}
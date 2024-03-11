package com.carmanufacturing;

public class CarsAssemble {
    public float productionRatePerHour(int speed) {
        // cars produced per hour for 1 unit of speed
        float normalProductionRate = 121;
        float carsProduced = speed * normalProductionRate, successfulCarsProduced;
        return switch (speed) {
            case 1, 2 -> {
                successfulCarsProduced = carsProduced;
                yield successfulCarsProduced;
            }
            case 3 -> {
                successfulCarsProduced = carsProduced * 95 / 100;
                yield successfulCarsProduced;
            }
            case 4 -> {
                successfulCarsProduced = carsProduced * 90 / 100;
                yield successfulCarsProduced;
            }
            case 5 -> {
                successfulCarsProduced = carsProduced * 83 / 100;
                yield successfulCarsProduced;
            }
            default -> carsProduced;
        };
    }

    public int workingItemsPerMinute(int speed) {
        float successfulProductionPerHour = productionRatePerHour(speed);
        return (int) (successfulProductionPerHour / 60);
    }
}

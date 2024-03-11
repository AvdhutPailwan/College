package com.birdwatcher;

public class BirdWatcher {
    private final int[] birdsLastWeek = {0, 2, 5, 3, 7, 8, 4};
    private final int[] birdsPerDay;

    public BirdWatcher(int[] birdsPerDay) {
        this.birdsPerDay = birdsPerDay;
    }

    public int[] getLastWeek() {
        return birdsLastWeek.clone();
    }

    public int getToday() {
        return birdsPerDay[birdsPerDay.length - 1];
    }

    public void incrementTodaysCount() {
        birdsPerDay[birdsPerDay.length - 1] += 1;
    }

    public boolean hasDayWithoutBirds() {
        for (int birds : birdsPerDay) {
            if (birds == 0) return true;
        }
        return false;
    }

    public int getCountForFirstDays(int days) {
        int sum = 0;
        for (int i = 0; i < days; i++) {
            sum += birdsPerDay[i];
        }
        return sum;
    }

    public int getBusyDays() {
        int count = 0;
        for (int birds : birdsPerDay) {
            if (birds > 4) count++;
        }
        return count;
    }
}

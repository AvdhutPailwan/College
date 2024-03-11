package com.birdwatcher;

class B22_2122000380_BirdWatcher {
    public static void main(String[] args) {
        int[] birdsPerDay = { 2, 5, 0, 7, 4, 1 };
        BirdWatcher birdCount = new BirdWatcher(birdsPerDay);

        // 1
        int[] lastWeek = birdCount.getLastWeek();
        System.out.print("Birds last week : ");
        for(int i = 0; i<lastWeek.length - 1; i++){
            System.out.print(lastWeek[i] + ", ");
        }
        System.out.println(lastWeek[lastWeek.length - 1]);

        //2
        System.out.println("Today's bird count : " + birdCount.getToday());

        //3
        birdCount.incrementTodaysCount();
        System.out.println("Today's bird count after increment : " + birdCount.getToday());

        //4
        System.out.println("Day without birds?\t: " + birdCount.hasDayWithoutBirds());

        //5
        System.out.println("Birds for first 3 days : " + birdCount.getCountForFirstDays(3));

        //6
        System.out.println("Busy days : " + birdCount.getBusyDays());
    }
}
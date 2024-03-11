class BirdWatcher {
    private int[] birdsLastWeek = {0, 2, 5, 3, 7, 8, 4}, birdsPerDay;

    public BirdWatcher(int[] birdsPerDay) {
        this.birdsPerDay = birdsPerDay;
    }

    public int[] getLastWeek(){
        return birdsLastWeek;
    }
    public int getToday(){
        return birdsPerDay[birdsPerDay.length - 1];
    }
    public void incrementTodaysCount(){
        birdsPerDay[birdsPerDay.length - 1] += 1;
    }
    public boolean hasDayWithoutBirds(){
        for(int birds : birdsPerDay){
            if(birds == 0) return true;
        }
        return false;
    }
    public int getCountForFirstDays(int days){
        int sum = 0;
        for(int i = 0; i<days; i++){
            sum += birdsPerDay[i];
        }
        return sum;
    }
    public int getBusyDays(){
        int count = 0;
        for(int birds : birdsPerDay){
            if(birds > 4) count++;
        }
        return count;
    }
}


class Main {
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
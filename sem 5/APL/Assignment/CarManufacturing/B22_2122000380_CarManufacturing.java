import java.util.Scanner;

class CarsAssemble{
    public float productionRatePerHour(int speed){
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

    public int workingItemsPerMinute(int speed){
        float successfulProductionPerHour = productionRatePerHour(speed);
        return (int)(successfulProductionPerHour/60);
    }
}

class Main{
    public static void main(String[] args) {
        try (Scanner input = new Scanner(System.in)) {
            int speed, choice;
            CarsAssemble car = new CarsAssemble();
            boolean keep_going = true;

            while(keep_going){
                System.out.print("1. Enter speed of the machine\t2. Exit : ");
                choice = input.nextInt();
                switch(choice){
                case 1:
                    System.out.print("speed : ");
                    speed = input.nextInt();
                    if(speed < 0 || speed > 5){
                        System.out.println("speed shoud be from 0 to 5!");
                    }else{
                        System.out.println(" productionRatePerHour() : " + car.productionRatePerHour(speed));
                        System.out.println(" workingItemsPerMinute() : " + car.workingItemsPerMinute(speed));
                    }
                    break;
                case 2:
                    keep_going = false;
                    break;
                default:
                    System.out.println("Invalid Choice!");
                }
            }
        }
    }
}

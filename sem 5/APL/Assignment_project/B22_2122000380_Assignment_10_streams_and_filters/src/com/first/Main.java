package com.first;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.IntStream;


public class Main {
    public static String maxVolumeDate(List<StockData> list){
        return list.stream()
                .max(Comparator.comparing(StockData::getVolume))
                .map(StockData::getDate)
                .orElseThrow(NoSuchElementException::new);
    }
    public static String minHighDate(List<StockData> list){
        return list.stream()
                .min(Comparator.comparing(StockData::getHigh))
                .map(StockData::getDate)
                .orElseThrow(NoSuchElementException::new);
    }
    public static double averageOpenPrice(List<StockData> list){
        return (list.stream()
                .map(x -> x.open)
                .reduce((double) 0, Double::sum))/list.size();
    }
    public static long averageVolume(List<StockData> list){
        return (list.stream()
                .map(x->(long) x.volume)
                .reduce((long) 0, Long::sum)) / list.size();
    }
    public static String dateOfTheMaxFluctuation(List<StockData> list){
        return list.stream()
                .max((obj1, obj2) -> Double.compare(obj1.getFluctuation(), obj2.getFluctuation()))
                .map(StockData::getDate)
                .orElseThrow(NoSuchElementException::new);
    }
    public static List<String> daysWhenOpeningPriceGreaterThanYesterdayClose(List<StockData> list){
        return  IntStream.range(1, list.size())
                .filter(i -> list.get(i).getOpen() > list.get(i-1).getClose())
                .mapToObj(x -> list.get(x).getDate())
                .collect(Collectors.toList());
    }
    public static void main(String[] args) {
        // Path to your CSV file
        var filePath = System.getProperty("user.dir") + "/res/FOX_data.csv";

        // mutable string
        List<StockData> csvData = new ArrayList<>();

        // read csv file data into csvData list
        try {
            Scanner scanner = new Scanner(new File(filePath));
            int i = 0;

            while (scanner.hasNextLine()) {
                String[] line = scanner.nextLine().split(",");
                if(i++ == 0) continue;
                StockData temp = new StockData(line);
                csvData.add(temp);
            }

            scanner.close();
        } catch (FileNotFoundException e) {
            System.out.println(e.getMessage());
        }

        // convert the mutable csvData list to immutable list
        List<StockData> immutableCsvData = Collections.unmodifiableList(csvData);

        var dateWithMaxVolume = maxVolumeDate(immutableCsvData);

        System.out.println("Date with max volume of stock : " + dateWithMaxVolume);

        var dateWithMinHigh = minHighDate(immutableCsvData);
        System.out.println("Date of the min high price : " + dateWithMinHigh);

        var averageOpenPrice = averageOpenPrice(immutableCsvData);
        System.out.println("The average opening price of the stocks : " + averageOpenPrice);

        var averageVolume = averageVolume(immutableCsvData);
        System.out.println("The average volume : " + averageVolume);

        var dateOfTheMostFluctuation = dateOfTheMaxFluctuation(immutableCsvData);
        System.out.println("The most fluctuations were seen on date : " + dateOfTheMostFluctuation);

        var numberOfDaysWhenOpeningPriceGreaterThanYesterdayClose = (long) daysWhenOpeningPriceGreaterThanYesterdayClose(immutableCsvData).size();
        System.out.println("number of days when opening price is at least 1 greater than previous day's close : " + numberOfDaysWhenOpeningPriceGreaterThanYesterdayClose);

        System.out.println();
        System.out.println("List of days when opening price is at least 1 greater than previous day's close : ");
        daysWhenOpeningPriceGreaterThanYesterdayClose(immutableCsvData).forEach(System.out::println);



    }
}
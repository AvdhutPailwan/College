package com.second;

import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

public class Main {
    public static void main(String[] args) {
        List<StockData> obj = new ArrayList<>();
        try (BufferedReader scanner = new BufferedReader(new FileReader("res/FOX_data.csv"))){
            obj = scanner.lines()
                    .skip(1)
                    .map(line -> {
                        String[] values = line.split(",");
                        return new StockData(
                                values[0],
                                Double.parseDouble(values[1]),
                                Double.parseDouble(values[2]),
                                Double.parseDouble(values[3]),
                                Double.parseDouble(values[4]),
                                Integer.parseInt(values[5]),
                                values[6]
                        );
                    })
                    .collect(Collectors.toList());
        } catch (FileNotFoundException e) {
            System.out.println(e.getMessage());
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        storeObjectsToJson(obj);
        readObjectFromJSON("StoredInJSON.json");
    }

    public static void storeObjectsToJson(List<StockData> list){
//        var pathToStorage = System.getProperty("user.dir") + ("/res/StoredInJSON.json");
        try(FileOutputStream fout = new FileOutputStream("res/StoredInJSON.json")){
            ObjectOutputStream out = new ObjectOutputStream(fout);
            
            for(StockData data : list){
                out.writeObject(data);
                out.flush();
                System.out.println("success!");
            }
            out.close();
        }catch (Exception e){
            System.out.println(e.getMessage());
        }

    }

    public static void readObjectFromJSON(String fileName){
        try(FileInputStream fin = new FileInputStream("res/"+fileName)){
            ObjectInputStream in = new ObjectInputStream(fin);
            StockData data;
            while((data = (StockData) in.readObject()) != null){
                System.out.print(data.date() + ",");
                System.out.print(data.low() + ",");
                System.out.print(data.high() + ",");
                System.out.print(data.open() + ",");
                System.out.print(data.close() + ",");
                System.out.print(data.volume() + ",");
                System.out.print(data.name());
                System.out.println();
            }
        }catch (Exception e){
            System.out.println(e.getMessage());
        }
    }
}

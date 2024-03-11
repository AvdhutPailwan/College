package com.first;

import java.util.List;

public class StockData {
    final String date;
    final double open;
    final double high;
    final double low;
    final double close;
    final int volume;
    final String name;
    public StockData(String[] obj) {
        this.date = obj[0];
        this.open = Double.parseDouble(obj[1]);
        this.high = Double.parseDouble(obj[2]);
        this.low = Double.parseDouble(obj[3]);
        this.close = Double.parseDouble(obj[4]);
        this.volume = Integer.parseInt(obj[5]);
        this.name = obj[6];
    }

    public String getDate() {
        return date;
    }

    public double getOpen() {
        return open;
    }

    public double getHigh() {
        return high;
    }

    public double getLow() {
        return low;
    }

    public double getClose() {
        return close;
    }

    public int getVolume() {
        return volume;
    }

    public String getName() {
        return name;
    }

    public double getFluctuation(){
        return this.high - this.low;
    }
}

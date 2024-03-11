package com.second;

import java.io.Serializable;

public record StockData(String date, double open, double high, double low, double close, int volume, String name) implements Serializable {

}

package com.multithreading.part1;

public class Main {
    public static void main(String[] args) {
        Multithread t1 = new Multithread("Thread 1");
        Multithread t2 = new Multithread("Thread 2");
        t1.start();
        t2.start();
    }
}

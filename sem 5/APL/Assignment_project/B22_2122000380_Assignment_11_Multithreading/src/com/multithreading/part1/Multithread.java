package com.multithreading.part1;

public class Multithread extends Thread{
    Multithread(String Name){
        super(Name);
    }
    @Override
    public void run(){
        try{
            for (int i = 0; i < 10; i++) {
                System.out.println(getName());
                sleep(300);
            }
        } catch (InterruptedException err){
            System.out.println("Program is interrupted!");
            System.out.println(err.getMessage());
        }

    }

}

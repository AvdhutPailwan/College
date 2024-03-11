package com.multithreading.part2;

public class Main {
    public static void main(String[] args) {
        int[][][] graphs = {
                {
                        {0, 1, 0, 1},
                        {1, 0, 1, 0},
                        {0, 1, 0, 1},
                        {1, 0, 1, 0}
                },
                {
                        {0, 1, 0, 1},
                        {1, 0, 1, 1},
                        {0, 1, 0, 1},
                        {1, 1, 1, 0}
                },
                {
                        {0, 1, 1, 1},
                        {1, 0, 1, 0},
                        {0, 1, 0, 1},
                        {1, 1, 1, 0}
                },
                {
                        {1, 1, 1, 1},
                        {1, 0, 1, 1},
                        {1, 1, 0, 1},
                        {1, 1, 1, 0}
                },
                {
                        {0, 1, 0, 1},
                        {1, 0, 1, 0},
                        {0, 1, 0, 0},
                        {1, 0, 0, 0}
                },
                {
                        {0, 0, 0, 0},
                        {0, 0, 1, 0},
                        {0, 1, 0, 1},
                        {0, 0, 1, 0}
                }
        };

        CalculateBipartiteThread[] arr = new CalculateBipartiteThread[graphs.length];
        for (int i = 0; i < graphs.length; i++) {
            arr[i] = new CalculateBipartiteThread("Thread " + Integer.toString(i+1), graphs[i]);
            arr[i].start();
        }
    }
}

package com.multithreading.part2;

import java.util.LinkedList;

public class CalculateBipartiteThread extends Thread{
    int[][] graph;
    public boolean isBipartiteUtil(int src, int[] colorArr)
    {
        colorArr[src] = 1;

        LinkedList<Integer> q = new LinkedList<Integer>();
        q.add(src);

        while (!q.isEmpty()) {
            int u = q.getFirst();
            q.pop();

            if (graph[u][u] == 1)
                return false;

            for (int v = 0; v < graph.length; ++v) {
                if (graph[u][v] == 1 && colorArr[v] == -1) {
                    colorArr[v] = 1 - colorArr[u];
                    q.push(v);
                }

                else if (graph[u][v] == 1
                        && colorArr[v] == colorArr[u])
                    return false;
            }
        }

        return true;
    }

    public boolean isBipartite()
    {
        if(graph.length != graph[0].length) return false;
        int[] colorArr = new int[graph.length];
        for (int i = 0; i < graph.length; ++i)
            colorArr[i] = -1;

        for (int i = 0; i < graph.length; i++)
            if (colorArr[i] == -1)
                if (!isBipartiteUtil(i, colorArr))
                    return false;

        return true;
    }
    CalculateBipartiteThread(String Name, int[][] graph){
        super(Name);
        this.graph = graph;
    }
    CalculateBipartiteThread(int[][] graph){
        this.graph = graph;
    }
    @Override
    public void run(){
        System.out.println(getName() + " is bipartite: " + (isBipartite()? "Yes":"No"));

    }
}

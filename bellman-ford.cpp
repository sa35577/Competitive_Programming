#include <bits/stdc++.h>
using namespace std;
int edges[100][3];
int dist[100]={};
int V,E;
int bellmanford(int src, int dest){
    //Step 2: Initialize distances from source to all other
    //vertices as arbitrarily large number
    for(int i = 0; i<=V; i++){
        dist[i] = INT_MAX;
    }
    dist[src] = 0;
    //Step 3 + 4: For every edge if the shortest distance can be updated using
    //the given edge, update it. Relax all edges V-1 times. A simple shortest
    //path from source to any other vertex can have at most
    //V - 1 edges.
    for(int i = 1; i<=V-1 ; i++){
        for(int j = 0; j<E; j++){
            int sta = edges[j][0];
            int fin = edges[j][1];
            int weight = edges[j][2];
            if(dist[sta]!=INT_MAX && dist[sta]+weight<dist[fin]){
                dist[fin] = weight+dist[sta];
            }
        }
    }
    return dist[dest];
}
void printArr(int dist[], int n){
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < n; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}
int main()
{
    //Step 1: Input the graph using edges. Each edge holds a start, an end, and a weight.
    cin >> V >> E;
    for(int i = 0 ; i<E ; i++){
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }
    int sta,fin;
    cin >> sta >> fin;
    cout<<bellmanford(sta,fin) << endl;
    printArr(dist,V+1);
}
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
vector<ii> edges[100];
int dist[100]={};
int V,E;

int djikstra(int src, int dest){
    //Step 1+2: Initialize distances from source to all other
    //vertices as arbitrarily large number
    for(int i = 0; i<=V; i++){
        dist[i] = INT_MAX;
    }
    dist[src] = 0;
    priority_queue<ii,vector<ii>,greater<ii>> heap;
    heap.push({0,src});
    while(!heap.empty()){
        int node = heap.top().second;
        //Step 3: Take the distance-node pair in queue.
        //Check if it is "infinite"
        if (heap.top().first==INT_MAX){
            return INT_MAX;
        }
        heap.pop();
        //Step 4: Loop through all edges leaving the current node
        //and check for the shortest path
        for(ii e : edges[node]){
            int sta = node;
            int fin = e.first;
            int weight = e.second;
            if(dist[sta]+weight<dist[fin]){
                dist[fin]=dist[sta]+weight;
                heap.push({dist[fin],fin});
            }
        }
    }//Step 5: repeat until queue is empty
    return dist[dest];
}
void printArr(int dist[], int n)
{
    printf("Vertex   Distance from Source\n");
    for (int i = 1; i < n; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}
int main()
{
    //Step 1: Input the graph using edges. Each edge holds a start, an end, and a weight.
    //Formatted differently because you need to be able to search for edges out of vertex.
    cin >> V >> E;
    for(int i = 0 ; i<E ; i++){
        int sta,fin,wei;
        cin >> sta >> fin >> wei;
        edges[sta].push_back({fin,wei});
        edges[fin].push_back({sta,wei});
    }
    int sta,fin;
    cin >> sta >> fin;
    cout << "=================================" << endl;
    printf("Distance from %d to %d is %d\n",sta,fin,djikstra(sta,fin));
    printf("Source is Vertex %d\n",sta);
    printArr(dist,V+1);
}


#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;

int V,E;
int graph[1010][1010];
int minKey(int key[], bool mstSet[])
{
    int minn = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < minn)
            minn = key[v], min_index = v;

    return min_index;
}
void printMST(int parent[])
{
    cout<<"Edge \tWeight\n";
    for (int i = 1; i < V; i++)
        cout<<parent[i]<<" - "<<i<<" \t"<<graph[i][parent[i]]<<" \n";
}
void primMST(){
    int parent[1010];
    int key[1010];
    bool mstSet[1010];

    for(int i = 0; i<V; i++){
        key[i]=INT_MAX;
        mstSet[i] = false;
    }
    key[0]=0;
    parent[0] = -1;

    for(int c = 0; c < V-1; c++){
        int u = minKey(key,mstSet);
        mstSet[u] = true;

        for(int v = 0; v<V; v++){
            if(graph[u][v]&&mstSet[v]==false && graph[u][v]<key[v]){
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    printMST(parent);
}
int main()
{
    cin >> V >> E;
    for(int i = 0; i<E; i++){
        int V1,V2,D;
        cin >> V1 >> V2 >> D;
        graph[V1][V2] = graph[V2][V1] = D;
    }
    primMST();
    return 0;
}

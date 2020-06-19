#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;

int dist[100][100]={};
int V,E;

int floyd(int src, int dest){
    //Step 2: Update shortest paths using Floyd-Warshall Algorithm/

    for (int i = 1; i<=V ; i++){
        for(int j = 1; j<=V; j++){
            for (int k = 1; k<=V; k++){
                if(dist[i][k] + dist[k][j] < dist[i][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    return dist[src][dest];
}
void printArr(int dist[100][100], int V)
{
    cout<<"The following matrix shows the shortest distances"
            " between every pair of vertices \n";
    for (int i = 1; i <= V; i++)
    {
        for (int j = 1; j <= V; j++)
        {
            if (dist[i][j] > 10000)
                cout<<"I"<<"     ";
            else
                cout<<dist[i][j]<<"     ";
        }
        cout<<endl;
    }
}
int main()
{
    //Step 1: Input the graph using adjacency list.
    cin >> V >> E;
    memset(dist,1,sizeof(dist));

    for(int i = 0; i<=V; i++){
        dist[i][i] = 0;
    }

    for(int i = 0 ; i<E ; i++){
        int sta,fin,wei;
        cin >> sta >> fin >> wei;
        dist[sta][fin] = wei;
    }
    int sta,fin;
    cin >> sta >> fin;
    cout << "=================================" << endl;
    printf("Distance from %d to %d is %d\n",sta,fin,floyd(sta,fin));
    printf("Source is Vertex %d\n",sta);
    printArr(dist,V);

}
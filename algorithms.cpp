#include <bits/stdc++.h>
using namespace std;
/*
For DP, memoization is better for when you don't
know where to start with your subsolution */
/*
int n;           //the fibonacci term desired
int memo[n + 1]; //array holding values of the fibonacci sequence
for (int i = 0; i <= n; i++)
{
    memo[i] = -1; // -1 denotes no solution found yet
}
memo[0] = 0;
memo[1] = 1;
int Fib(int n)
{
    if (memo[n] != -1)
        return memo[n];
    else
        return memo[n] = Fib(n - 1) + Fib(n - 2);
    // store the value and return
}
 */
//2007 CCCS4
/*
#include <bits/stdc++.h>
using namespace std;
int n;
int x,y;
vector<int> arr[10000];
int shu[10000];
void trust(int a) {
    for (int i = 0; i < arr[a].size(); i++) {
        shu[arr[a][i]] += shu[a]; 
    }
}
int main()
{
    for (int i = 0; i < 10000; i++) {
        shu[i] = 0;
    }
    cin >> n;
    while (true)
    {
        cin >> x >> y;
        if (x == 0 && y == 0) break;
        arr[y].push_back(x);
    }
    shu[n] = 1;
    for (int i = n; i > 1; --i) {
        trust(i);
    }
    cout << shu[1] << endl;
}
 */


//GREEDY ALGORITHm
/*It is the implementation where the best case is taken each time.
In some cases, it can be the best implementation.
Problem: Given a set of K(1000 <= K <= 1000000) integers with values
between 0 and 1000, find the least number of elements needed from the
set to reach a sum of at least S(1 <= S <= 1, 000, 000, 000). It is
guaranteed that the sum of all elements in the set will be greater
than or equal to S

The best way is to sort the numbers.
Code:
#include <bits/stdc++.h>
using namespace std;

int main() {
    int K,S;
    cin >> K >> S;
    int arr[K];
    for (int i = 0; i < K; i++) {
        cin >> arr[i];
    }
    sort(arr,arr+K);
    int tot = 0, pos = 0;
    while (tot < S) {
        tot += nums[pos++];
    }
    cout << tot << "\n";
}
 */
//UNDERSTAND BFS AND DFS,
//DFS involves recursion, BFS involves a queue (but more memory)

//GRAPHS
/*
FLOYD-WARSHALL'S ALGORITHM
<<Finds shortest path between all pairs of vertices.
It solves the algorithm in O(V^3) time
IMPLEMENTATION

int n; //size of graph
int grid[n][n]; //grid containing all shortest paths

//assume edgecost(i,j) returns cost of edge
//infinity returns if no edge exists,
//0 returns if i == j

for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        grid[i][j] = edgecost(i,j);
    }
}
for (int k = 0; k < n; k++) { //pivot vertex
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            grid[i][j] = min(grid[i][k],grid[i][k]+grid[k][j])
        }
    }
}
*/
/*
DIJKSTRA'S ALGORITHM
This runs in O(V^2) time. It measures from one source to all vertices
1. Set source distance to 0, all others infinity
2. Find vertex with min distance from the source that has not yet been visited
3. For all neighbours, check if going thru current vertex creates
   a shorter path than before. If so, update the distance.
IMPLEMENTATION
int n; //size of graph;
int dijkstras(int source) {
    int dist[n];
    bool visited[n];
    for (int i = 0; i < n; i++) {
        dist[i] = INFINITY;
    }
    dist[source] = 0;
    for (int k = 0; k < n; k++) {
        int min = INFINITY;
        int v;
        for (int i = 0; i < n; i++) {
            if (dist[i] < min && !visited[i]) {
                min = dist[i];
                v = i;
            }
        }
        visited[v] = true;
        //assume edgecost(i,j) returns cost of edge between i,j
        //infinity if no edge exists
        for (int i = 0; i < n; i++) {
            dist[i] = min(dist[i],dist[v]+edgecost(v,i));
        }
    }
}
However, a priority queue can run in O(E+VlogV) time for sparse graphs.
It is also better because searching drops from O(V) to O(logV) time.

IMPLEMENTATION (PRIORITY QUEUE)
#define f first
#define s second
int src; //starting
int dist[n]; //distance arrays
for (int i = 0; i < n; i++) {
    dist[i] = INFINITY;
}
dist[src] = 0; //distance to itself is 0
vector<pair<int,int>> arr[n]; //holds all connections, length of edge and node
priority_queue<pair<int,int>
vector<pair<int,int>>,
greater<pair<int,int>>> q; //priority queue, distance followed by node
q.push(make_pair(0,src));
while (!q.empty) {
    auto x = q.top;
    for (int i = 0; i < arr[x].size(); i++) {
        if (x.f + arr[x][i].f < dist[arr[x][i].s]) {
            dist[arr[x][i].s] = x.f + arr[x][i].f;
            q.push(make_pair(dist[arr[x][i].s],arr[x][i].s))
        }
    }
}
//Now dist holds all shortest distances from src.
*/
//A FEW PROBLEMS

#include <bits/stdc++.h>
#include <unordered_set>
#include <stdio.h>

using namespace std;

#define f first
#define s second
#define ll long long
#define ull unsigned long long
#define PI 3.141592653589793
#define vi vector<int>
#define vll vector<long long>
#define p pair<int,int>
const int MOD = 1000000007;
inline double degcos(double ang) {return cos(ang*PI/180);}
inline double degsin(double ang) {return sin(ang*PI/180);}
#define rep(i,j,k,in) for (int i = j; i < k; i += in)


/*---END OF TEMPLATE---*/


vector<int> graph[26];

int dijkstra(int sta, int fin) {
    bool visited[26];
    rep(i,0,26,1) {
        visited[i] = false;
    }
    queue<int> q;
    visited[0]=1;
    q.push(0);
    while (!q.empty()) {
        int cur = q.front();
        rep(i,0,graph[cur].size(),1) {
            if (!visited[graph[cur][i]] && !(cur == sta && graph[cur][i] == fin) && !(cur == fin && graph[fin][i] == sta)) {
                visited[graph[cur][i]] = 1;
                q.push(graph[cur][i]);
            }
        }
        q.pop();
    }
    if (visited[1]) return 0;
    return 1;
}



int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    //ifstream fin("data.in");
    //ofstream fout("data.out");
    string s;
    int tot = 0;
    p arr[500];
    while (true) {
        cin >> s;
        if (s == "**") break;
        arr[tot].f = int(s[0])-65;
        arr[tot].s = int(s[1])-65;
        graph[arr[tot].f].push_back(arr[tot].s);
        graph[arr[tot].s].push_back(arr[tot].f);
        ++tot;
    }
    int disconnect = 0;
    rep(i,0,tot,1) {
        int sta = arr[i].f,fin = arr[i].s;
        if (dijkstra(sta,fin) == 1) {
            ++disconnect;
            cout << char(sta+65) << char(fin+65) << "\n";
        }
    }
    cout << "There are " << disconnect << " disconnecting roads.\n";

    


}   
#include <bits/stdc++.h>
#include <unordered_set>
#include <stdio.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define PI 3.141592653589793
#define vi vector<int>
#define p pair<int,int>
const int MOD = 1000000007;
inline double degcos(double ang) {return cos(ang*PI/180);}
inline double degsin(double ang) {return sin(ang*PI/180);}
#define for(i,j,k,in) for (int i = j; i < k; i += in)


/*---END OF TEMPLATE---*/

int n;
vector<int> graph[n];
vector<int> tree[n];
unordered_map<int,int> factorials;
int sizes[n];

void build_tree(int root, int v) {
    for (int i : graph[v]) {
        if (i != root) {
            tree[v].push_back(i);
            build_tree(v,i);
        }
    }
}

int ffc(int n) {
    if (factorials.find(n) != factorials.end()) return factorials[n];
    if (n <= 1) return 1;
    factorials[n] = ((n % MOD) * ffc(n-1)) % MOD;
    return factorials[n];
}

int getSize(int root) {
    if (sizes[root] != -1) return sizes[root];
    if (tree[root].size() == 0) {
        sizes[root] = 1;
        return sizes[root];
    }
    sizes[root] = 1;
    for (int i : tree[root]) {
        sizes[root] += getSize(i);
    }
    return sizes[root];
}





int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    //ifstream fin("data.in");
    //ofstream fout("data.out");
    int n;
    cin >> n;
    for (i,0,n,1) {
        int a,b;
        cin >> a >> b;
        a--;b--;
        graph[a].push_back(b);
        graph[b].push_back(a);

    }
    for (i,0,n,1) {
        build_tree(-1,i);
        for (j,0,n,1) sizes[j] = -1;

    }

    
}
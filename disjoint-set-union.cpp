#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
class UF {
int *id, cnt, *sz;
public:
UF(int N) {
cnt = N;
id = new int[N];
sz = new int[N];
for(int i=0; i<N; i++) {
id[i] = i;
sz[i] = 1;
}
}
~UF() {
delete [] id;
delete [] sz;
}
int fnd(int p) {
int root = p;
while (root != id[root])
root = id[root];
while (p != root) {
int newp = id[p];
id[p] = root;
p = newp;
}
return root;
}
void mrg(int x, int y){
int i = fnd(x);
int j = fnd(y);
if (i == j) return;
if (sz[i] < sz[j]){
id[i] = j;
sz[j] += sz[i];
} else {
id[j] = i;
sz[i] += sz[j];
}

cnt--;
}
bool ctd(int x, int y) {
return fnd(x) == fnd(y);
}
int count() {
return cnt;
}
};



int main()
{
    int N,M;
    cin >> N >> M;
    pair<int,int> edges[M];
    int a,b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        edges[i] = (make_pair(a,b));
    }
    UF ds(N+1); // will go up to, not including N+1
    vector<int> used;
    for (int i = 0; i < M; i++) {
        if (!ds.ctd(edges[i].f,edges[i].s)) {
            ds.mrg(edges[i].f,edges[i].s);
            used.push_back(i+1);
        }
    }
    if (used.size() == N-1) {
        for (int i = 0; i < N-1; i++) {
            cout << used[i] << "\n";
        }
    }
    else {
        cout << "Disconnected Graph" << "\n";
    }


}
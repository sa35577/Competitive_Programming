#include <bits/stdc++.h>
using namespace std;

class UF
{
    int *id, cnt, *sz;

public:
    UF(int N)
    {
        cnt = N;
        id = new int[N];
        sz = new int[N];
        for (int i = 0; i < N; i++)
        {
            id[i] = i;
            sz[i] = 1;
        }
    }
    ~UF()
    {
        delete[] id;
        delete[] sz;
    }
    int fnd(int p)
    {
        int root = p;
        while (root != id[root])
            root = id[root];
        while (p != root)
        {
            int newp = id[p];
            id[p] = root;
            p = newp;
        }
        return root;
    }
    void mrg(int x, int y)
    {
        int i = fnd(x);
        int j = fnd(y);
        if (i == j)
            return;
        if (sz[i] < sz[j])
        {
            id[i] = j;
            sz[j] += sz[i];
        }
        else
        {
            id[j] = i;
            sz[i] += sz[j];
        }
        cnt--;
    }
    bool ctd(int x, int y)
    {
        return fnd(x) == fnd(y);
    }
    int count()
    {
        return cnt;
    }
};
typedef pair<int,pair<int,int>> p;
#define f first
#define s second

int main() {
    int N,M,D;
    cin >> N >> M >> D;
    int a,b,c;
    priority_queue<p,vector<p>,greater<p>> q;
    for (int kk = 0; kk < M; kk++) {
        cin >> a >> b >> c;
        q.push({c,{a,b}});
    }
    UF ds(N+1);
    int days = 0;
    while (!q.empty()) {
        auto x = q.top();
        if (!ds.ctd(x.s.f,x.s.s)) {
            ds.mrg(x.s.f,x.s.s);
            days++;

        }
        q.pop();
    }
    cout << days << "\n";
    

    


}


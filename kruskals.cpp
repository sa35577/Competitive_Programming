
#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;

int parent[1010];
int N,M;
vector<iii> edges;
int fnd(int i)
{
    if (parent[i] == -1)
        return i;
    return fnd(parent[i]);
}
void Union(int x, int y)
{
    int xset = fnd(x);
    int yset = fnd(y);
    parent[xset] = yset;
}
int main()
{
    memset(parent,-1,sizeof(parent));
    cin >> N >> M;
    for(int i = 0; i<M; i++){
        int sta,fin,wei;
        cin >> sta >> fin >> wei;
        edges.push_back({wei,{sta,fin}});
        edges.push_back({wei,{fin,sta}});
    }
    sort(edges.begin(),edges.end());

    int tsum = 0;
    for(iii i : edges){
        if(!(fnd(i.second.first)==fnd(i.second.second))){
            Union(i.second.first,i.second.second);
            tsum += i.first;
        }
    }
    cout << tsum << endl;
    return 0;
}




class UF
{
    int *id, cnt, *sz;
public:
    UF(int N)
    {
        cnt = N;
        id = new int[N];
        sz = new int[N];
        for(int i=0; i<N; i++)
        {
            id[i] = i;
            sz[i] = 1;
        }
    }
    ~UF()
    {
        delete [] id;
        delete [] sz;
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

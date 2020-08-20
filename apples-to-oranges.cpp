#include <bits/stdc++.h>
#include <unordered_set>
#include <stdio.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define f first
#define s second
#define ll long long
#define ull unsigned long long
#define endl "\n"
#define PI 3.141592653589793
#define vi vector<int>
#define vll vector<long long>
#define p pair<int,int>
const int MOD = 1000000007;
inline double degcos(double ang) {return cos(ang*PI/180);}
inline double degsin(double ang) {return sin(ang*PI/180);}
#define rep(i,j,k,in) for (int i = j; i < k; i += in)


/*---END OF TEMPLATE---*/
unordered_map<string,int> fruits;
unordered_map<int,string> veggies;
int N;
int M;
int curKey=0;
vector<pair<int,long double>> graph[501];
long double maxVal[501];


int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    //ifstream fin("data.in");
    //ofstream fout("data.out");
    cin >> N >> M;
    rep(i,0,N,1) {
        string fruit;
        cin >> fruit;
        fruits[fruit] = i;
        veggies[i] = fruit;

    }
    string sta,fin;
    long double val;
    rep(i,0,M,1) {
        cin >> sta >> fin >> val;
        graph[fruits[sta]].push_back({fruits[fin],val});
    }
    queue<pair<int,long double>> q;
    memset(maxVal,0.0,sizeof(maxVal));
    maxVal[fruits["APPLES"]] = 1.000000;
    q.push({fruits["APPLES"],1.000000});
    int tot = 0;
    while (!q.empty()) {
        //printf("%d\n",q.size());
        pair<int,long double> cur = q.front();
        q.pop();
        int curKey = cur.first;
        long double curValue = cur.second;
        ++tot;
        if (veggies[curKey] == "APPLES" && curValue >= 1.1) {
            cout << "YA\n";
            return 0;
        }
        for (pair<int,long double> nxt : graph[curKey]) {
            if (maxVal[nxt.first] < curValue * nxt.second) {
                maxVal[nxt.first] = curValue*nxt.second;
                q.push({nxt.first,maxVal[nxt.first]})   ;
            }
        }
    }

    if (maxVal[fruits["APPLES"]] >= 1.1) {
        cout << "YA\n";
        return 0;
    }
    cout << "NAW\n" << tot;



}
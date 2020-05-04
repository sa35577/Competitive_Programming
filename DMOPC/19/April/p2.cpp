//
// Created by satcl on 2020-05-04.
//
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
int n;
inline int getNext(int i) {return (i+1)%n;}
inline int getPrev(int i) {return (i+n-1)%n;}

pair<int,int> moves[500001];


int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    //ifstream fin("data.in");
    //ofstream fout("data.out");
    /*
    map<int,int> mp;
    mp.insert({1,2});
    mp.insert({5,8});
    mp.insert({2,6});
    mp.insert({8,-1});
    for (map<int,int>::iterator it = --mp.end(); it != --mp.begin(); it--) {
        int a = it->first, b = it->second;
        cout << a << " " << b << endl;
    }*/
    priority_queue<p> pq;
    int n,tot=0;
    cin >> n;
    int arr[n];
    bool flag = false;
    int flagIdx=-1;
    rep(i,0,n,1) {
        cin >> arr[i];
        tot += arr[i];
        pq.push({arr[i],i});
        if (arr[i] == 0) flag = true;
    }
    if (tot % 2 == 1) {cout << "NO\n"; return 0;}
    int i = 0;
    while (i < tot/2) {
        if (flagIdx != -1) {
            while (arr[flagIdx] == 0) flagIdx = getNext(flagIdx);
            if (arr[flagIdx] >= arr[getNext(flagIdx)]) {
                arr[getNext(flagIdx)] -= arr[flagIdx];
                while (arr[flagIdx] > 0) {
                    arr[flagIdx]--;
                    arr[getNext(flagIdx)]--;
                    moves[i] = {flagIdx,flagIdx+1};
                }
            }
            else {
                flag = true;
                break;
            }
        }
        p cur = pq.top();
        int idx = cur.first, val = cur.second;



        flagIdx = 5;
    }




}
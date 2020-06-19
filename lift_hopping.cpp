#include <bits/stdc++.h>
using namespace std;

unordered_map<int,vector<int>> mp;
vector<int> pass[6];
int speeds[6];
int shortest[6][100];

int main() {
    //cin.sync_with_stdio(0);
    //cin.tie(0); cout.tie(0);
    //ifstream fin("lift_hopping.in");
    //ofstream fout("lift_hopping.out");
    string tc;
    int n,k;
    while (getline(cin,tc)) {
        if (tc.size() == 0) break;
        n = -1;
        k = -1;
        stringstream tt(tc);
        string token;
        while (getline(tt,token,' ')) {
            if (n == -1) n = stoi(token);
            else if (k == -1) k = stoi(token);
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d",&speeds[i]);
        }
        string s;
        getline(cin,s);
        for (int i = 1; i <= n; i++) {
            getline(cin,s);
            stringstream ss(s);
            string tok;
            int val;
            vector<int> v;
            while (getline(ss,tok,' ')) {
                val = stoi(tok);
                if (mp.find(val) == mp.end()) {
                    v.push_back(i);
                    mp[val] = v;
                }
                else mp[val].push_back(i);

                pass[i].push_back(val);
            }
        }
        memset(shortest,1,sizeof(shortest));
        priority_queue<pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>> pq;
        //pair<time,pair<floor,elevator>>
        for (int i = 0; i < mp[0].size(); i++) {
            pq.push({0,{0,mp[0][i]}});
            shortest[mp[0][i]][0] = 0;
        }
        int dist,curFloor,curElevator;
        while (!pq.empty()) {
            pair<int,pair<int,int>> front = pq.top();
            pq.pop();
            dist = front.first;
            curFloor = front.second.first;
            curElevator = front.second.second;

            if (dist > shortest[curElevator][curFloor]) continue;

            //switching elevator
            for (int i = 0; i < mp[curFloor].size(); i++) {
                if (shortest[mp[curFloor][i]][curFloor] > dist + 60) {
                    shortest[mp[curFloor][i]][curFloor] = dist + 60;
                    pq.push({dist+60,{curFloor,mp[curFloor][i]}});    
                }
            }
            //moving up and down floors
            for (int i = 0; i < pass[curElevator].size(); i++) {
                if (pass[curElevator][i] != curFloor) {
                    if (shortest[curElevator][pass[curElevator][i]] > dist + abs(curFloor - pass[curElevator][i])*speeds[curElevator]) {
                        shortest[curElevator][pass[curElevator][i]] = dist + abs(curFloor - pass[curElevator][i])*speeds[curElevator];
                        pq.push({shortest[curElevator][pass[curElevator][i]],{pass[curElevator][i],curElevator}});
                    }
                }
            }
        }
        int mn = INT_MAX;
        for (int i = 1; i <= n; i++) {
            mn = min(mn,shortest[i][k]);
        }
        if (mn == shortest[0][k]) cout << "IMPOSSIBLE\n";
        else cout << mn << endl;
        mp.clear();
        for (int i = 0; i < 6; i++) pass[i].clear();
    }





}
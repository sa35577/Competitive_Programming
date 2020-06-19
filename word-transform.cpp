#include <bits/stdc++.h>
using namespace std;

unordered_map<string,vector<string>> mp;
unordered_map<string,vector<string>>:: iterator it;
int t;
int arr[200*200];
bool getVal(string a, string b) {
    int change = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) ++change;
    }
    return change == 1;
}

int compute(string a, string b) {
    priority_queue<pair<int,string>,
    vector<pair<int,string>>,
    greater<pair<int,string>>> q;
    unordered_map<string,int> visited;
    q.push({0,a});
    while (!q.empty()) {
        pair<int,string> cur = q.top();
        string old = cur.second;
        int val = cur.first;
        visited[old] = 1;
        if (old == b) {
            return val;
        }
        for (string s : mp[old]) {
            if (visited.find(s) == visited.end()) {
                q.push({val+1,s});
            }
        }
        q.pop();
    }
}

int main() {
    int n;
    cin >> n;
    string nw;
    getline(cin,nw);
    for (int i = 0; i < n; i++) {
        string tmp;
        t = 0;
        while (true) {
            cin >> tmp;
            if (tmp == "*") break;
            vector<string> v;
            mp[tmp] = v;
            for (it = mp.begin(); it != mp.end(); it++) {
                if (it->first.size() == tmp.size() && it->first != tmp) {
                    bool cng = getVal(it->first,tmp);
                    if (cng) {
                        mp[tmp].push_back(it->first);
                        it->second.push_back(tmp);
                    }
                }
            }
            ++t;
        }
        string data;
        getline(cin,data);
        while (true) {
            getline(cin,data);
            if (data == "") break;
            int fspace = data.find(' ');
            string s1 = data.substr(0,fspace);
            string s2 = data.substr(fspace+1);
            cout << s1 << " " << s2 << " " << compute(s1,s2) << endl;
            
        }
        if (i != n-1) cout << "\n";
        mp.clear();

    }
}
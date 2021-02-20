#include <bits/stdc++.h>
using namespace std;

unordered_map<int,string> mp;
int mn=0,mx=0,cur=0;

int main() {
	int n;
	cin >> n;
	string dots;
	for (int i = 0; i < n; i++) dots += ".";
	for (int i = -n; i <= n; i++) {
		mp[i] = dots;
	}
	string instruct;
	cin >> instruct;
	string curStr;
	for (int i = 0; i < n; i++) {
		
		if (instruct[i] == 'v') {
			
			++cur;
			curStr = mp[cur];
			mp[cur] = curStr.substr(0,i)+'\\'+curStr.substr(i+1);
			
		}
		else if (instruct[i] == '>') {
			curStr = mp[cur];
			mp[cur] = curStr.substr(0,i)+'_'+curStr.substr(i+1);
		}
		else if (instruct[i] == '^') {
			curStr = mp[cur];
			mp[cur] = curStr.substr(0,i)+'/'+curStr.substr(i+1);
			--cur;
		}
		mn=min(mn,cur);
		mx=max(mx,cur);
	}
	for (int i = -n; i <= n; i++) {
		if (mp[i] != dots)
		cout << mp[i] << endl;
	}
}
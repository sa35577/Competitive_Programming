#include <bits/stdc++.h>
using namespace std;

string add(string s1, string s2) {
	string res = "";
	if (s2.size() > s1.size()) swap(s1,s2);
	reverse(s1.begin(),s1.end());
	reverse(s2.begin(),s2.end());
	int size1 = s1.size(), size2 = s2.size();
	for (int i = 0; i < size1-size2; i++) s2 += '0';
	int carry = 0,dig;
	for (int i = 0; i < s1.size(); i++) {
		dig = carry+(s1[i]-'0')+(s2[i]-'0');
		if (dig >= 10) dig -= 10, carry = 1;
		else carry = 0;
		res += to_string(dig);
	}
	if (carry > 0) res += to_string(carry), carry = 0;
	reverse(res.begin(),res.end());
	int cnt = 0;
	while (res[cnt] == '0') {
		++cnt;
	}
	res = res.substr(cnt);
	if (res.size() == 0) res = "0";
	return res;
}

string subtract(string s1, string s2) {
	string res = "";
	reverse(s1.begin(),s1.end());
	reverse(s2.begin(),s2.end());
	int size1 = s1.size(), size2 = s2.size();
	for (int i = 0; i < size1-size2; i++) s2 += '0';
	//cout << s1 << " " << s2 << "\n";
	int carry = 0,dig;
	for (int i = 0; i < s1.size(); i++) {
		dig = (s1[i]-'0')-(s2[i]-'0')-carry;
		if (dig < 0) dig += 10, carry = 1;
		else carry = 0;
		res += to_string(dig);
	}
	reverse(res.begin(),res.end());
	int cnt = 0;
	while (res[cnt] == '0') {
		++cnt;
	}
	res = res.substr(cnt);
	if (res.size() == 0) res = "0";
	return res;

}

int cmp(string s1, string s2) {
	//compare which string has the greatest absolute value
	if (s1[0] == '-') s1 = s1.substr(1);
	while (s1.size() > 1 && s1[0] == '0') s1 = s1.substr(1);
	if (s2[0] == '-') s2 = s2.substr(1);
	while (s2.size() > 1 && s2[0] == '0') s2 = s2.substr(1);
	if (s1 == s2) return 3;
	if (s1.size() > s2.size()) return 1;
	else if (s1.size() < s2.size()) return 2;
	for (int i = 0; i < s1.size(); i++) {
		if ((s1[i]-'0') > (s2[i]-'0')) return 1;
		else if ((s1[i]-'0') < (s2[i]-'0')) return 2;
	}
	return 3;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	while (n--) {
		string a,b;
		cin >> a >> b;
		if (a[0] != '-' && b[0] != '-') cout << add(a,b) << "\n";
		else if (a[0] == '-' && b[0] == '-') cout << "-" << add(a.substr(1),b.substr(1)) << "\n";
		else {
			int comparison = cmp(a,b);
			if (comparison == 3) cout << 0 << "\n";
			else if (comparison == 1) {
				if (b[0] == '-') cout << subtract(a,b.substr(1)) << "\n";
				else cout << '-' << subtract(a.substr(1),b) << "\n";
			}
			else if (comparison == 2) {
				if (b[0] == '-') cout << '-' << subtract(b.substr(1),a) << "\n";
				else cout << subtract(b,a.substr(1)) << "\n";
			}
			
		}
	}
}
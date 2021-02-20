#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	int a = 2, b = 5,i=3;
	if (N <= 2) cout << 1;
	else if (N <= 5) cout << 2;
	else {
		while (true) {
			if (i % 2 == 1) {
				a += 2*i;
				if (a >= N) {
					cout << i;
					return 0;
				}
			}
			else {
				b += 2*i;
				if (b >= N) {
					cout << i;
					return 0;
				}
			}
			
			i++;
		}
	}
}
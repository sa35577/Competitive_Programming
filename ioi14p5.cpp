#include <bits/stdc++.h>
using namespace std;


int findSample(int n, int confidence[], int host[], int protocol[]) {
	int ans = 0;
	for (int i = n-1; i > 0; i--) {
		int par = host[i], command = protocol[i];
		if (command == 0) {
			ans += confidence[i];
			confidence[par] = max(confidence[par]-confidence[i],0);
		}
		else if (command == 1) {
			confidence[par] = confidence[par] + confidence[i];
		}
		else if (command == 2) {
			confidence[par] = max(confidence[par],confidence[i]);
		}
	}
	return ans + confidence[0];
}
#include <bits/stdc++.h>
using namespace std;

int n;
const int MAXN = 100005;
int confidence[MAXN];
int protocol[MAXN][2];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> confidence[i];
	for (int i = 1; i < n; i++) cin >> protocol[i][0] >> protocol[i][1];
	//0 --> IAmYourFriend
	//1 --> MyFriendsAreYourFriends
	//2 --> WeAreYourFriends
	int ans = 0;
	for (int i = n-1; i > 0; i--) {
		int par = protocol[i][0], command = protocol[i][1];
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
	cout << ans + confidence[0] << "\n";
	return 0;
}
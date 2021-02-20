#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3003, MAXM = 101;
vector<int> pies,newPies;
int N,M;

int calc[MAXN][2][MAXM][MAXM];

int recur(int n, int i, int L, int R) {
	if (calc[n][i][L][R] != -1) return calc[n][i][L][R];
	if (n == N+1) {
		if (i && L <= R) {
			return calc[n][i][L][R] = recur(n,1-i,L,R-1)+newPies[R];
		}
		else if (L <= R) {
			return calc[n][i][L][R] = recur(n,1-i,L+1,R);
		}
		return calc[n][i][L][R] = 0;
	}
	if (i) {
		calc[n][i][L][R] = max(recur(n+1,1-i,L,R)+pies[n],recur(n,1-i,L,R));
		if (L <= R) calc[n][i][L][R] = max(calc[n][i][L][R],recur(n,1-i,L,R-1)+newPies[R]);
		return calc[n][i][L][R];
	}
	else {
		calc[n][i][L][R] = recur(n+1,1-i,L,R);
		if (L <= R) calc[n][i][L][R] = max(calc[n][i][L][R],recur(n,1-i,L+1,R));
	}
	return calc[n][i][L][R];
}


int main() {

	cin >> N;
	pies.resize(N+1);
	
	for (int i = 1; i <= N; i++) cin >> pies[i];
	cin >> M;
	newPies.resize(M);
	for (int i = 0; i < M; i++) cin >> newPies[i];
	sort(newPies.begin(),newPies.end());
	for (int i = 0; i < MAXN; i++)
	for (int j = 0; j < 2; j++)
	for (int k = 0; k < MAXM; k++)
	for (int l = 0; l < MAXM; l++)
	calc[i][j][k][l] = -1;
	cout << recur(1,1,0,M-1);
}
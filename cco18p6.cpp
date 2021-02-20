#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
vector<pii> moves,moves2;
vector<int> lst;

int n;

//swapping elements
void elementSwap(int n1, int n2) {
	if (!(n1-n2)) return;
	if (n1 > n2) {
		//swap n1&n2
		n1 = n1 ^ n2;
		n2 = n2 ^ n1;
		n1 = n1 ^ n2;
	}
	swap(lst[n1],lst[n2]);
	moves.push_back({n1+1,n2+1});

}

//merging together
void mrg(int L, int mid, int R) {
	if (L >= R || mid >= R || L > mid) return;
	if (!((L-R)>>1)) {
		if (lst[L] > lst[R]) elementSwap(L,R);
		return;
	}
	
	int vl = L, vr = mid+1;
	for (int cnt = 0; cnt < (R-L+1)/2; cnt++) {
		if (vl > mid) ++vr;
		else if (vr > R) ++vl;
		else if (lst[vl] < lst[vr]) ++vl;
		else ++vr;
	}

	for (int cnt = 0; cnt < (mid-vl+1)/2; cnt++) elementSwap(vl+cnt, mid-cnt);
	--vr;
	for (int cnt = 0; cnt < (vr-(mid+1)+1)/2; cnt++) elementSwap(mid+1+cnt, vr-cnt);
	for (int cnt = 0; cnt < (vr-vl+1)/2; cnt++) elementSwap(vl+cnt, vr-cnt);
	mid = L + ((R-L+1)>>1) - 1;
	mrg(L,vl-1,mid); mrg(mid+1,vr,R);

}

//divide & conquer merge sort
void mrgSort(int L, int R) {
	if (!(L<R)) return;
	int mid = (L+R)>>1;
	mrgSort(L,mid); mrgSort(mid+1,R);
	mrg(L,mid,R);

}





int main() {
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	bool done;
	for (int cnt = 0; cnt < n; cnt++) {
		lst.push_back(0);
		cin >> lst[cnt];
	}
	done = 1;
	for (int cnt = 1; cnt < lst.size(); cnt++) {
		if (!done) break;
		if (lst[cnt-1] >= lst[cnt]) done = false;
	}
	if (!done) mrgSort(0, n-1);
	moves2 = moves;
	moves.clear();
	for (int cnt = 0; cnt < n; cnt++) cin >> lst[cnt];
	done = 1;
	for (int cnt = 1; cnt < lst.size(); cnt++) {
		if (!done) break;
		if (lst[cnt-1] >= lst[cnt]) done = false;
	}
	if (!done) mrgSort(0, n-1);
	cout << moves.size()+moves2.size() << endl;
	for (int idx = 0; idx < moves2.size(); idx++) {
		cout << moves2[idx].first << " " << moves2[idx].second << endl;
	}
	for (int idx = moves.size()-1; idx > -1; idx--) {
		cout << moves[idx].first << " " << moves[idx].second << endl;
	}
	return 0;





}
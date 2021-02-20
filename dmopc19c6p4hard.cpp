#include <bits/stdc++.h>


using namespace std;


struct Node {
    int L, R;
    map<int, int> freq;
} seg[2000005];


int arr[500005];

void buildTree(int v, int l, int r) {

    seg[v].L = l;
    seg[v].R = r;

    if(l == r) {
        seg[v].freq[0] = 1;

    } else {

        int mid = (l+r)/2;

        buildTree(v*2, l, mid);
        buildTree(v*2+1, mid+1, r);

        seg[v].freq[0] = r-l+1;

    }

}

void increment(int v, int ind) {

    int l = seg[v].L;
    int r = seg[v].R;

    if(l <= ind && ind <= r) {

        if(l == r && l == ind) {
            arr[ind]++;

        } else {


            //increment(v*2, ind);
            //increment(v*2+1, ind);

            int mid = (r+l)/2;

            if(ind <= mid) increment(v*2, ind);
            else increment(v*2+1, ind);

            seg[v].freq[arr[ind]-1]--;
            if(seg[v].freq[arr[ind]-1] == 0) seg[v].freq.erase(arr[ind]-1);

            seg[v].freq[arr[ind]]++;

        }

    } else return;


}

void decrement(int v, int ind) {

    int l = seg[v].L;
    int r = seg[v].R;

    if(l <= ind && ind <= r) {

        if(l == r && l == ind) {
            arr[ind]--;
        } else {

            //decrement(v*2, ind);
            //decrement(v*2+1, ind);

            int mid = (r+l)/2;

            if(ind <= mid) decrement(v*2, ind);
            else decrement(v*2+1, ind);

            seg[v].freq[arr[ind]+1]--;
            if(seg[v].freq[arr[ind]+1] == 0) seg[v].freq.erase(arr[ind]+1);

            seg[v].freq[arr[ind]]++;

        }

    } else return;


}

int query(int v, int QL, int QR, int val) {

    int l = seg[v].L;
    int r = seg[v].R;

    if(l > QR || r < QL) return 0;
    else if (QL <= l && r <= QR) {
        if(l == r) {
            if(arr[l] == val) return 1;
            else return 0;
        }
        if (seg[v].freq.find(val) == seg[v].freq.end()) return 0;
        return seg[v].freq[val];

    } else {

        return query(v*2, QL, QR, val) + query(v*2+1, QL, QR, val);

    }

}

int N, Q, t, x, l, r;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> Q;

    buildTree(1, 1, N);

    for(int i = 0; i < Q; i++) {
        cin >> t;

        if(t == 1) {
            cin >> x;
            increment(1, x);

        } else if (t == 2) {
            cin >> x;
            decrement(1, x);

        } else {
            cin >> l >> r >> x;
            cout << query(1, l, r, x) << "\n";

        }
    }


    return 0;
}
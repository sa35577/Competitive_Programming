#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n,k;
    int tot = 0;
    cin >> n;

    int cur[n];
    int quan[n];

    for (int i = 0; i < n; i++)
        cin >> cur[i];
    for (int i = 0; i < n; i++){
        cin >> quan[i];
        tot += quan[i];
    }
    cin >> k;
    int vals[tot];
    int arg = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < quan[i]; j++) {
            vals[arg] = cur[i];
            arg++;
        }
    }
    arg = 0;
    int wt[k+1];
    for (int i = 0; i < k+1; i++) {
        wt[i] = i;
    }
    vector<vector<int> > wt2;
    for(int i = 0; i < sizeof(vals); i++) {
        wt2[0].push_back(vals[i]);
    }
    for (int i = 0; i < k+1; i++) {
        for (int j = 0; j < i; j++) {
            if (wt2[j].size() - 1 > wt2[i].size() && find(wt2[j].begin(),wt2[j].end(),i-j) != wt2[j].end()) {
                for (int m = 0; m < wt2[j].size(); m++) {
                    if (i - j != wt2[j][m])
                        wt2[i].push_back(wt2[j][m]);
                }
            }
        }
    }

    cout << tot - wt2[k].size();
    return 0;
    /*
    int lst[tot];
    int arg = 0;
    int w;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < quan[i]; j++) {
            lst[arg] = cur[i];
            arg++;
        }
    }


    int arr[k+1];
    arr[0] = 0;
    for (int i = 1; i < k+1; i++)
        arr[i] = 10000;
    for (int i = 0; i < tot; i++) {
        w = 0;
        while (w <= k - lst[i]){
            if (arr[w] != 10000)
                arr[w+lst[i]] = min(arr[w+lst[i]],arr[w]+1);
            w++;
        }
    }
    for (int i = 0; i < k+1; i++)
        cout << arr[i] << endl;
    cout << tot << " " << n << " " << k << endl;

    return 0;
    */
}


#include <bits/stdc++.h>
using namespace std;
int n;
int x,y;
vector<int> arr[10000];
int shu[10000];
void trust(int a) {
    for (int i = 0; i < arr[a].size(); i++) {
        shu[arr[a][i]] += shu[a]; 
    }
}
int main()
{
    for (int i = 0; i < 10000; i++) {
        shu[i] = 0;
    }
    cin >> n;
    while (true)
    {
        cin >> x >> y;
        if (x == 0 && y == 0) break;
        arr[y].push_back(x);
    }
    shu[n] = 1;
    for (int i = n; i > 1; --i) {
        trust(i);
    }
    cout << shu[1] << endl;




}
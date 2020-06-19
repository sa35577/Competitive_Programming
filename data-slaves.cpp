#include <bits/stdc++.h>
using namespace std;

int N,arr[400000];
vector<int> graph[400000];
int y = -9999999;
int ag(int n) {
    int x = arr[n];
    for (int i = 0; i < graph[n].size(); i++) {
        x += ag(graph[n][i]);
    }
    y = max(x,y);
    return x;
}
int main() {
    int N,A,B;
    cin >> N;
    
    for (int i = 0; i < N - 1; i++) {
        cin >> A >> B;
        A--;
        B--;
        graph[A].push_back(B);
    }
    
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    ag(0);
    cout << y << "\n";
    
}
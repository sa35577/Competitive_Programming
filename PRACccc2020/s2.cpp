#include <bits/stdc++.h>
using namespace std;
int n,,cur = 1;
int start[n][n];

struct Pos {
    int m=0,arr[n][n];
    string output = "";
} memo[8000000];

void R1(int ind) {
    memo[cur].m = memo[ind]+1;
    memo[cur].arr = memo[ind].arr;
    for (int i = 0; i < 3; i++) {
        memo[cur].arr[0][i] = 1 - memo[cur].arr[0][i]; 
    }
    for (int i = 0; i < cur; i++) {
        if (memo[cur].arr == memo[i].arr) {
            return;
        }
    }
    memo[cur].output = memo[ind].output + "R 1";
    ++cur;
}

void C2(int ind) {
    memo[cur].m = memo[ind]+1;
    memo[cur].arr = memo[ind].arr;
    for (int i = 0; i < 3; i++) {
        memo[cur].arr[i][1] = 1 - memo[cur].arr[i][1]; 
    }
    for (int i = 0; i < cur; i++) {
        if (memo[cur].arr == memo[i].arr) {
            return;
        }
    }
    memo[cur].output = memo[ind].output + "C 2";
    ++cur;
}
void C3(int ind) {
    memo[cur].m = memo[ind]+1;
    memo[cur].arr = memo[ind].arr;
    for (int i = 0; i < 3; i++) {
        memo[cur].arr[i][2] = 1 - memo[cur].arr[i][2]; 
    }
    for (int i = 0; i < cur; i++) {
        if (memo[cur].arr == memo[i].arr) {
            return;
        }
    }
    memo[cur].output = memo[ind].output + "C 3";
    ++cur;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
        cin >> start[i][j];
    }
    memo[0].arr = start;
    int M = 0;



    
}
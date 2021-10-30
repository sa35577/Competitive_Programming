#include <bits/stdc++.h>
using namespace std;

int n;
int l[10001];
int mem[10001][10001];

int main(){
    ifstream cin("DATA31.txt");
    for(int zz = 0; zz < 10; zz++){
        memset(mem, -1, 10001*10001);
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> l[i];
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if (i == j || mem[i][j] != -1) continue; 
                pair<int,int> mntA = {i,l[i]};
                pair<int,int> mntB = {j,l[j]};
                double slope = (double)(mntA.second-mntB.second)/(mntA.first-mntB.first);
                double inter = (double)mntA.second - slope*mntA.first;
                if (abs(i-j) == 1){
                    mem[i][j] = 1;
                    mem[j][i] = 1;
                }
                else{
                    bool clear = true;
                    vector<int> rg;
                    for(int k = i + 1; k < j; k++){
                        rg.push_back(k);
                    }
                    for (int q : rg){
                        if ((q * slope + inter) <= l[q]){
                            clear = false;
                            break;
                        }
                    }
                    if ( clear){
                        mem[i][j] = 1;
                        mem[j][i] = 1;
                    }
                    else{
                        mem[i][j] = 0;
                        mem[j][i] = 0;
                    }
                }
            }
        }
        pair<int, int> largest = make_pair(-1, -1);
        for (int key = 0; key < n; key++){
            int total = 0;
            for (int i : mem[key]){
                if (i == 1) total ++;
            }
            if (total > largest.second) largest = {key, total};
        }
        cout << largest.first + 1 << endl;
    }
}
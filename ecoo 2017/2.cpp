#include <bits/stdc++.h>
using namespace std;

#define JUDGES 101

int main() {
    for (int cs = 0; cs < 10; cs++) {
        int n;
        cin >> n;
        string names[n];
        int tp[n],tf[n],tg[n],tot[n];
        cin >> names[0];
        for (int i = 0; i < n; i++) {
            tp[i] = 0; tf[i] = 0; tg[i] = 0;
            string j;
            while (true) {
                cin >> j;
                if (j != "J") {
                    if (j != "*") {
                        names[i+1] = j;
                    }
                    break;
                }
                int p,f,g;
                cin >> p >> f >> g;
                tp[i] += p;
                tf[i] += f;
                tg[i] += g;
            }
            tot[i] = tp[i] + tf[i] + tg[i];
        }
        int mx = -1;
        vector<int> tieTot;
        for (int i = 0; i < n; i++) {
            if (tot[i] > mx) {
                mx = tot[i];
                tieTot.clear();
                tieTot.push_back(i);
            }
            else if (tot[i] == mx) {
                tieTot.push_back(i);
            }
        }
        if (tieTot.size() == 1) {
            cout << names[tieTot[0]] << endl;
        }
        else {
            int mg = -1;
            vector<int> tieG;
            for (int m : tieTot) {
                if (tg[m] > mg) {
                    mg = tg[m];
                    tieG.clear();
                    tieG.push_back(m);
                }
                else if (tg[m] == mg) {
                    tieG.push_back(m);
                }
            }
            if (tieG.size() == 1) {
                cout << names[tieG[0]] << endl;
            }
            else {
                int mf = -1;
                vector<int> tieF;
                for (int j : tieG) {
                    if (tf[j] > mf) {
                        mf = tf[j];
                        tieF.clear();
                        tieF.push_back(j);
                    }
                    else if (tf[j] == mf) {
                        tieF.push_back(j);
                    }
                }
                if (tieF.size() == 1) {
                    cout << names[tieF[0]] <<  endl;
                }
                else {
                    int mp = -1;
                    vector<int> tieP;
                    for (int k : tieF) {
                        if (tp[k] > mp) {
                            mp = tp[k];
                            tieP.clear();
                            tieP.push_back(k);
                        }
                        else if (tp[k] == mp) {
                            tieP.push_back(k);
                        }
                    }
                    if (tieP.size() == 1) {
                        cout << names[tieP[0]] << endl;
                    }
                    else {
                        for (int w = 0; w < tieP.size()-1; w++) {
                            cout << names[tieP[w]] << ",";
                        }
                        cout << names[tieP[tieP.size()-1]] << endl;
                    }
                }
            }
        }

    }
}  
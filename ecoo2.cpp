#include <bits/stdc++.h>
using namespace std;

int main() {
    string dna;
    for (int kk = 0; kk < 5; kk++) {
        cin >> dna;
        int pos = dna.find("TATAAT") + 10;
        string remain = dna.substr(pos);
        string flip = remain;
        reverse(flip.begin(),flip.end());
        for (int i = 0; i < flip.size(); i++) {
            if (flip[i] == 'A') {
                 flip[i] = 'T';
            }
            else if (flip[i] == 'T') flip[i] = 'A';
            else if (flip[i] == 'G') flip[i] = 'C';
            else if (flip[i] == 'C') flip[i] = 'G';
        }
        int k = 6;
        int position=-2;
        string tmp;
        while (true) {
            for (int j = 1; j < remain.size()-k+1; j++) {
                tmp = remain.substr(j,k);
                if (flip.find(tmp) >= j+k) {
                    position = flip.find(tmp);
                    break;
                }
            }
            if (position != -2) break;
            ++k;
        }
        cout << kk+1 << ": ";
        flip = remain.substr(0,position);
        for (int i = 0; i < flip.size(); i++) {
            if (flip[i] == 'A') {
                 flip[i] = 'U';
            }
            else if (flip[i] == 'T') flip[i] = 'A';
            else if (flip[i] == 'G') flip[i] = 'C';
            else if (flip[i] == 'C') flip[i] = 'G';
        }
        cout << flip << endl;





        
    }
}
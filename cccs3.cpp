#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

unsigned int dp[200005];
unsigned int freq[200005][26];
unsigned int hi[200005], ni[200005];
unsigned int val(char c) {
    return (unsigned int)(int(c)-97);
}

long long hsh(string key) {
  const int base = 13;
  long long hsh = 0;
  for (int charIndex = 0; charIndex < key.size(); charIndex += 1) {
    const int charCode = key[charIndex];
    hsh = (hsh * base + charCode) % 1000000007;
  }

  return hsh;
}

int main() {
    //cout << hsh("ab") << " " << hsh("b");
    string n,h;
    cin >> n >> h;
    unsigned int N = 0;
    unordered_set<long long> st;
    unsigned int ns = n.size(),hs = h.size();
    if (ns > hs) {
        cout << 0;
        return 0;
    }
    unsigned int Nfreq[26];
    memset(Nfreq,0,sizeof(Nfreq));
    for (unsigned int i = 0; i < ns; i++) {
        ni[i] = val(n[i]);
        N += ni[i];
        Nfreq[ni[i]]++;
    }
    
    dp[0] = 0;
    for (unsigned int i = 0; i < 26; i++) freq[0][i] = 0;
    for (unsigned int i = 0; i < hs; i++) {
        hi[i] = val(h[i]);
        if (i == 0) {
            dp[i] = hi[i];
            freq[i][hi[i]]++;
        }
        else {
            dp[i] = dp[i-1] + hi[i];
            for (unsigned int j = 0; j < 26; j++) {
                freq[i][j] = freq[i-1][j];
            }
            freq[i][hi[i]]++;
        }
    }
    unsigned int nfreq[26];
    for (unsigned int i = ns-1; i < hs; i++) {
        unsigned int cur = dp[i];
        if (i != ns-1) {
            cur -= dp[i-ns];
        }
        if (cur == N) {
            bool good = true;
            for (unsigned int j = 0; j < 26; j++) {
                nfreq[j] = freq[i][j];
                if (i >= ns) nfreq[j] -= freq[i-ns][j];
                if (nfreq[j] != Nfreq[j]) {

                    good = false;
                    break;
                }
            }
            if (good) {
                string newstr = h.substr(i-ns+1,ns);
                //c.insert(newstr);
                st.insert(hsh(newstr));

            }  
        }
    }
    cout << st.size();
}
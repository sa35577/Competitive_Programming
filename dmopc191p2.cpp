#include <bits/stdc++.h>
using namespace std;

string s1 = "Good writing is good ",s2 = " writing is good ",s3 = " is good writing.";
string zero = "Good writing is good writing is good writing.";
string one = "Good writing is good Good writing is good writing is good writing. writing is good Good writing is good writing is good writing. is good writing.";

char solve(long long n, long long k) 
{
    long long x = pow(2,n);//rising to power
    long long y = 45 + 99*(x-1);//current string length
    if (n == 1) {
        if (k > 143) return '.';
        else return one[k];
    }
    long long z = 45 + 99*(x/2-1);//next lower string length
    if (y <= k) {
        return '.';
    }
    else {
        if (k < 21){
            if (n == 1)
                return s1[k];
            else 
                return solve(n-1,k);
        } 
        else if (k < 21 + z) return solve(n-1,k-21);
        else if (k < 37 + z) {
            if (n == 1)
                return s2[k-21-z];
            else 
                return solve(n-1,k-21-z);
        }
        else if (k < 37+2*z) return solve (n-1,k-21-z-16);
        else{
            if (n == 1)
                return s3[k-21-z-16];
            else 
                return solve(n-1,k-21-z-16);
        }
    }

    
}

int main() 
{
    long long q,N,K;
    cin >> q;
    
    for (long long zz = 0; zz < q; zz++) {
        cin >> N >> K;
        K--;
        if (N == 0) {
            if (K > 44) cout << "." << "\n";
            else cout << zero[K] << "\n";
        }
        else {
            cout << solve(N,K) << "\n";
        }
    }
    

}
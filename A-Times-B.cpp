#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>
#define cd complex<double>
#define pi 3.1415982653589
#define vcd vector<cd>
int m,n;


vcd fft(vcd v, cd omega) {
    if (v.size() == 1) return v;
    vcd ao(v.size()/2),ae(v.size()/2);
    for (ll i = 0; i < v.size()/2; i++) {
        ao[i] = v[i*2];//a0,a2,...,a(n-2)
        ae[i] = v[i*2+1];//a1,a3,...,a(n-1)
    }
    vcd ye = fft(ae,omega*omega);
    vcd yo = fft(ao,omega*omega);
    vcd y(v.size());
    cd x(1);
    for (int i = 0; i < v.size()/2; i++) {
        y[i] = ye[i] + x*yo[i];
        y[i+n/2] = ye[i] - x*yo[i];
        x = x * omega;
    }
    return y;
}


int main() {
    string a,b;
    cin >> a >> b;
    while (n - 1 <= a.size()+b.size()) {
        n *= 2;
    }
    vll A(a.size()), B(b.size());
    for (ll i = 0; i < a.size(); i++) {
        A[i] = a[i] - '0';
    }
    A.resize(n);
    for (ll i = 0; i < b.size(); i++) {
        B[i] = b[i] - '0';
    }
    B.resize(n);
    vcd ca(a.begin(),a.end()), cb(a.begin(),a.end());
    cout << "gaga";
    vcd resA = fft(ca,dcd(exp(pi/n))), resB = fft(cb,cd(exp(pi/n)));
    for (ll i = 0; i < resA.size(); i++) resA[i] = resA[i]*resB[i];
    resA = fft(resA,-pi/n);
    vll res(n+1);
    for (ll i = 0; i < resA.size(); i++) res[i+1] = round(resA[i].real());
    res.resize(n);

    ll carry = 0;
	for (int i = n - 1; i > 0; i--)
	{
		res[i] += carry;
		carry = res[i] / 10;
		res[i] %= 10;
	}

	res[0] = carry;
	if (!res[0]) res.erase(res.begin());
	
	n--;
	while (!res[n] && n) n--;

	if (!n) res.resize(1);
	
	for (ll r : res) cout << r;
	cout << "\n";



    
    

}


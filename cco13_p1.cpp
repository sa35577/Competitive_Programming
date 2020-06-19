#include <bits/stdc++.h>
using namespace std;

int x;

bool tobase(int n,int b) {
    vector<int> dig;
    while (n) {
        dig.push_back(n % b);
        n = n / b;
    }
    for (int i = 0; i < dig.size(); i++)
    if (dig[i] != dig[dig.size() - 1 - i])
        return false;
    return true;
}

int main() {
    cin >> x;
    for (int i = 2; i <= sqrt(1000000000) && x > i; i++)
    if (tobase(x,i))
        cout << i << endl;
    if (x > sqrt(1000000000))
	{
		for (int i = x/sqrt(1000000000); i != 0; --i)
		{
			if (x%i == 0)
				cout << x / i - 1 << endl;
		}
	}
	return 0;
}

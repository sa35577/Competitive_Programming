#include <bits/stdc++.h>
using namespace std;

int main() {
	double p,c;
	int n;
	scanf("%d",&n);
	while (n--) {
		scanf("%lf%lf",&p,&c);
		double denom = c+100.00;
		printf("%.9lf\n",p/denom * 100.00);
	}
}
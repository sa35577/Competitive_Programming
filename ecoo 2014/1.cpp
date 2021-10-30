#include <bits/stdc++.h>
using namespace std;

int main() {
    for (int g = 0; g < 10; g++) {
        int a,b,c;
        cin >> a >> b >> c;
        a--;
        double val = (double)(24*60*60+37*60+22.663)/(24*60*60);
        double computeMin = (double)(a*24*60+b*60+c)/(val*60*24);
        int hour = (int)computeMin;
        cout << "Day ";
        cout << hour+1 << ", ";
        computeMin -= hour;
        computeMin *= 24;
        if ((int)computeMin < 10) cout << "0";
        cout << (int)computeMin << ":";
        computeMin -= (int)computeMin;
        computeMin *= 60;
        if ((int)computeMin < 10) cout << "0";
        cout << (int)computeMin << endl;


    }
}
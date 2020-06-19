#include <bits/stdc++.h>
using namespace std;

int main() {
    string season;
    getline(cin,season);
    cout << season << endl;
    cout << "====================" << endl;
    string team;
    int oneBase;
    int atBats,gamesPlayed,runs,hits,twoBase,threeBase,homeRun;
    char num[6];
    int sumBats=0,sumHits=0,slughits=0;
    for (int kk = 0; kk < 10; kk++) {
        cin >> team >> gamesPlayed >> atBats >> runs >> hits >> twoBase >> threeBase >> homeRun;
        cout << team << ": ";
        float batAvg = (float)hits/atBats;
        sprintf(num,"%.3f", batAvg);
        cout << num[1] << num[2] << num[3] << num[4] << " ";
        oneBase = hits - twoBase - threeBase - homeRun;
        slughits += oneBase+2*twoBase+3*threeBase+4*homeRun;
        sumBats += atBats;
        sumHits += hits;
        float sAvg = (float)(oneBase+2*twoBase+3*threeBase+4*homeRun)/atBats;
        sprintf(num,"%.3f", sAvg);
        cout << num[1] << num[2] << num[3] << num[4] << endl;
    }
    cout << "====================" << endl;
    cout << "Big 10 Av: ";
    sprintf(num,"%.3f",(double)sumHits/sumBats);
    cout << num[1] << num[2] << num[3] << num[4] << " ";
    sprintf(num,"%.3f",(double)slughits/sumBats);
    cout << num[1] << num[2] << num[3] << num[4];



}
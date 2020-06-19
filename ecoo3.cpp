#include<bits/stdc++.h>
#define SQRT3 1.732050808
using namespace std;
int main(int argl,char**argv)
{
    double x=0,y=0;
    double x2=0,y2=0,x3=0,y3=0;
    for(unsigned int test=0;test<5;test++) {
        cin>>x>>y;
        x2=x/2+SQRT3*y/2,y2=y/2-SQRT3*x/2,x3=3*x/2-SQRT3*y/2,y3=SQRT3*x/2+3*y/2;
        printf("(%.1f,%.1f) (%.1f,%.1f) (%.1f,%.1f)\n",x2*-1,y2*-1,x2,y2,x3,y3);
    }
    return 0;
}
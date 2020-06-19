#include <bits/stdc++.h>
using namespace std;

int main() {
    bool firstStraight=0,secondStraight=0;
    double x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    double x3,y3,x4,y4;
    cin >> x3 >> y3 >> x4 >> y4;
    if (x2 == x1) firstStraight = 1;
    if (x4 == x3) secondStraight = 1;
    if (firstStraight && secondStraight) {
        if (x1 == x3) {
            printf("coincident");
            return 0;
        }
        printf("parallel");
        return 0;
    }
    double firstSlope,firstInter,secondSlope,secondInter;
    if (firstStraight) {
        secondSlope = (double)(y4-y3)/(x4-x3);
        secondInter = y4-secondSlope*x4;
        printf("%.10f %.10f",x1,secondSlope*x1+secondInter);
        return 0;
    }
    if (secondStraight) {
        firstSlope = (double)(y2-y1)/(x2-x1);
        firstInter = y1-firstSlope*x1;
        printf("%.10f %.10f",x3,firstSlope*x3+firstInter);
        return 0;
    }
    firstSlope = (double)(y2-y1)/(x2-x1);
    firstInter = y1-firstSlope*x1;
    secondSlope = (double)(y4-y3)/(x4-x3);
    secondInter = y4-secondSlope*x4;
    if (firstSlope == secondSlope && firstInter == secondInter) {
        printf("coincident");
        return 0; 
    }
    else if (firstSlope == secondSlope) {
        printf("parallel");
        return 0;
    }
    double interY = (firstInter*secondSlope-secondInter*firstSlope)/(secondSlope-firstSlope);
    double interX = (secondInter-firstInter)/(firstSlope-secondSlope);
    printf("%.10f %.10f",interX,interY);
}
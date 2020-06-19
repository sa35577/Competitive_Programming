#include <bits/stdc++.h>
using namespace std;

double twoPointDist(double x1, double x2, double y1, double y2) {
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}
double PI = (double)4*atan(1);

int main() {
    for (int tc = 0; tc < 5; tc++) {
        int tot = 1;
        double d,l,n;
        cin >> d >> l >> n;
        while (d < 0) d += 360;
        while (d > 360) d -= 360;
        double xTop=l*cos(d*PI/180.0),yTop=l*sin(d*PI/180.0);
        for (int i = 0; i < n; i++) {
            double x,y,r;
            cin >> x >> y >> r;
            double dist = abs(cos(d*PI/180.0)*y-sin(d*PI/180.0)*x);
            if (dist > r) {
                continue;
            }
            if (twoPointDist(xTop,x,yTop,y) <= r || twoPointDist(0,x,0,y) <= r) {
                ++tot;
                continue;
            }
            if (d == 0 || d == 180) {
                if (y <= r && y >= r*(-1) && ((x<=xTop&&x>=0)||(x>=xTop&&x<=0))) {
                    ++tot;
                }
                continue;
            }
            if (d == 90 || d == 270) {
                if (x <= r && x >= r*(-1) && ((y<=yTop&&y>=0)||(y>=yTop&&y<=0))) {
                    ++tot;
                }
                continue;
            }
            double firstSlope = yTop/xTop;
            double firstInter = 0;
            double secondSlope = (double)(-1) * (xTop/yTop);
            double secondInter = y-secondSlope*x;
            double interY = (firstInter*secondSlope-secondInter*firstSlope)/(secondSlope-firstSlope);
            //if((interY<=yTop&&interY>=0)||(interY>=yTop&&interY<=0)) ++tot;
            if (yTop >= 0) {
                if ((interY<=yTop&&interY>=0)) ++tot;
            }
            else {
                if ((interY>=yTop&&interY<=0)) ++tot;
            }
        }
        cout << "The jet will appear on " << tot << " radar screens.\n";
    }
}
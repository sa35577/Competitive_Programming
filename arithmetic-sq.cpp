#include <bits/stdc++.h>
using namespace std;

int arr[3][3];

int check() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    bool b1,b2,b3,b4,b5,b6,b7,b8,b9;
    if (arr[0][0] < 1000000001 && arr[0][0] > -1000000001) {
        b1 = true;
    }
    if (arr[0][1] < 1000000001 && arr[0][1] > -1000000001) {
        b2 = true;
    }
    if (arr[0][2] < 1000000001 && arr[0][2] > -1000000001) {
        b3 = true;
    }
    if (arr[1][0] < 1000000001 && arr[1][0] > -1000000001) {
        b4 = true;
    }
    if (arr[1][1] < 1000000001 && arr[1][1] > -1000000001) {
        b5 = true;
    }
    if (arr[1][2] < 1000000001 && arr[1][2] > -1000000001) {
        b6 = true;
    }

    if (arr[2][0] < 1000000001 && arr[2][0] > -1000000001) {
        b7 = true;
    }
    if (arr[2][1] < 1000000001 && arr[2][1] > -1000000001) {
        b8 = true;
    }
    if (arr[2][2] < 1000000001 && arr[2][2] > -1000000001) {
        b9 = true;
    }
    if (b1 && b2 && b3 && b4 && b5 && b6 && b7 && b8 && b9) {
        return 0;
    }
    //
    /*CHECKING ALL ROWS*/
    if (b1) {
        if (!b2 && b3) {
            arr[0][1] = (arr[0][0] + arr[0][2])/2;
            return check();
        }
        else if (b2 && !b3) {
            arr[0][2] = 2*arr[0][1] - arr[0][0];
            return check();
        }
    }
    else if (b2 && b3) {
        arr[0][0] = 2*arr[0][1] - arr[0][2];
        return check();
    }
    //
    
    /*
    if (b1 && b2 && b3 && b4 && b5 && b6 && b7 && b8 && b9) {
        return 0;
    }
    
    }
    */
    if (b4) {
        if (!b5 && b6) {
            arr[1][1] = (arr[1][0] + arr[1][2])/2;
            return check();
        }
        else if (b5 && !b6) {
            arr[1][2] = 2*arr[1][1] - arr[1][0];
            return check();
        }
    }
    else if (b5 && b6) {
        arr[1][0] = 2*arr[1][1] - arr[1][2];
        return check();
    }
    //
    /*
    
    if (b1 && b2 && b3 && b4 && b5 && b6 && b7 && b8 && b9) {
        return 0;
    }
    
    }
    */
    if (b7) {
        if (!b8 && b9) {
            arr[2][1] = (arr[2][0] + arr[2][2])/2;
            return check();
        }
        else if (b8 && !b9) {
            arr[2][2] = 2*arr[2][1] - arr[2][0];
            return check();
        }
    }
    else if (b8 && b9) {
        arr[2][0] = 2*arr[2][1] - arr[2][2];
        return check();
    }
    //
    
    /*
    if (b1 && b2 && b3 && b4 && b5 && b6 && b7 && b8 && b9) {
        return 0;
    }
    
    }
    */
    /*CHECKING ALLL COLUMNS*/
    if (b1) {
        if (!b4 && b7) {
            arr[1][0] = (arr[0][0]+arr[2][0])/2;
            return check();
        }
        else if (b4 && !b7) {
            arr[2][0] = 2*arr[1][0]-arr[0][0];
            return check();
        }
    }
    else if (b4 && b7) {
        arr[0][0] = 2*arr[1][0]-arr[2][0];
        return check();
    }
    //
    
    /*
    if (b1 && b2 && b3 && b4 && b5 && b6 && b7 && b8 && b9) {
        return 0;
    }
    
    }
    */
    if (b2) {
        if (!b5 && b8) {
            arr[1][1] = (arr[0][1]+arr[2][1])/2;
            return check();
        }
        else if (b5 && !b8) {
            arr[2][1] = 2*arr[1][1]-arr[0][1];
            return check();
        }
    }
    else if (b5 && b8) {
        arr[0][1] = 2*arr[1][1]-arr[2][1];
        return check();
    }
    //
    /*
    if (b1 && b2 && b3 && b4 && b5 && b6 && b7 && b8 && b9) {
        return 0;
    }
    */
    if (b3) {
        if (!b6 && b9) {
            arr[1][2] = (arr[0][2]+arr[2][2])/2;
            return check();
        }
        else if (b6 && !b9) {
            arr[2][2] = 2*arr[1][2]-arr[0][2];
            return check();
        }
    }
    else if (b6 && b9) {
        arr[0][2] = 2*arr[1][2]-arr[2][2];
        return check();
    }
    /*FILLING ALL ZEROES*/
    if (!b5) {
        arr[1][1] = 0;
        return check();
    }
    if (!b2) {
        arr[0][1] = 0;
        return check();
    }
    if (!b8) {
        arr[2][1] = 0;
        return check();
    }
    if (!b4) {
        arr[1][0] = 0;
        return check();
    }
    if (!b6) {
        arr[1][2] = 0;
        return check();
    }
    if (!b1) {
        arr[0][0] = 0;
        return check();
    }
    if (!b3) {
        arr[0][2] = 0;
        return check();
    }
    if (!b7) {
        arr[2][0] = 0;
        return check();
    }
    
    if (!b9) {
        arr[2][2] = 0;
        return check();
    }
    if (b1 && b2 && b3 && b4 && b5 && b6 && b7 && b8 && b9) {
        return 0;
    }
    return check();
}


int main() {
    string sti;
    for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) {
        cin >> sti;
        if (sti == "X") {
            arr[i][j] = INT_MAX;
        }
        else {
            arr[i][j] = stoi(sti);
        }
    }
    check();
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}
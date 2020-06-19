#include <bits/stdc++.h>
using namespace std;

int main() {
    string x;
    int nums[26] = {0,0,0,1,1,1,2,2,2,3,3,3,4,4,4,5,5,5,5,6,6,6,7,7,7,7};
    string alphabet[26] = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
    string groups[8] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxys"};
    int seconds,z;
    while (true) {
        cin >> x;
        if (x == "halt") {
            break;
        }
        for (int i = 0; i < x.size(); i++) {
            cout << nums[find(alphabet,alphabet + 26,x[i])] << endl;

        }




    }
}

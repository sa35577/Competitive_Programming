#include <bits/stdc++.h>
using namespace std;

int main() {
    int nums[8] = {2,3,4,5,6,7,8,9};
    vector<int> newnums;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            for (int k = 0; k < 8; k++) {
                if (find(newnums.begin(),newnums.end(),nums[i]*nums[j]*nums[k]) == newnums.end()) {
                    newnums.push_back(nums[i]*nums[j]*nums[k]);
                }
            }
        }
    }
    cout << newnums.size() << endl;
}

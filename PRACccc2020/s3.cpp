    #include <bits/stdc++.h>
    using namespace std;

    struct Node {
        string value;
        vector<char> nChar;
        vector<int> nIndex;
    } arr[100005];

    pair<int,int> fnd(string prefix, int index) {
        if (arr[index].value == prefix) return {prefix.size(),index};
        char c = prefix[arr[index].value.size()];
        vector<int> v;
        for (int i = 0; i < arr[index].nChar.size(); i++) {
            if (arr[index].nChar[i] == c) {
                v.push_back(arr[index].nIndex[i]);
            }
        }
        int mxsize = arr[index].value.size(), newIndex = index;
        for (int i : v) {
            pair<int,int> np = fnd(prefix,i);
            if (np.first > mxsize) {
                mxsize = np.first;
                newIndex = np.second; 
            }
            else if (np.first == mxsize && np.second < newIndex) {
                newIndex = np.second;
            }
        }
        return {mxsize,newIndex};
    }

    int main() {
        cin >> arr[0].value;
        int q;
        cin >> q;
        char type;
        char c;
        int ind,furthest=1;
        string prefix;
        for (int QQ = 0; QQ < q; QQ++) {
            cin >> type;
            if (type == 'C') {
                cin >> ind >> c;
                --ind;
                arr[furthest].value = arr[ind].value + c;
                arr[ind].nIndex.push_back(furthest);
                arr[ind].nChar.push_back(c);
                ++furthest;
            }
            else if (type == 'Q') {
                cin >> prefix;
                if (prefix[0] != arr[0].value[0]) cout << -1 << endl;
                else {
                    if (prefix.size() <= arr[0].value.size()) {
                        cout << 1 << endl;
                    }
                    else {
                        if (prefix.substr(0,arr[0].value.size()) == arr[0].value) {
                            cout << fnd(prefix,0).second + 1 << endl;
                        }
                        else {
                            cout << 1 << endl;
                        }
                    }
                }
            }
        }
        return 0;
    }
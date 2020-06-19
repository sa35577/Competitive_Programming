#include <bits/stdc++.h>
using namespace std;

int main() {
    char quiz[30][30];
    int R, C, M;
    cin >> R >> C;
    for (int i = 0 ; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> quiz[i][j];
        }
    }
    cin >> M;
    vector<string> clues;
    string newClue,boob="";
    getline(cin, newClue);
    for(int i = 0; i < M; i++){
        getline(cin, newClue);
        cin.ignore(0);
        for (int j = 0; j < newClue.size(); j++) {
            if (newClue[j] != ' ') boob += newClue[j];
        }
        newClue = boob;
        clues.push_back(newClue);
        boob = "";

    }
    for(int i = 0 ;i < M; i++){
        cout << clues[i] << endl;
    }
    
    bool checked[30][30] = {false};
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            for(int l = 0; l < clues.size(); l++){
                string tryClue = clues[l];
                if (i + tryClue.size() < R){
                    vector<char> test;
                    for(int k = i; k < tryClue.size(); k++){
                        test.push_back(quiz[k][j]);
                    }
                    if (equal(test.begin(), test.end(), tryClue.begin())){
                        clues.erase(clues.begin() + l);
                        for(int k = i; k < tryClue.size(); k++){
                            checked[k][j] = 1;
                        }
                        continue;
                    }
                }
                if (j + tryClue.size() < C){
                    vector<char> test;
                    for(int k = j; k < tryClue.size(); k++){
                        test.push_back(quiz[i][k]);
                    }
                    if (equal(test.begin(), test.end(), tryClue.begin())){
                        clues.erase(clues.begin() + l);
                        for(int k = j; k < tryClue.size(); k++){
                            checked[i][k] = 1;
                        }
                        continue;
                    }
                }
                if (i - tryClue.size() >= 0){
                    vector<char> test;
                    for(int k = i; k > i - tryClue.size(); k--){
                        test.push_back(quiz[k][j]);
                    }
                    if (equal(test.begin(), test.end(), tryClue.begin())){
                        clues.erase(clues.begin() + l);
                        for(int k = i; k > i - tryClue.size(); k--){
                            checked[k][j] = 1;
                        }
                        cout << "got milk baby" << " " << tryClue << endl;
                        continue;
                    }
                }
                if (j - tryClue.size() >= 0){
                    vector<char> test;
                    for(int k = j; k > j - tryClue.size(); k--){
                        test.push_back(quiz[i][k]);
                    }
                    if (equal(test.begin(), test.end(), tryClue.begin())){
                        clues.erase(clues.begin() + l);
                        for(int k = j; k > j - tryClue.size(); k--){
                            checked[i][k] = 1;
                        }
                        continue;
                    }
                }
                if (i + tryClue.size() < R && j + tryClue.size() < C){
                    vector<char> test;
                    for(int k = 0; k < tryClue.size(); k++){
                        test.push_back(quiz[i+k][j+k]);
                    }
                    if (equal(test.begin(), test.end(), tryClue.begin())){
                        clues.erase(clues.begin() + l);
                        for(int k = 0; k < tryClue.size(); k++){
                            checked[i+k][j+k] = 1;
                        }
                        continue;
                    }
                }
                if (i + tryClue.size() < R && j - tryClue.size() >= 0){
                    vector<char> test;
                    for(int k = 0; k < tryClue.size(); k++){
                        test.push_back(quiz[i+k][j-k]);
                    }
                    if (equal(test.begin(), test.end(), tryClue.begin())){
                        clues.erase(clues.begin() + l);
                        for(int k = 0; k < tryClue.size(); k++){
                            checked[i+k][j-k] = 1;
                        }
                        continue;
                    }
                }
                if (i - tryClue.size() >= 0 && j + tryClue.size() < C){
                    vector<char> test;
                    for(int k = 0; k < tryClue.size(); k++){
                        test.push_back(quiz[i-k][j+k]);
                    }
                    if (equal(test.begin(), test.end(), tryClue.begin())){
                        clues.erase(clues.begin() + l);
                        for(int k = 0; k < tryClue.size(); k++){
                            checked[i-k][j+k] = 1;
                        }
                        continue;
                    }
                }
                if (i - tryClue.size() >= 0 && j - tryClue.size() >= 0){
                    vector<char> test;
                    for(int k = 0; k < tryClue.size(); k++){
                        test.push_back(quiz[i-k][j-k]);
                    }
                    if (equal(test.begin(), test.end(), tryClue.begin())){
                        clues.erase(clues.begin() + l);
                        for(int k = 0; k < tryClue.size(); k++){
                            checked[i-k][j-k] = 1;
                        }
                        continue;
                    }
                }
            }
        }
    }
    string finalOut = "";
    for(int i = 0 ; i < R; i++){
        for(int j = 0; j < C; j++){
            if (!checked[i][j]) finalOut += quiz[i][j];
        }
    }
    cout << finalOut << endl;
}
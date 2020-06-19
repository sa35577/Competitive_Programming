    #include <bits/stdc++.h>
    using namespace std;
    int ints, upperLets, lowerLets, symbols,score,sz;
    string word;

    bool isInt(char c) {
        int code = (int)c;
        return code >= 48 && code <= 57;
    }

    bool isUpper(char c) {
        int code = (int)c;
        return code >= 65 && code <= 90;
    }

    bool isLower(char c) {
        int code = (int)c;
        return code >= 97 && code <= 122;
    }
    bool isLetter(char c) {
        return isUpper(c) || isLower(c);
    }
    bool isSymbol(char c) {
        return !(isInt(c) || isUpper(c) || isLower(c));
    }

    void consUpper() {
        int cur = 0;
        while (cur < sz) {
            int len = 0;
            while (!isUpper(word[cur])) {
                ++cur;
                if (cur == sz) break;
            }
            if (cur == sz) break;
            while (isUpper(word[cur])) {
                ++len;
                ++cur;
                if (cur == sz) {
                    score -= 2*(len-1);
                    len = 0;
                    break;
                }
            }
            if (cur == sz) break;
            score -= 2*(len-1);
            len = 0;
        }
    }
    void consLower() {
        int cur = 0;
        while (cur < sz) {
            int len = 0;
            while (!isLower(word[cur])) {
                ++cur;
                if (cur == sz) break;
            }
            if (cur == sz) break;
            while (isLower(word[cur])) {
                ++len;
                ++cur;
                if (cur == sz) {
                    score -= 2*(len-1);
                    len = 0;
                    break;
                }
            }
            if (cur == sz) break;
            score -= 2*(len-1);
            len = 0;
        }
    }
    void consInt() {
        int cur = 0;
        while (cur < sz) {
            int len = 0;
            while (!isInt(word[cur])) {
                ++cur;
                if (cur == sz) break;
            }
            if (cur == sz) break;
            while (isInt(word[cur])) {
                ++len;
                ++cur;
                if (cur == sz) {
                    score -= 2*(len-1);
                    len = 0;
                    break;
                }
            }
            if (cur == sz) break;
            score -= 2*(len-1);
            len = 0;
        }
    }
    bool isCons(string s) {
        if (s.size() <= 1) return true;
        if (s.size() == 2) {
            return abs(int(s[0])-int(s[1])) == 1;
        }
        return int(s[s.size()-2])-int(s[s.size()-1]) == int(s[0])-int(s[1]) && abs(int(s[s.size()-2])-int(s[s.size()-1])) == 1;
    }
    void seqLetter() {
        int cur = 0,mx=0;
        while (cur < sz) {
            int len = 0;
            while (!isLetter(word[cur])) {
                ++cur;
                if (cur == sz) break;
            }
            if (cur == sz) break;
            string s = "";
            while (isLetter(word[cur])&&isCons(s+word[cur])) {
                s += word[cur];
                ++len;
                ++cur;
                if (cur == sz) {
                    mx = max(mx,len);
                    len = 0;
                    break;
                }
            }
            if (cur == sz) break;
            mx = max(mx,len);
            len = 0;
        }
        if (mx >= 2) score -= 3*(mx-2);
    }
    void seqInt() {
        int cur = 0,mx=0;
        while (cur < sz) {
            int len = 0;
            while (!isInt(word[cur])) {
                ++cur;
                if (cur == sz) break;
            }
            if (cur == sz) break;
            string s = "";
            while (isInt(word[cur])&&isCons(s+word[cur])) {
                s += word[cur];
                ++len;
                ++cur;
                if (cur == sz) {
                    mx = max(mx,len);
                    len = 0;
                    break;
                }
            }
            if (cur == sz) break;
            mx = max(mx,len);
            len = 0;
        }
        if (mx >= 2) score -= 3*(mx-2);
    }


    int main() {
        //48-57 --> int
        //65-90 --> upper let
        //97-122 -> lower let
        //other --> symbol
        
        for (int tc = 0; tc < 10; tc++) {
            score = 0;
            ints = 0;
            lowerLets = 0;
            upperLets = 0;
            symbols = 0;
            cin >> word;
            sz = word.size();
            for (char c : word) {
                int code = (int)c;
                if (isInt(code)) ints++;
                else if (isUpper(code)) upperLets++;
                else if (isLower(code)) lowerLets++;
                else symbols++;

            }
            score += 4*sz;
            //printf("%d\n",score);
            int miss=0;
            if (ints == 0) miss++;
            if (lowerLets == 0) miss++;
            if (upperLets == 0) miss++;
            if (symbols == 0) miss++;
            if (sz >= 8 && miss <= 1) {
                score += 2;
                score += 2*(4-miss);
            }
            if (upperLets > 0) {
                score += (sz-upperLets)*2;
            }
            if (lowerLets > 0) {
                score += (sz-lowerLets)*2;
            }
            if (ints != sz) {
                score += 4*ints;
            }
            printf("%d\n",score);
            score += symbols*6;
            score += 2*(ints+symbols);
            if (!isLetter(word[0])) score -= 2;
            if (!isLetter(word[sz-1])&&sz!=1) score -= 2;
            //printf("%d\n",score);
            if (upperLets + lowerLets == sz) score -= sz;
            //printf("%d\n",score);
            if (ints == sz) score -= sz;
            //printf("%d\n",score);
            //printf("%d\n",score);
            consUpper();
            printf("%d\n",score);
            consLower();
            printf("%d\n",score);
            consInt();
            printf("%d\n",score);
            seqLetter();
            printf("%d\n",score);
            seqInt();
            printf("%d\n",score);
            if (score > 100) score = 100;
            if (score < 0) score = 0;

            if (score <= 20) {
                printf("Very Weak (score = %d)",score);
            }
            else if (score <= 40) {
                printf("Weak (score = %d)",score);
            }
            else if (score <= 60) {
                printf("Good (score = %d)",score);
            }
            else if (score <= 80) {
                printf("Strong (score = %d)",score);
            }
            else {
                printf("Very Strong (score = %d)",score);
            }
            printf("\n");
        }
    }
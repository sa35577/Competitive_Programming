#include <bits/stdc++.h>
using namespace std;
#define npm next_permutation
bool valid(const string&s)
{
    int r1=s.find('R');
    int r2=s.find_last_of('R');
    if(s.find('K')>r1&&s.find('K')<r2) {
        return(s.find('B')&1)!=(s.find_last_of('B')&1);
    }
    return false;
}
bool check(const string&r,const string&s)
{
    for(unsigned int i=0;i<r.size();i++)
    {
        if(r[i]!='_')
        {
            if(r[i]!=s[i])
                return false;
        }
    }
    return true;
}
string __r="BBKNNQRR";
int main() {
    string s="";
    string u="";
    unsigned int cnt=0;
    for(int t=0;t<10;t++) {
        cin>>s;
        u=__r;
        cnt=0;
        if(valid(u)&&check(s,u))
        {
            cnt++;
        }
        npm(u.begin(),u.end());
        while(u!=__r)
        {
            if(valid(u)&&check(s,u))
            {
                cnt++;
            }
            npm(u.begin(),u.end());
        }
        cout<<cnt<<endl;
    }

}
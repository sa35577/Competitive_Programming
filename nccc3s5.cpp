#include <bits/stdc++.h>
#include <unordered_set>
#include <stdio.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define f first
#define s second
#define ll long long
#define ull unsigned long long
#define ld long double
#define endl "\n"
#define PI 3.141592653589793
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int,int>
#define pll pair<ll,ll>
const int MOD = 1000000007;
inline double degcos(double ang) {return cos(ang*PI/180);}
inline double degsin(double ang) {return sin(ang*PI/180);}
#define rep(i,j,k,in) for (int i = j; i < k; i += in)
#define repr(i,j,k,in) for (int i = j; i > k; i -= in)
#define repll(i,j,k,in) for (ll i = j; i < k; i += in)
#define repllr(i,j,k,in) for (ll i = j; i > k; i -= in)

/*---END OF TEMPLATE---*/

const int MAXP = 2000006;
struct Node {
    int L;
    int R;
    ll lazy = 0;
    bool reset = 0;
    ll val = 0;
    ll cnt = 0;
    friend Node operator+(Node n1, Node n2) {
        return {n1.L, n2.R, 0, 0, n1.val+n2.val, n1.cnt+n2.cnt};
    }
    void clear() {
        reset = 1;
        val = 0;
        cnt = 0;
        lazy = 0;
    }
} seg[4*MAXP];

void build_tree(int v, int L, int R) {
    seg[v].L = L;
    seg[v].R = R;
    seg[v].lazy = seg[v].reset = seg[v].val = seg[v].cnt = 0;
    if (L == R) { return; }
    int mid = (L+R)>>1;
    build_tree(v<<1,L,mid);
    build_tree(v<<1|1,mid+1,R);
}
void push_lazy(int v) {
    int L = seg[v].L, R = seg[v].R, mid = (L+R)>>1;
    if (seg[v].lazy != 0) {
        seg[v<<1].cnt += seg[v].lazy*(mid-L+1);
        seg[v<<1].val += seg[v].lazy*(mid-L+1)*(mid+L)/2;//lazy * sum of numbers
        seg[v<<1].lazy += seg[v].lazy;
        seg[v<<1|1].cnt += seg[v].lazy*(R-(mid+1)+1);
        seg[v<<1|1].val += seg[v].lazy*(R-(mid+1)+1)*((mid+1)+R)/2;//lazy * sum of numbers
        seg[v<<1|1].lazy += seg[v].lazy;
    }
    if (seg[v].reset) {
        seg[v<<1].lazy = seg[v<<1|1].lazy = 0;
        seg[v<<1].cnt = seg[v<<1|1].cnt = 0;
        seg[v<<1].val = seg[v<<1|1].val = 0;
        seg[v<<1].reset = seg[v<<1|1].reset = 1;
    }
    seg[v].lazy = 0;
    seg[v].reset = 0;
}

void add(int v, int k, int p) {
    int L = seg[v].L, R = seg[v].R;
    if (p < L || R < p) {
        return;
    }
    if (L < R) push_lazy(v);
    if (L == R) {
        seg[v].cnt += k;
        seg[v].val += ((ll)k)*((ll)p);
        //seg[v].lazy += k;
        return;
    }
    add(v<<1,k,p);
    add(v<<1|1,k,p);
    seg[v] = seg[v<<1] + seg[v<<1|1];
}

void addRange(int v, int UL, int UR) {
    int L = seg[v].L, R = seg[v].R;
    if (UR < L || R < UL) {
        return;
    }
    if (L < R) push_lazy(v);
    if (UL <= L && R <= UR) {
        seg[v].val += ((ll)(R-L+1))*((ll)(L+R))/2;
        seg[v].cnt += (ll)(R-L+1);
        seg[v].lazy += 1LL;
        return;
    }
    addRange(v<<1,UL,UR);
    addRange(v<<1|1,UL,UR);
    seg[v] = seg[v<<1] + seg[v<<1|1];
}

ll buyAmt(int v, ll Q) { //current node, amount of money remaining (find max # of cones)
    int L = seg[v].L, R = seg[v].R;
    if (L < R) push_lazy(v);
    ll ans;
    if (L == R) {
        ans = min(Q/L,seg[v].cnt);
        
        seg[v].cnt -= ans;
        seg[v].val -= ans*L;
        return ans;
    }
    if (seg[v<<1].val >= Q) ans = buyAmt(v<<1,Q);
    else {
        ans = seg[v<<1].cnt + buyAmt(v<<1|1,Q-seg[v<<1].val);
        seg[v<<1].clear();
    }
    seg[v] = seg[v<<1] + seg[v<<1|1];
    return ans;

}

ll buyLowHigh(int v, ll Q, bool low) {
    int L = seg[v].L, R = seg[v].R;
    if (L < R) push_lazy(v);
    ll ans;
    if (L == R) {
        ans = min(Q,seg[v].cnt);
        seg[v].cnt -= ans;
        ans = ans * ((ll)L);
        seg[v].val -= ans;
        return ans;
    }
    if (low) {
        if (seg[v<<1].cnt >= Q) {
            ans = buyLowHigh(v<<1,Q,low);
        }
        else {
            ans = seg[v<<1].val + buyLowHigh(v<<1|1,Q-seg[v<<1].cnt,low);
            seg[v<<1].clear();
        }
    }
    else {
        if (seg[v<<1|1].cnt >= Q) {
            ans = buyLowHigh(v<<1|1,Q,low);
        }
        else {
            ans = seg[v<<1|1].val + buyLowHigh(v<<1,Q-seg[v<<1|1].cnt,low);
            seg[v<<1|1].clear();
        }
    }
    seg[v] = seg[v<<1] + seg[v<<1|1];
    return ans;
}

ll cost(int v, ll Q) {
    int L = seg[v].L, R = seg[v].R;
    if (L == R) return L;
    push_lazy(v);
    if (seg[v<<1].cnt >= Q) {
        return cost(v<<1,Q);
    }
    else return cost(v<<1|1,Q-seg[v<<1].cnt);
}



int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    //ifstream fin("data.in");
    //ofstream fout("data.out");
    int N,K,P,A,B;
    ll Q,L;
    string qType;
    cin >> N;
    build_tree(1,1,MAXP);
    while (N--) {
        cin >> qType;
        if (qType == "ADD") {
            cin >> K >> P;
            add(1,K,P);
        }
        else if (qType == "ADDRANGE") {
            cin >> A >> B;
            addRange(1,A,B);
        }
        else if (qType == "BUYAMT") {
            cin >> Q;
            cout << buyAmt(1,Q) << endl;
        }
        else if (qType == "BUYLOW") {
            cin >> L;
            cout << buyLowHigh(1,L,1) << endl;
        }
        else if (qType == "BUYHIGH") {
            cin >> L;
            cout << buyLowHigh(1,L,0) << endl;
        }
        else if (qType == "COST") {
            cin >> L;
            if (seg[1].cnt < L) cout << -1 << endl;
            else cout << cost(1,L) << endl;
        }
        else if (qType == "NUMCONES") {
            cout << seg[1].cnt << endl;
        }
        else if (qType == "TOTALCOST") {
            cout << seg[1].val << endl;
        }        
    }
}
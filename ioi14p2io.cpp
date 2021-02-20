#include <bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
const int N = 2000010,K = 500000;
struct Node {
    int L,R,lazyMin = -5,lazyMax = 1e9;
} seg[4*N];

inline void build_tree(int v, int L, int R) {
    seg[v].L = L;
    seg[v].R = R;
    if (L == R) return;
    int mid = (L+R)>>1;
    build_tree(v<<1,L,mid);
    build_tree(v<<1|1,mid+1,R);
}

inline void setMin(int v, int val) {
    seg[v].lazyMax = max(seg[v].lazyMax,val);
    seg[v].lazyMin = max(seg[v].lazyMin,val);
}

inline void setMax(int v, int val) {
    seg[v].lazyMax = min(seg[v].lazyMax,val);
    seg[v].lazyMin = min(seg[v].lazyMin,val);
}

inline void push_lazy(int v) {
    if (seg[v].L == seg[v].R) return;
    
    setMin(v<<1,seg[v].lazyMin);
    setMax(v<<1,seg[v].lazyMax);
    setMin(v<<1|1,seg[v].lazyMin);
    setMax(v<<1|1,seg[v].lazyMax);
    seg[v].lazyMax = 1e9;
    seg[v].lazyMin = -5;
    return;
}

inline void updateMin(int v, int UL, int UR, int H) {
    int L = seg[v].L, R = seg[v].R;
    if (R < UL || UR < L) return;
    push_lazy(v);
    if (UL <= L && R <= UR) {
        setMin(v,H);
        return;
    }
    updateMin(v<<1,UL,UR,H);
    updateMin(v<<1|1,UL,UR,H);
    return;
}

inline void updateMax(int v, int UL, int UR, int H) {
    int L = seg[v].L, R = seg[v].R;
    if (R < UL || UR < L) return;
    push_lazy(v);
    if (UL <= L && R <= UR) {
        setMax(v,H);
        return;
    }
    updateMax(v<<1,UL,UR,H);
    updateMax(v<<1|1,UL,UR,H);
}
int arr[N];
inline void search(int v) {
    if (seg[v].L == seg[v].R) {
        arr[seg[v].L] = seg[v].lazyMin;
        return;
    }
    push_lazy(v);
    search(v<<1);
    search(v<<1|1);
    return;
}

/*void buildWall(int n, int k, int op[], int left[], int right[], int height[], int finalHeight[]) {
    build_tree(1,0,n-1);
    int type,l,r,h;
    for (int zz = 0; zz < k; zz++) {
        type = op[zz];
        l = left[zz];
        r = right[zz];
        h = height[zz];
        if (type == 1) {
            updateMin(1,l,r,h);
        }
        else {
            updateMax(1,l,r,h);
        }
    }
    search(1);
    for (int i = 0; i < n; i++) {
        if (arr[i] == -5) finalHeight[i] = 0;
        else finalHeight[i] = arr[i];
    }
}*/

int n,k,op[K],lefty[K],righty[K],heighty[K];
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    scan(n);scan(k);
    for (int i = 0; i < k; i++) { 
        
        scan(op[i]);
        scan(lefty[i]);
        scan(righty[i]);
        scan(heighty[i]);
    }
    //buildWall(n,k,op,lefty,righty,heighty,finalHeighty);
    
    build_tree(1,0,n-1);
    int type,l,r,h;
    for (int zz = 0; zz < k; zz++) {
        type = op[zz];
        l = lefty[zz];
        r = righty[zz];
        h = heighty[zz];
        if (type == 1) {
            updateMin(1,l,r,h);
        }
        else {
            updateMax(1,l,r,h);
        }
    }
    search(1);
    for (int i = 0; i < n; i++) {
        if (arr[i] == -5) cout << 0 << "\n";
        else cout << arr[i] << "\n";
    }
    
    return 0;
    
}
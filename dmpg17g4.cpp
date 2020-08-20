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
#define endl "\n"
#define PI 3.141592653589793
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int,int>
const int MOD = 1000000007;
inline double degcos(double ang) {return cos(ang*PI/180);}
inline double degsin(double ang) {return sin(ang*PI/180);}
#define rep(i,j,k,in) for (int i = j; i < k; i += in)
#define repr(i,j,k,in) for (int i = j; i > k; i -= in)
#define repll(i,j,k,in) for (ll i = j; i < k; i += in)
#define repllr(i,j,k,in) for (ll i = j; i > k; i -= in)

/*---END OF TEMPLATE---*/

struct node {
    int val;
    node *left = NULL, *right = NULL;
    int height = 0;
    int cnt,sz;
};

struct Tree {
    node *root;
    bool switched;
    void updateSum(node *n) {
        if (n == NULL) return;
        n->sz = n->cnt + (n->left == NULL ? 0 : n->left->sz) + (n->right == NULL ? 0 : n->right->sz);
    }
    int getHeight(node *cur) {
        return (cur == NULL ? -1 : cur->height);
    }
    void insert(int v) {
        root = insert(v,root);
        updateSum(root);
    }
    void remove(int v) {
        switched = false;
        root = remove(v,root);
        updateSum(root);
    }
    int firstOccurence(int v) {
        return firstOccurence(v,root);
    }
    int nthElement(int n) {
        return nthElement(n,root);
    } 

    node* insert(int v, node *cur) {

        if (cur == NULL) {
            cur = new node;
            cur->height = 0;
            cur->val = v;
            cur->left = cur->right = NULL;
            cur->cnt = cur->sz = 1;

        }
        else if (cur->val == v) {
            ++cur->cnt; ++cur->sz;
        }
        else if (v < cur->val) {
            cur->left = insert(v,cur->left);
            updateSum(cur);
            if ((getHeight(cur->left) - getHeight(cur->right) == 2)) {
                if (v < cur->left->val) {
                    //LL Rotation
                    cur = LL(cur);
                }
                else {
                    //LR Rotation
                    cur = LR(cur);
                }
            }
        }
        else if (v > cur->val) {
            cur->right = insert(v,cur->right);
            updateSum(cur);
            if (getHeight(cur->left) - getHeight(cur->right) == -2) {
                if (v < cur->right->val) {
                    //RL Rotation
                    cur = RL(cur);
                }
                else {
                    //RR Rotation
                    cur = RR(cur);
                }
            }
        }
        cur->height = max(getHeight(cur->left), getHeight(cur->right));
        ++cur->height;
        return cur;
    }
    node* remove(int v, node* t) {
        node *mn;
        //printf("%d\n",t->val);
        if (t == NULL) return t;
        else if (v < t->val) {
           // printf("%d\n",1);
            t->left = remove(v,t->left);
            updateSum(t);
        }
        else if (v > t->val) {
          //  printf("%d\n",2);
            t->right = remove(v,t->right);
            updateSum(t);
        }
        else if (t->left != NULL && t->right != NULL) {
          //  printf("%d\n",3);
            if (t->cnt > 1) {
                --t->cnt;
                --t->sz;
                return t;
            }
            mn = t->right;
            while (mn->left != NULL) mn = mn->left;
            t->val = mn->val; t->cnt = mn->cnt;
            switched = true;
            t->right = remove(t->val,t->right);
        }
        else { 
           // printf("%d\n",4);
            if (t->cnt > 1 && !switched) {

                --t->cnt;
                --t->sz;
                return t;
            }   

            mn = t;
            if (t->right == NULL) t = t->left;
            else if (t->left == NULL) t = t->right;
            delete mn;

        }
        
        if (t == NULL) return t;
        updateSum(t); 
        t->height = max(getHeight(t->left),getHeight(t->right));
        ++t->height;
        if (getHeight(t->left) - getHeight(t->right) == 2) {
            if (getHeight(t->left->left) - getHeight(t->left->right) == 1) {
                return RR(t);
            }
            else {
                return RL(t);
            }
        }
        else if (getHeight(t->left) - getHeight(t->right) == -2) {
            if (getHeight(t->right->right) - getHeight(t->right->left) == -1) {
                return LL(t);
            }
            else {
                return LR(t);
            }
        }
        return t;
    }
    int firstOccurence(int v, node* cur) {
        if (cur == NULL) return -1;
        if (v < cur->val) return firstOccurence(v,cur->left);
        else if (v == cur->val) {
            return (cur->left == NULL ? 0 : cur->left->sz) + 1;
        }
        else {
            int bck = firstOccurence(v,cur->right);
            if (bck >= 0) {
                bck = bck + (cur->left == NULL ? 0 : cur->left->sz) + cur->cnt;
            }
            return bck;
        }
    }
    int nthElement(int n, node* cur) {
        
        int cntLeft = (cur->left == NULL ? 0 : cur->left->sz);
        if (n <= cntLeft) return nthElement(n,cur->left);
        n -= cntLeft;
        if (n <= cur->cnt) return cur->val;
        n -= cur->cnt;
        return nthElement(n,cur->right);
    }
    node* LL(node* &old) {
        if (old == NULL) return old;
        else if (old->left == NULL) return old;
        node* n = old->left;
        old->left = n->right;
        n->right = old;
        old->height = max(getHeight(old->left), getHeight(old->right));
        ++old->height;
        n->height = max(old->height,getHeight(n->left));
        ++n->height;
        updateSum(old); updateSum(n);
        return n;
    }
    node* RR(node* &old) {
        if (old == NULL) return old;
        else if (old->right == NULL) return old;
        node* n = old->right;
        old->right = n->left;
        n->left = old;
        old->height = max(getHeight(old->left),getHeight(old->right));
        ++old->height;
        n->height = max(old->height,getHeight(old->right));
        ++n->height;
        updateSum(old); updateSum(n);
        return n;
    }
    node *RL(node* &old) {
        old->right = LL(old->right);
        return RR(old);
    }
    node *LR(node* &old) {
        old->left = RR(old->left);
        return LL(old);
    }
    vector<int> stringify() {
        
        return stringify(root);
    }
    vector<int> stringify(node* curNode) {
        if (curNode == NULL) return vector<int>();
        vector<int> ret;
        for (int i : stringify(curNode->left)) ret.push_back(i);
        for(int val = 0; val < curNode->cnt; val++)
            ret.push_back(curNode->val);
        for (int i : stringify(curNode->right)) ret.push_back(i);
        return ret;
        
        //return stringify(curNode->left) + " " + (to_string(curNode->val) + " " + to_string(curNode->sz)) + " " + stringify(curNode->right);
    }

} tree;



int main() {
    //cin.sync_with_stdio(0);
    //cin.tie(0);
    //ifstream fin("data.in");
    //ofstream fout("data.out");
    tree.root = NULL;
    int n,m;
    int val;
    char opType;
    int v, lastAns = 0;
    cin >> n >> m;
    rep(i,0,n,1) {
        cin >> val;
        tree.insert(val);
    }
    rep(i,0,m,1) {
        cin >> opType >> v;
        v = v ^ lastAns;
        //printf("%d\n",v);
        if (opType == 'I') {
            tree.insert(v);
        }
        else if (opType == 'R') {
            tree.remove(v);
        }
        else if (opType == 'S') {
            lastAns = tree.nthElement(v);
            printf("%d\n",lastAns);
        }
        else if (opType == 'L') {
            lastAns = tree.firstOccurence(v);
            printf("%d\n",lastAns);
        }
    }
    for (int j : tree.stringify()) cout << j << " ";
        cout << endl;
}
#include <bits/stdc++.h>
#include <unordered_set>
#include <stdio.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define PI 3.141592653589793
#define vi vector<int>
#define vll vector<long long>
#define p pair<int,int>
const int MOD = 1000000007;
inline double degcos(double ang) {return cos(ang*PI/180);}
inline double degsin(double ang) {return sin(ang*PI/180);}
#define rep(i,j,k,in) for (int i = j; i < k; i += in)


/*---END OF TEMPLATE---*/

struct BNode {
    int val;
    BNode * left;
    BNode * right;
    BNode(int v) {
        val = v;
        left = right = nullptr;
    }
};

struct BTree {
    BNode * root;
    BTree() {
        root = new BNode(INT_MIN);
    }
    void insert(int v) {
        if (root->val == INT_MIN) {
            root->val = v;
        }    
        else add(root,v);
    }
    void add(BNode * branch, int v) {
        if (v < branch->val) {
            if (!branch->left) {
                branch->left = new BNode(v);
            }
            else add(branch->left,v);
        }
        else if (v > branch->val) {
            if (!branch->right) {
                branch->right = new BNode(v);
            }
            else add(branch->right,v);
        }
    }
    string display() {
        string s = stringify(root);
        if (s.size() > 0) {
            s.pop_back(); s.pop_back();
        }
        return s;
    }
    string stringify(BNode * branch) {
        if (branch == NULL) {
            return "";
        }   
        return stringify(branch->left) + to_string(branch->val) + ", " + stringify(branch->right); 
    }
    BNode* find(int v) {
        BNode* tmp = find(root,v);

    }
    BNode* find(BNode* branch, int v) {
        if (!branch || branch->val == v) return branch;
        if (v < branch->val) {
            return find(branch->left,v);
        }
        else if (v > branch ->val) {
            return find(branch->right,v);
        }
    }
};


int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    //ifstream fin("data.in");
    //ofstream fout("data.out");
    BTree y;
    y.insert(5);
    y.insert(6);
    y.insert(3);
    y.insert(4);
    y.insert(57);
    string s = y.display();
    cout << s;

}

void ost_del_node(struct __ost *ost, struct __ostn *node)
{
    if (ost->size == 1 && node->up == NULL)
    {
        free(ost->rt);
        ost->rt = NULL;
    }
    else if (node->left != NULL && node->right != NULL)
    {
        struct __ostn *tmp = node->right;
        while (tmp->left != NULL)
            tmp = tmp->left;
        int tmpv = node->val, tmpid = node->id;
        node->val = tmp->val, node->id = tmp->id;
        tmp->val = tmpv, tmp->id = tmpid;
        ost_del_node(ost, tmp);
        return;
    }
    else if (node->left == NULL)
    {
        struct __ostn *child = node->right, *p = node->up;
        if (p == NULL)
        {
            free(ost->rt);
            ost->rt = child;
            child->up = NULL;
        }
        else if (p->left == node)
        {
            free(p->left);
            p->left = child;
            if (child != NULL)
                child->up = p;
        }
        else
        {
            free(p->right);
            p->right = child;
            if (child != NULL)
                child->up = p;
        }
        stat_update_ost(p);
        fix_ost_node(ost, p);
    }
    else if (node->right = NULL)
    {
        struct __ostn *child = node->left, *p = node->up;
        if (p == NULL)
        {
            free(ost->rt);
            ost->rt = child;
            child->up = NULL;
        }
        else if (p->left == node)
        {
            free(p->left);
            p->left = child;
            child->up = p;
        }
        else
        {
            free(p->right);
            p->right = child;
            child->up = p;
        }
        stat_update_ost(p);
        fix_ost_node(ost, p);
    }
    --ost->size;
}
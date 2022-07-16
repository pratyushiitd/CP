// https://codeforces.com/edu/course/2/lesson/5/1/practice/contest/279634/problem/C
#include <bits/stdc++.h>

using namespace std;

#define int long long


const int neutral = 0;
const int NO_OPERATION = LLONG_MAX;

struct lazy_segtree{
    int size;
    vector<int> operations;
    
    int operation(int a, int b){
        if (b == NO_OPERATION)return a;
        return b;
    }
    void apply_op(int &a, int b){
        a = operation(a, b);
    }
    void propagate(int x, int lx, int rx){
        if (rx-lx == 1)return;
        apply_op(operations[2*x+1], operations[x]);
        apply_op(operations[2*x+2], operations[x]);
        operations[x] = NO_OPERATION;
    }
    void init(int n){
        size = 1;
        while(size < n){
            size*=2;
        }
        operations.assign(2*size, 0ll);
    }

    void modify(int l, int r, int val, int x, int lx, int rx){
        propagate(x, lx, rx);
        if (rx<=l || r<=lx)return;
        if (rx<=r && lx>=l){
            apply_op(operations[x], val);
            return;
        }
        int m = (lx + rx) / 2;
        modify(l, r, val, 2*x+1, lx, m);
        modify(l, r, val, 2*x+2, m , rx);
    }
    void modify(int l, int r, int val){
        modify(l,r, val, 0, 0, size);
    }
    
    int get(int i, int x, int lx, int rx){
        propagate(x, lx, rx);
        if (rx - lx == 1)return operations[x];
        int m = (lx+rx)/2;
        if (i < m)return get(i, 2*x+1, lx, m);
        else return get(i, 2*x+2, m, rx);
    }
    int get(int i){
        return get(i, 0, 0, size);
    }
};

void solve(){
    int n, m; cin >> n >> m;
    lazy_segtree st;
    st.init(n);
    while(m--){
        int t; cin >> t;
        if (t==1){
            int l, r, val; cin >> l >> r >> val;
            st.modify(l, r, val);
        }
        else {
            int i; cin >> i;
            cout << st.get(i) << endl;
        }
    }
}
int32_t main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    // cin >> t;
    while(t--)solve();
    return 0;
}

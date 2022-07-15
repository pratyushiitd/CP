// https://codeforces.com/edu/course/2/lesson/4/3/practice/contest/274545/problem/E
#include <bits/stdc++.h>

using namespace std;

#define int int64_t

// x ->curr node, 
// left -> 2x+1, right -> 2x+2

// Borders x-> [lx,rx-1], 
// m = (lx+rx)/2, 
// left -> [lx,m-1], right -> [m, rx-1];

const pair<int, int> neutral = {INT_MAX, 0};
struct segtree{
    
    int size; 
    vector<int> vec;
    int merge(int a, int b){return a+b;}
    void build(vector<int> &arr, int x, int lx, int rx){
        if (rx - lx == 1){
            if (lx <= (int)arr.size()-1)vec[x] = arr[lx];
            return;
        }
        int m = (lx + rx) / 2;
        build(arr, 2*x+1, lx, m);
        build(arr, 2*x+2, m, rx);
        vec[x] = merge(vec[2*x+1],vec[2*x+2]);
    }
    void build(vector<int> &arr){
        build(arr, 0, 0, size);
    }
    void init(int n){
        size = 1;
        while(size < n){size *=2;}
        vec.assign(2*size, (int)0);
    }
    
    void set(int i, int val, int lx, int rx, int x){
        if (rx - lx == 1){
            vec[x] += val;
            return;
        }
        int m = (lx + rx) / 2;
        if (i < m)set(i, val, lx, m, 2*x+1);
        else set(i, val, m, rx, 2*x+2);
        vec[x] = merge(vec[2*x+1], vec[2*x+2]);
    }
    void set(int i, int val){
        set(i, val, 0, size, 0);
    }
    
    int func(int l, int r, int x, int lx, int rx){
        if (l >= rx || r <= lx){
            return 0;
        }
        if ( lx >= l && rx <= r)return vec[x];
        int m = (lx+rx)/2;
        return merge(func(l, r, 2*x+1, lx, m), func(l, r, 2*x+2, m, rx));
    }
    int func(int l, int r){
        return func(l,r, 0, 0, size);
    }
};
int32_t main(){
    ios::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    segtree st;
    st.init(n+1);
    for(int i = 1; i <= m; i++){
        int t; cin >> t;
        if (t==1){
            int l, r, v; cin >> l >> r >> v;
            st.set(l, v);
            st.set(r, -v);
        }
        else{
            int i; cin >> i;
            cout << st.func(0, i+1) << "\n";
        }
    }

    return 0;
}
// 1 1 0 0 1 0 0 0 0 0

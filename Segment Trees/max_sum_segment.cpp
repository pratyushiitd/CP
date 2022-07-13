//https://codeforces.com/edu/course/2/lesson/4/2/practice/contest/273278/problem/A#include <bits/stdc++.h>

using namespace std;

#define int long long

// x ->curr node, 
// left -> 2x+1, right -> 2x+2

// Borders x-> [lx,rx-1], 
// m = (lx+rx)/2, 
// left -> [lx,m-1], right -> [m, rx-1];

const pair<int, int> neutral = {INT_MAX, 0};
struct segtree{
    
    int size; 
    vector<int> sums;
    vector<int> pref;
    vector<int> suff;
    vector<int> seg;

    int merge(int s1, int s2){
        
        return s1+s2;
    }
    void build(vector<int> &arr, int x, int lx, int rx){
        if (rx - lx == 1){
            if (lx <= (int)arr.size()-1){
                sums[x] = arr[lx];
                pref[x] = max(0ll, arr[lx]);
                suff[x] = max(0ll, arr[lx]);
                seg[x] = max(0ll, arr[lx]);
                // pref[x] = arr[lx];
                // suff[x] = arr[lx];
                // seg[x] = arr[lx];
                
            }
            return;
        }
        int m = (lx + rx) / 2;
        build(arr, 2*x+1, lx, m);
        build(arr, 2*x+2, m, rx);
        sums[x] = merge(sums[2*x+1],sums[2*x+2]);
        pref[x] = max(pref[2*x+1], sums[2*x+1]+pref[2*x+2]);
        suff[x] = max(suff[2*x+2], suff[2*x+1]+sums[2*x+2]);
        seg[x] = max(max(seg[2*x+1], seg[2*x+2]),pref[2*x+2]+suff[2*x+1]);
    }
    void build(vector<int> &arr){
        build(arr, 0, 0, size);
    }
    void init(int n){
        size = 1;
        while(size < n){size *=2;}
        sums.assign(2*size, 0ll);
        pref.assign(2*size, 0ll);
        suff.assign(2*size, 0ll);
        seg.assign(2*size, 0ll);
         
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        build(a);
    }
    
    void set(int i, int val, int lx, int rx, int x){
        if (rx - lx == 1){
                sums[x] = val;
                pref[x] = max(0ll, val);
                suff[x] = max(0ll, val);
                seg[x] = max(0ll, val);
            return;
        }
        int m = (lx + rx) / 2;
        if (i < m)set(i, val, lx, m, 2*x+1);
        else set(i, val, m, rx, 2*x+2);
        sums[x] = merge(sums[2*x+1],sums[2*x+2]);
        pref[x] = max(pref[2*x+1], sums[2*x+1]+pref[2*x+2]);
        suff[x] = max(suff[2*x+2], suff[2*x+1]+sums[2*x+2]);
        seg[x] = max(max(seg[2*x+1], seg[2*x+2]),pref[2*x+2]+suff[2*x+1]);
    }
    void set(int i, int val){
        set(i, val, 0, size, 0);
    }
    int get_max(){
        return seg[0];
    }
};
int32_t main(){
    ios::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    segtree st;
    st.init(n);
    cout << st.get_max() << endl;
    for(int i = 0; i < m; i++){
        int a,b; cin >> a >> b;
        st.set(a, b);
        cout << st.get_max() << endl;
    }
    return 0;
}

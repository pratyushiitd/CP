// https://codeforces.com/edu/course/2/lesson/4/2/practice/contest/273278/problem/C

#include <bits/stdc++.h>

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
    vector<int> maxs;

    int merge(int s1, int s2){
        
        return max(s1, s2);
    }
    void build(vector<int> &arr, int x, int lx, int rx){
        if (rx - lx == 1){
            if (lx <= (int)arr.size()-1){
                maxs[x] = arr[lx];
            }
            return;
        }
        int m = (lx + rx) / 2;
        build(arr, 2*x+1, lx, m);
        build(arr, 2*x+2, m, rx);
        maxs[x] = merge(maxs[2*x+1],maxs[2*x+2]);
    }
    void build(vector<int> &arr){
        build(arr, 0, 0, size);
    }
    void init(int n){
        size = 1;
        while(size < n){size *=2;}
        maxs.assign(2*size, 0ll);
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        build(a);
    }
    
    void set(int i, int val, int lx, int rx, int x){
        if (rx - lx == 1){
                maxs[x] = val;
            return;
        }
        int m = (lx + rx) / 2;
        if (i < m)set(i, val, lx, m, 2*x+1);
        else set(i, val, m, rx, 2*x+2);
        maxs[x] = merge(maxs[2*x+1], maxs[2*x+2]);
    }
    void set(int i, int val){
        set(i, val, 0, size, 0);
    }
    int get_min(int k, int x, int lx, int rx){
        if (maxs[x] < k)return -1;
        if (rx - lx == 1){
            return lx;
        }
        int m = (lx+rx)/2;
        if (maxs[2*x+1] >= k)return get_min(k, 2*x+1, lx, m);
        else if (maxs[2*x+2] >= k) return get_min(k, 2*x+2, m, rx);
        else return -1;
    }
    int get_min(int k){
        return get_min(k, 0, 0, size);
    }
};
int32_t main(){
    ios::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    segtree st;
    st.init(n);

    for(int i = 0; i < m; i++){
        int t,a,b; cin >> t >> a;
        if (t==1) {
            cin >> b; st.set(a, b);
        }
        else {
            int val = st.get_min(a);
            if (val < n) cout << st.get_min(a) << endl;
            else cout << -1 << endl;
        }
    }
    return 0;
}

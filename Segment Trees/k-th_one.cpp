//https://codeforces.com/edu/course/2/lesson/4/2/practice/contest/273278/problem/B
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
    vector<int> sums;

    int merge(int s1, int s2){
        
        return s1+s2;
    }
    void build(vector<int> &arr, int x, int lx, int rx){
        if (rx - lx == 1){
            if (lx <= (int)arr.size()-1){
                sums[x] = arr[lx];
            }
            return;
        }
        int m = (lx + rx) / 2;
        build(arr, 2*x+1, lx, m);
        build(arr, 2*x+2, m, rx);
        sums[x] = merge(sums[2*x+1],sums[2*x+2]);
    }
    void build(vector<int> &arr){
        build(arr, 0, 0, size);
    }
    void init(int n){
        size = 1;
        while(size < n){size *=2;}
        sums.assign(2*size, 0ll);
         
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        build(a);
    }
    
    void set(int i, int lx, int rx, int x){
        if (rx - lx == 1){
                sums[x] = 1-sums[x];
            return;
        }
        int m = (lx + rx) / 2;
        if (i < m)set(i, lx, m, 2*x+1);
        else set(i, m, rx, 2*x+2);
        sums[x] = merge(sums[2*x+1], sums[2*x+2]);
    }
    void set(int i){
        set(i, 0, size, 0);
    }
    int get_k(int k, int x, int lx, int rx){
        if (rx - lx == 1){
            return lx;
        }
        int m = (lx+rx)/2;
        if (sums[2*x+1] >= k+1)return get_k(k, 2*x+1, lx, m);
        else return get_k(k-sums[2*x+1], 2*x+2, m, rx);
    }
    int get_k(int k){
        return get_k(k, 0, 0, size);
    }
};
int32_t main(){
    ios::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    segtree st;
    st.init(n);

    for(int i = 0; i < m; i++){
        int a,b; cin >> a >> b;
        if (a==1) st.set(b);
        else cout << st.get_k(b) << endl;
    }
    return 0;
}

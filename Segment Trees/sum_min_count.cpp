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
    vector<int> sums;
    vector<int> mins;
    vector<pair<int, int>> leaf; // min, count
    pair<int, int> merge(pair<int, int> p1, pair<int, int> p2){
        
        if (p1.first > p2.first)return p2;
        else if (p1.first < p2.first)return p1;
        else return make_pair(p2.first, p1.second + p2.second);
    }
    void build(vector<int> &arr, int x, int lx, int rx){
        if (rx - lx == 1){
            if (lx <= (int)arr.size()-1){
                sums[x] = arr[lx];
                mins[x] = arr[lx];
                leaf[x] = {arr[lx], 1};

            }
            return;
        }
        int m = (lx + rx) / 2;
        build(arr, 2*x+1, lx, m);
        build(arr, 2*x+2, m, rx);
        sums[x] = sums[2*x+1] + sums[2*x+2];
        mins[x] = min(mins[2*x+1],mins[2*x+2]);
        leaf[x] = merge(leaf[2*x+1], leaf[2*x+2]);
    }
    void build(vector<int> &arr){
        build(arr, 0, 0, size);
    }
    void init(int n){
        size = 1;
        while(size < n){size *=2;}
        sums.assign(2*size, (int)0);
        mins.assign(2*size, (int)0);
        for(int i = 0; i < 2*size; i++){
            leaf.push_back({INT_MAX, 0});
        }
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        build(a);
    }
    
    void set(int i, int val, int lx, int rx, int x){
        if (rx - lx == 1){
            sums[x] = val;
            mins[x] = val;
            leaf[x] = {val, 1};
            return;
        }
        int m = (lx + rx) / 2;
        if (i < m)set(i, val, lx, m, 2*x+1);
        else set(i, val, m, rx, 2*x+2);
        sums[x] = sums[2*x+1]+sums[2*x+2];
        mins[x] = min(mins[2*x+1],mins[2*x+2]);
        leaf[x] = merge(leaf[2*x+1], leaf[2*x+2]);
    }
    void set(int i, int val){
        set(i, val, 0, size, 0);
    }
    
    int sum(int l, int r, int x, int lx, int rx){
        if (l >= rx || lx >= r)return 0;
        if (lx >= l && rx <= r)return sums[x];
        int m = (lx + rx) / 2;
        return sum(l, r, 2*x+1, lx, m)+sum(l, r, 2*x+2, m, rx);
    }
    int sum(int l, int r){
        return sum(l, r, 0, 0, size);
    }
    int getmin(int l, int r, int x, int lx, int rx){
        if (l >= rx || lx >= r)return INT_MAX;
        if (lx >= l && rx <= r)return mins[x];
        int m = (lx + rx) / 2;
        return min(getmin(l, r, 2*x+1, lx, m),getmin(l, r, 2*x+2, m, rx));
    }
    int getmin(int l, int r){
        return getmin(l, r, 0, 0, size);
    }
    pair<int, int> getmin_count(int l, int r, int x, int lx, int rx){
        if (l >= rx || lx >= r)return neutral;
        if (lx >= l && rx <= r)return leaf[x];
        int m = (lx + rx) / 2;
        pair<int, int> p1 = getmin_count(l, r, 2*x+1, lx, m);
        pair<int, int> p2 = getmin_count(l, r, 2*x+2, m, rx);
        return merge(p1, p2);
    }
    pair<int, int> getmin_count(int l, int r){
        return getmin_count(l ,r, 0, 0, size);
    }
};
int32_t main(){
    ios::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    segtree st;
    st.init(n);
    for(int i = 0; i < m; i++){
        int t, l, r; cin >> t >> l >> r;
        if (t==1)st.set(l, r);
        else{
            pair<int, int> ans = st.getmin_count(l ,r);
            cout << ans.first << ' ' << ans.second << endl;
        }
    }
    return 0;
}

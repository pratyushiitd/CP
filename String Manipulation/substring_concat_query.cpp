// https://codeforces.com/contest/1705/problem/C
#include <bits/stdc++.h>

using namespace std;

#define int long long


const int neutral = 0;

struct segtree{
    int size;
    vector<int> vec;
    int merge(int a, int b){return a+b;}
    
    void init(int n){
        size = 1;
        while(size < n){
            size*=2;
        }
        vec.assign(2*size, 0);
    }
    void build(vector<int> &arr, int x, int lx, int rx){
        if (rx - lx == 1){
            if (lx < arr.size())vec[x] = arr[lx];
            return;
        }
        int m = (lx + rx) / 2;
        build(arr, 2*x+1, lx, m);
        build(arr, 2*x+2, m, rx);
        vec[x] = merge(vec[2*x+1], vec[2*x+2]);
    }
    void build(vector<int> &a){
        build(a, 0, 0, size);
    }
    void set(int i, int val, int x, int lx, int rx){
        if (rx - lx == 1){
            vec[x] = val;
            return;
        }
        int m = (lx + rx) / 2;
        if (i < m)set(i, val, 2*x+1, lx, m);
        else set(i, val, 2*x+2, m, rx);
        vec[x] = merge(vec[2*x+1], vec[2*x+2]);
    }
    void set(int i, int val){
        set(i, val, 0, 0, size);
    }
    int sum(int l, int r, int x, int lx, int rx){
        if (l >= rx || r <= lx)return 0ll;
        if (lx >= l && rx <= r)return vec[x];
        int m = (lx + rx) / 2;
        return merge(sum(l, r, 2*x+1, lx, m), sum(l, r, 2*x+2, m, rx));
    }
    int sum(int l, int r){
        return sum(l, r, 0, 0, size);
    }
};


void solve(){
    int n, c, q; cin >> n >> c >> q;
    string s;
    cin >> s;
    vector<int> left(c+1), right(c+1), vec(c+1);
    left[0] = 0;right[0] = n;
    for(int i = 1; i <= c; i++){
        int l, r; cin >> l >> r;
        l--;r--;
        left[i] = right[i-1];
        right[i] = left[i]+r-l+1;
        vec[i] = left[i] - l;
    }
    while(q--){
        int k; cin >> k; k--;
        for(int j = c; j > 0; j--){
            if (left[j] > k)continue;
            k-=vec[j];
            // cout << k << endl;
        }
        cout << s[k] << endl;
    }
}
int32_t main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}

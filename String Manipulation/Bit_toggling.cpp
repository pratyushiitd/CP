// https://codeforces.com/contest/1705/problem/D
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


int solve(){
    int n; cin >> n;
    string s, t; cin >> s >> t;
    if(s[0]!=t[0] || s[n-1]!=t[n-1])return -1;
    vector<int> arr,brr;
    // an operation in s is swapping two different adjacent bits in xor string
    for(int i = 1; i < n; i++){
        int v1 = (s[i]-'0')^(s[i-1]-'0');
        int v2 = (t[i]-'0')^(t[i-1]-'0');
        if (v1)arr.push_back(i);
        if (v2)brr.push_back(i);
    }
    if (arr.size()!=brr.size())return -1;
    int ans = 0;
    for(int i = 0; i < arr.size(); i++)ans+=abs(arr[i]-brr[i]);
    return ans;
}
int32_t main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    cin >> t;
    while(t--)cout << solve() << endl;
    return 0;
}

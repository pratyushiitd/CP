// https://codeforces.com/edu/course/2/lesson/4/3/practice/contest/274545/problem/B
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
            vec[x] = val;
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
    
    int func(int k, int x, int lx, int rx){
        if (rx - lx == 1){
            return lx;
        }
        int m = (lx+rx)/2;
        if (vec[2*x+1] >= k+1)return func(k, 2*x+1, lx, m);
        else return func(k-vec[2*x+1], 2*x+2, m, rx);
    }
    int func(int k){
        return func(k, 0, 0, size);
    }
};
int32_t main(){
    ios::sync_with_stdio(false);
    int n; cin >> n;
    segtree st;
    st.init(n);
    vector<int> vec(n, 1);
    st.build(vec);
    int arr[n]; 
    for(int i = 0; i < n; i++)cin >> arr[i];
    for(int i = 0; i < n; i++){
        int x = arr[n-i-1];
        int val = st.func(n-x-1-i);
        arr[n-i-1] = val+1;
        st.set(val,0);
    }
    for(int i = 0; i < n; i++)cout<< arr[i] << " \n"[i==n-1];
    return 0;
}

// https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/D
#include <bits/stdc++.h>

using namespace std;
#define int int64_t

#define fo(i, k, n) for(int i = k; i < n; i++)


void solve(){

    // index of first element >= x 
    // int ind = lower_bound(a.begin(), a.end(), x) - a.begin(); 
    
    // index of first element > x
    // int ind = upper_bound(a.begin(), a.end(), x) - a.begin(); 
    
    int n; cin >> n;
    vector<int> vec(n, 0);
    fo(i, 0, n)cin >> vec[i];
    sort(vec.begin(), vec.end());
    int k; cin >> k;
    while(k--){
        int l, r;
        cin >> l >> r;
        int up = upper_bound(vec.begin(), vec.end(), r) - vec.begin();
        int lo = lower_bound(vec.begin(), vec.end(), l) - vec.begin();
        cout << up - lo << " \n"[k == 0];
    }
}
int32_t main(){
    
    int t; 
    // cin >> t;
    t = 1;
    while(t--)solve();
    return 0;
}

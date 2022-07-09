// https://codeforces.com/contest/1701/problem/D
#include <bits/stdc++.h>

using namespace std;
#define int int64_t


void solve(){
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)cin >> arr[i];
    vector<pair<pair<int, int>, int>> vec;
    vector<int> left(n+1), right(n+1);
    vector<int> low_arr[n+1];
    for(int i = 1; i <= n; i++){
        int bi = arr[i-1];
        int lower = i/(bi+1) + 1;
        int upper;
        if (bi == 0)upper = n;
        else upper = floor(i / bi);
        // cout << lower << ' ' << upper << endl;
        vec.push_back({{lower, upper}, i});
        left[i] = lower; right[i] = upper;
        low_arr[lower].push_back(i);
    }
    int ans[n+1];
    set<pair<int, int>> se;
    for(int i = 1; i <= n; i++){
        for(auto x: low_arr[i])se.insert({right[x],x});
        ans[se.begin()->second] = i;
        se.erase(se.begin());
    }
    for(int i = 1; i <= n; i++){
        cout << ans[i] << ' ';
    }
    cout << endl;
}
int32_t main(){
    
    int t; 
    cin >> t;
    // t = 1;
    while(t--)solve();
    return 0;
}

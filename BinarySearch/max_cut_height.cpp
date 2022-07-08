// https://www.spoj.com/problems/EKO/

#include <bits/stdc++.h>

using namespace std;
#define int int64_t

void solve(){
    int n, m; cin >> n >> m;
    int arr[n];
    for(int i = 0; i < n; i++)cin >> arr[i];
    int lo = 0, hi = 2e9;
    int ans = 0;
    while(lo <= hi){
        // cout << lo << ' ' << hi << endl;
        int mid = lo + (hi-lo)/2;
        int curr = 0;
        for(int i = 0; i < n; i++)curr+=max((int64_t)0, arr[i]-mid);
        if (curr < m)hi = mid-1;
        else if (curr >= m){
            ans = mid;
            lo = mid+1;
        }
    }
    cout << ans << endl;
}
int32_t main(){
    
    int t; 
    // cin >> t;
    t = 1;
    while(t--)solve();
    return 0;
}

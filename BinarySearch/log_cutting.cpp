// 
#include <bits/stdc++.h>

using namespace std;
#define int int64_t
#define fo(i, k, n) for(int i = k; i < n; i++)
int query(int l, int r){
    cout << "? " << l << ' ' << r << endl;
    cout.flush();
    int x; cin >> x;
    return x;
}
void output(int ans){
    cout << "! "<< ans << endl; 
    cout.flush();
}

void solve(){
     int n, k; cin >> n >> k;
    int arr[n];
    fo(i, 0, n)cin >> arr[i];
    int lo = 1, hi = 1e9;
    int ans = INT_MAX;
    while(lo <= hi){
        // if (lo == hi){
        //     ans = lo; break;
        // }
        int mid = lo+(hi - lo)/2;
        int curr = 0;
        for(int i = 0; i < n; i++){
            curr+= ( arr[i] )/ mid;
            if (arr[i] % mid == 0)curr--;
        }
                // cout << lo << ' ' << hi << ' ' << curr<< endl;

        if (curr <= k){
            hi = mid-1;
            ans = mid;
        }
        else lo = mid+1;

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

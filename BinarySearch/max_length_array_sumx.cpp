// https://codeforces.com/problemset/problem/279/B

#include <bits/stdc++.h>

using namespace std;

int solve(){
    int n, x; cin >> n >> x; 
    int arr[n+1];
        arr[0] = 0;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        arr[i]+=arr[i-1];
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        int lo = i-1, hi = n;
        int curr = 0;
        while(lo <= hi){
            // cout << lo << ' ' << hi << endl;
            int m = lo + (hi - lo) / 2;
            // cout <<arr[m] - arr[i-1] << endl;
            if (arr[m] - arr[i-1] <= x){
                lo = m+1;
                curr = m-(i-1);
            }else{
                hi = m-1;
            }
        }
        ans = max(ans, curr);
    }
    return ans;
}

int main()
{
    int t=1;
    //cin >> t;
    while(t--)cout << solve();
}

/*
LOOK FOR -> int overflow, 
            array bounds
            special cases (n=1?)
            Different approaches
*/

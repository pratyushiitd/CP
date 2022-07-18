#include <bits/stdc++.h>
// https://codeforces.com/problemset/problem/279/B

using namespace std;

int solve(){
    int n, x; cin >> n >> x; 
    int arr[n+1];
        arr[0] = 0;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    int ans = 0, sum = arr[1];
    int l = 0, r = 1;
    while(l <= n && r <= n){
        if (sum <= x){
            ans = max(ans, r-l);r++;sum+=arr[r];
        }else{
            l++;sum-=arr[l];
        }
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

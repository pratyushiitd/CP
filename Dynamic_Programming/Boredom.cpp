// https://codeforces.com/problemset/problem/455/A
#include <bits/stdc++.h>

using namespace std;

#define int long long
const int MAX = 1000001;

int dp[MAX];
void solve(){
    memset(dp, 0, sizeof(dp));
    int ans = 0;
    int n; cin >> n;
    int arr[n];
    map<int, int> mp;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        mp[arr[i]]++;
    }
    sort(arr, arr+n);
    for(int i = 1; i <= arr[n-1]; i++){
        int x = i;
        if (x==1)dp[1] = mp[1];
        else{
            dp[x] = max(dp[x-1], dp[x-2]+x*mp[x]);
        }
        ans = max(ans, dp[x]);
    }
    cout << ans << endl;
}
int32_t main(){
    
    int t = 1;
    // cin >> t;
    while(t--)solve();
    return 0;
}

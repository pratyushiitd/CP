// https://cses.fi/problemset/task/1636/
#include <bits/stdc++.h>

using namespace std;

#define int long long
const int MAX = 1000001;
const int mod = 1e9+7;
int arr[MAX], n, m; 

// WORKS BUT HIGH MEMORY USAGE => N*x
// int dp[MAX][101];
// int num_ways(int x, int prev){
//     if (x == 0)return 1;
//     if (prev == n) return 0;
//     if (dp[x][prev]!=-1)return dp[x][prev]%mod;
//     int ans = 0;
//     if (x-arr[prev]>=0)ans+=num_ways(x-arr[prev], prev)%mod;
//     ans+=num_ways(x, prev+1)%mod;
//     return dp[x][prev] = ans%mod;
// }

int dp[MAX];
void solve(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)cin >> arr[i];
    int dp[MAX];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for(int i = 0; i < n; i++){
        int c = arr[i];
        for(int j = 1; j <= m; j++){
            if (c <= j)
            dp[j] = (dp[j]+dp[j-c])%mod;
        }
    }
    cout << dp[m] << endl;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while(t--)solve();
    return 0;
}

// https://cses.fi/problemset/task/1746/
#include <bits/stdc++.h>

using namespace std;

#define int long long
const int MAX = 200001;
const int mod = 1e9+7;
int dp[MAX][101];
int arr[MAX], n, m; 
int num_ways(int i, int prev){
    if (i == n)return 1;
    if (prev < 0 || prev > m)return dp[i][prev]=0;
    if (dp[i][prev]!=-1ll)return dp[i][prev]%mod;
    if (arr[i] != 0){
        if (abs(prev-arr[i]) > 1 && prev!=0ll)return dp[i][prev]=0;
        return dp[i][prev]=num_ways(i+1, arr[i])%mod;
    }
    if (prev == 0){
        int ans = 0;
        for(int j = 1; j <= m; j++){
            ans+=num_ways(i+1, j)%mod;
        }return dp[i][prev]=ans%mod;
    }else{
        int ans= 0;
        for(int j = max(1ll, prev-1); j <= min(m, prev+1); j++)
        ans+=num_ways(i+1, j)%mod;
        return dp[i][prev]=ans%mod;
    }
}
void solve(){
    cin >> n >> m;
    for(int i = 0; i <= n; i++)for(int j = 0; j <= m; j++)dp[i][j] = -1ll;
    for(int i = 0; i < n; i++)cin >> arr[i];
    cout << num_ways(0, 0);
    // cout << 1;
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

// https://cses.fi/problemset/task/1635/
#include <bits/stdc++.h>

using namespace std;

#define int long long
const int MAX = 1000001;
const int mod = 1e9+7;
int dp[MAX];
int arr[MAX], n, m; 
int num_ways(int x){
    if (x == 0)return 1;
    if (dp[x]!=-1)return dp[x]%mod;
    int ans = 0;
    for(int i = 0; i < n; i++){
        if (x-arr[i]>=0)
            ans+=num_ways(x-arr[i])%mod;
    }
    return dp[x] = ans%mod;
}
void solve(){
    cin >> n >> m;
    for(int i = 0; i <= m; i++)dp[i] = -1;
    for(int i = 0; i < n; i++)cin >> arr[i];
    cout << num_ways(m) << endl;
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

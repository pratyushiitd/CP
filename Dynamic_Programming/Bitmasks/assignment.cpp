// https://www.spoj.com/problems/ASSIGN/
#include <bits/stdc++.h>

using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

const int MAX = 22;
int n, arr[MAX][MAX];
int dp[(1<<20)];
int get(int mask){
    int k = __builtin_popcount(mask);
    if (dp[mask]!=-1)return dp[mask];
    if (k == n)return 1;
    int ans = 0;
    for(int i = 0; i < n; i++){
        if (arr[i][k] && !(mask & (1<<i)))ans+=get(mask | (1<<i));
    }
    return dp[mask] = ans;
}

void solve(){
    cin >> n;
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)cin >> arr[i][j];
    }
    cout << get(0) << endl;
}
int32_t main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}

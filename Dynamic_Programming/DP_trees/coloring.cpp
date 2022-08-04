// https://atcoder.jp/contests/dp/tasks/dp_p
#include <bits/stdc++.h>

using namespace std;

#define int long long
const int MAX = 1e5+1, mod = 1e9+7;
int dp[MAX][2], n, x, y;
vector<int> adj[MAX];
void dfs(int i = 1, int p = -1){
    dp[i][0] = dp[i][1] = 1;
    int w = 1, b = 1;
    for(auto x: adj[i]){
        if (p != x){
            dfs(x, i);
            w = (w * (dp[x][0] + dp[x][1]))%mod;
            b = (b * dp[x][0])%mod;
        }
    }
    dp[i][0] = w, dp[i][1] = b;
}
void solve(){
    cin >> n;
    for(int i(0); i < n-1; i++)cin >> x >> y, adj[x].push_back(y), adj[y].push_back(x);
    memset(dp, 0, sizeof(dp));
    dfs();
    cout << (dp[1][0] + dp[1][1])%mod << endl;
}
int32_t main(){
    
    solve();
    return 0;
}

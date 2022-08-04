// https://cses.fi/problemset/task/1133/
#include <bits/stdc++.h>

using namespace std;

#define int long long
const int MAX = 2e5+1, mod = 1e9+7;
int dp[MAX][2], n, x, y;
vector<int> adj[MAX];
vector<int> visited;

// dp[0] -> Sum, dp[1] -> count
void dfs(int i = 1, int p = -1){
    dp[i][1]++;
    for(auto it: adj[i]){
        if (it == p)continue;
        dfs(it, i);
        dp[i][1]+=dp[it][1];
        dp[i][0]+=dp[it][0]+dp[it][1];
    }
}
void dfs2(int i = 1, int p = -1){
    if (p>0){
        dp[i][0] = dp[p][0]+ n - 2*dp[i][1];
    }
    for(auto it: adj[i]){
        if (p != it){
            dfs2(it, i);
        }
    }
}
void solve(){
    cin >> n;
    visited.assign(n+1, 0);
    for(int i(0); i < n-1; i++)cin >> x >> y, adj[x].push_back(y), adj[y].push_back(x);
    memset(dp, 0, sizeof(dp));
    dfs();
    dfs2();
    for(int i = 1; i <= n; i++)cout << dp[i][0] << " \n"[i == n];
}
int32_t main(){
    
    solve();
    return 0;
}

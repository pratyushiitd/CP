// https://cses.fi/problemset/task/1130/
#include <bits/stdc++.h>

using namespace std;

#define int long long
const int MAX = 2e5+1, mod = 1e9+7;
int dp[MAX][2], n, x, y;
vector<int> adj[MAX];
const int INF = -1e9;
void dfs(int i = 1, int p = -1){
    int w = 0, wt = INF;
    dp[i][0] = dp[i][1] = 0;
     // 0-> with
    if (adj[i].size() == 1 && p > 0)return;
    for(auto x: adj[i]){
        if (p != x){
            dfs(x, i);
            w += dp[x][0];
            wt = max(wt, dp[x][1] - dp[x][0]);
        }
    }
    dp[i][0] = w + wt + 1;
    dp[i][1] = w;
}
void solve(){
    cin >> n;
    for(int i(0); i < n-1; i++)cin >> x >> y, adj[x].push_back(y), adj[y].push_back(x);
    memset(dp, 0, sizeof(dp));
    dfs();
    cout << max(dp[1][0], dp[1][1]) << endl;
}
int32_t main(){
    
    solve();
    return 0;
}

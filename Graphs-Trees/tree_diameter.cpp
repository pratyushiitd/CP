// https://cses.fi/problemset/task/1131/
#include <bits/stdc++.h>

using namespace std;

#define int long long
const int MAX = 2e5+2;
vector<int> adj[MAX];
vector<bool> visited;
int ans = 0;
int dfs(int i = 1){
    int f1 = 0, f2 = 0;
    visited[i] = true;
    for(auto x: adj[i]){
        if (!visited[x]){
            int val = dfs(x);
            if (f1 < val){
                f2 = f1;
                f1 = val;
            }else if (val > f2){
                f2 = val;
            }
        }
    }
    ans = max(ans, f1+f2);
    return max(f1, f2)+1;
}
void solve(){
    int n; cin >> n;
    for(int i = 0; i < n-1; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    visited.assign(n+1, 0);
    dfs();
    cout << ans << endl;
}
int32_t main(){
    
    int t = 1;
    // cin >> t;
    while(t--)solve();
    return 0;
}

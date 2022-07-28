#include <bits/stdc++.h>

using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define fi first
#define se second
const int MAX = 100002;
int n,m;
int arr[MAX];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
vector<int> adj[MAX];
vector<int> color;
vector<bool> visited;
bool valid(int nx, int ny){
    return (nx >= 0 && ny >= 0 && nx < n && ny < m);
}
bool dfs(int u, int c){
    visited[u] = true;
    color[u] = c;
    bool valid = true;
    for(auto x: adj[u]){
        if (color[x] == color[u])return false;
        if (visited[x])continue;
        valid = valid & dfs(x, 1-c);
    }
    return valid;
}
void solve(){
    cin >> n >> m;
    color.assign(n+1, -1);visited.resize(n+1);
    while(m--){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool valid = true;
    for(int i = 1; i <= n; i++){
        if (!visited[i])valid = valid & dfs(i, 0);
    }
    if (!valid){
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    for(int i = 1; i <= n; i++){
        cout << color[i] + 1<< " \n"[i==n];
    }
}
int32_t main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--)solve();
    return 0;
}

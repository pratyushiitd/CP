// https://www.codechef.com/problems/CHFNFRN?tab=statement
#include <bits/stdc++.h>

using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define fi first
#define se second
const int MAX = 1002;
int n,m;
int arr[MAX];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
vector<int> adj[MAX];
vector<int> color;
vector<bool> visited;
int adj_mat[MAX][MAX];
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
    memset(adj_mat, 0, sizeof(adj_mat));
    color.clear();visited.clear();
    color.assign(n+1, -1);visited.resize(n+1);
    for(int i = 0; i <= n; i++)adj[i].clear();
    while(m--){
        int u, v; cin >> u >> v;
        adj_mat[u][v] = 1;
        adj_mat[v][u] = 1;
    }
    for(int i = 1; i <= n; i++){
        for(int j = i+1; j <= n; j++){
            if (adj_mat[i][j] == 0){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    bool valid = true;
    for(int i = 1; i <= n; i++){
        if (!visited[i])valid = valid & dfs(i, 0);
    }
    if (!valid){
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
}
int32_t main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}

// https://cses.fi/problemset/task/1667/
#include <bits/stdc++.h>

using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define fi first
#define se second
#define ld long double
const int MAX = 200002;
int n,m,r;
int arr[MAX];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
vector<int> adj[MAX];
vector<int> indegree;
vector<bool> visited;
stack<int> st;

bool valid(int nx, int ny){
    return (nx >= 0 && ny >= 0 && nx < n && ny < m);
}
void dfs(int u){
    visited[u] = true;
    for(auto x: adj[u]){
        if (!visited[x])dfs(x);
    }
    st.push(u);
}
void solve(){
    cin >> n >> m;
    visited.resize(n+1);
    while(m--){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> par(n+1);
    par[1] = 1;
    par[n] = -1;
    queue<int> q;
    q.push(1);
    visited[1] = true;
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(auto x: adj[u]){
            if (!visited[x]){
                visited[x] = true;
                q.push(x);
                par[x] = u;
            }
        }
    }
    if (par[n] == -1){
        cout << "IMPOSSIBLE" << endl;
    }
    else {
        vector<int> path;
        path.push_back(n);
        while(par[n] != n){
            path.push_back(par[n]);
            n = par[n];
        }
        reverse(path.begin(), path.end());
        cout << path.size() << endl;
        for(auto x: path)cout << x << ' ';
        cout << endl;
    }
}
int32_t main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--)solve();
    return 0;
}

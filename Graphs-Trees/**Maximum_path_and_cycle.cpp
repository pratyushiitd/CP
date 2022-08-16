//https://cses.fi/problemset/task/1673

#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
#define f first
#define s second
const int MAX = 1e4;
int n, m, a, b, w;
vector<int> rev[MAX], adj[MAX];
int dist[MAX];
#define inf -1e18
int sens[MAX], visited[MAX];
void check(int i){
    if (sens[i] == 1)sens[i] = 2;
    visited[i] = true;
    for(auto x: rev[i]){
        if (!visited[x])check(x);
    }
}
bool dfs(int i = 1){
    if (sens[i] == 2)return true;
    visited[i] = true;
    bool ret_val = false;
    for(auto x: adj[i]){
        if (!visited[x])ret_val |= dfs(x);
    }
    return ret_val;
}
void solve(){
    cin >> n >> m;
    for(int i = 0; i <= n; i++){
        dist[i] = inf;
    }
    dist[1] = 0;
    vector<tuple<int, int, int>> edges;
    for(int i = 0; i < m; i++){
        cin >> a >> b >> w;
        edges.push_back({a, b, w});
        rev[b].push_back(a);
        adj[a].push_back(b);
    }
    for(int i = 0; i < n-1; i++){
        for(auto [x, y, w] : edges){
            if (dist[y] < dist[x] + w)dist[y] = dist[x] + w;
        }
    }
    bool cycle = false;
    memset(sens, 0, sizeof(sens));
    memset(visited, 0, sizeof(visited));
    for(auto [x, y, w] : edges){
            if (dist[y] < dist[x] + w){
                sens[y] = 1;
            }
        }
    check(n);
    memset(visited, 0, sizeof(visited));
    if (dfs())cout << -1 << endl;
    else cout << dist[n] << endl;
}
 
int32_t main(){
    
    solve();
    return 0;
}

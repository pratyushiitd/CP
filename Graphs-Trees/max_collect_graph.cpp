// https://cses.fi/problemset/task/1686/
#include <bits/stdc++.h>

#define int long long

using namespace std;

const int MAX = 2e5+2;
int n, q, k;
vector<int> adj[MAX];
int par[MAX][40];
vector<int> g[MAX], gr[MAX];
set<int> grr[MAX];
stack<int> st;
int arr[MAX];
bool visited[MAX];
int sz[MAX];
int cmp = 0;
void topo(int i){
    visited[i] = true;
    for(auto v: g[i]){
        if (!visited[v])topo(v);
    }
    st.push(i);
}
int comp[MAX];
void dfs(int i){
    visited[i] = true;
    sz[cmp]+=arr[i];
    comp[i] = cmp;
    for(auto v: gr[i]){
        if (!visited[v])dfs(v);
    }
}
int ans = 0;
int dfs2(int i){
    if (arr[i]!=-1)return arr[i];
    int val = 0;
    for(auto it = grr[i].begin(); it != grr[i].end(); it++){
        int x = *it;
        val = max(val, dfs2(x));
    }
    ans = max(ans, val+sz[i]);
    return arr[i] = val+sz[i];
}
void solve(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++)cin >> arr[i+1];
    vector<pair<int, int>> edges;
    while(m--){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        gr[v].push_back(u);
        edges.push_back({u, v});
    }
    memset(visited, 0, sizeof(visited));
    for(int i = 1; i <= n; i++){
        if (!visited[i])topo(i);
    }
    memset(sz, 0, sizeof(sz));
    memset(visited, 0, sizeof(visited));
    memset(comp, -1, sizeof(comp));
    while(!st.empty()){
        int v = st.top(); st.pop();
        if (!visited[v]){
            cmp++;
            dfs(v);
        }
    }
    for (auto e:edges){
        int u = e.first, v = e.second;
        if (comp[u] != comp[v]){
            grr[comp[u]].insert(comp[v]);
        }
    }
    memset(arr, -1, sizeof(arr));
    for(int i = 1; i <= cmp; i++){
        dfs2(i);
    }
    cout << ans << endl;
}
int32_t main(){
    
    solve();
    return 0;
}

// https://www.spoj.com/problems/BREAK/
#include <bits/stdc++.h>

#define int long long

using namespace std;

const int MAX = 9002;
int n, q, k;
vector<int> adj[MAX];

vector<int> g[MAX], gr[MAX];
set<int> grr[MAX];
stack<int> st;
int arr[MAX];
bool visited[MAX];
int sz[MAX];
int cmp = 0, ans = 0;;
void topo(int i){
    visited[i] = true;
    for(auto v: g[i]){
        if (!visited[v])topo(v);
    }
    st.push(i);
}
void topo2(int i){
    visited[i] = true;
    for(auto it = grr[i].begin(); it != grr[i].end(); it++){
        int v = *it;
        if (!visited[v])topo2(v);
    }
    st.push(i);
}
int comp[MAX];
map<int, int> vis;
void dfs(int i){
    visited[i] = true;
    sz[cmp]++;
    comp[i] = cmp;
    for(auto v: gr[i]){
        if (!visited[v])dfs(v);
    }
}
void dfs2(int i){
    vis[i] = 1;
    for(auto it = grr[i].begin(); it != grr[i].end(); it++){
        if (vis[*it])continue;
        dfs2(*it);
    }
    ans+=sz[i];
}
void solve(){
    int n, m; cin >> n >> m;
    for(int i = 0; i <= n; i++){
        g[i].clear(); gr[i].clear();
        while(!st.empty())st.pop();
        grr[i].clear();
        ans = cmp = 0;
    }
    vector<pair<int, int>> edges;
    while(m--){
        int u, v; cin >> u >> v;
        swap(u, v);
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
    memset(visited, 0, sizeof(visited));
    memset(arr, -1, sizeof(arr));
    vector<int> out;
    while(!st.empty())st.pop();
    for(int i = 1; i <= cmp; i++){
        if (!visited[i])topo2(i);
    }
        
    memset(visited, 0, sizeof(visited));
    int glob = 0;
    while(!st.empty()){
        int u = st.top();st.pop();vis.clear();
        ans = 0;
        dfs2(u); glob = max(glob, ans);
        arr[u] = ans;
    }
    // cout << cmp << endl;
    for(int i = 1; i <= n; i++){
        // cout << i << ' ' << arr[comp[i]] << endl;
        if (arr[comp[i]] == glob)cout << i <<  ' ';
    }
    cout << endl;
}
int32_t main(){
    int t; cin >> t;
    while(t--)solve();
    return 0;
}

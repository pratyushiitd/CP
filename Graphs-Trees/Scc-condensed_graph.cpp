//https://www.codechef.com/problems/MCO16405
#include <bits/stdc++.h>

using namespace std;

#define int long long
int n, m, k, q;
const int MAX = 1e5+2;

bool visited[MAX];
vector<int> g[MAX], gr[MAX];
set <int> grr[MAX];

int comp[MAX];
stack<int> st;
int cmp = 0;
void topo(int i = 1){
    visited[i] = true;
    for(auto it: g[i]){
        if (!visited[it])topo(it);
    }
    st.push(i);
}
map<int, int> sz;
int arr[MAX], ans[MAX];
void dfs(int i){
    sz[cmp]+=arr[i];
    comp[i] = cmp;
    for(auto x: gr[i]){
        if (comp[x] == -1)dfs(x);
    }
}

int dfs2(int u){
    if (ans[u]!=-1)return ans[u];
    int val = 0;
    for(auto it = grr[u].begin(); it != grr[u].end(); it++){
        int x = *it;
        ans[x]=dfs2(x);
        val=max(ans[x], val);
    }
    return ans[u] = val+sz[u];
}
void solve(){
   cin >> n >> m;
    for(int i = 1; i <= n; i++)cin >> arr[i];
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
    memset(comp, -1, sizeof(comp));
    while(!st.empty()){
        int u = st.top(); st.pop();
        if (comp[u] == -1){
            cmp++;
            dfs(u);
        }
    }
    for(auto e: edges){
        int u = e.first, v = e.second;
        if (comp[u]!=comp[v])
        grr[comp[u]].insert(comp[v]);
    }
    memset(ans, -1, sizeof(ans));
    for(int i = 1; i <= cmp; i++){
        dfs2(i);
    }
    for(int i = 1; i <= n; i++)cout << ans[comp[i]] << " \n"[i==n];
}

int32_t main(){
    solve();
    return 0;
}

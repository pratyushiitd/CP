// https://cses.fi/problemset/task/1683/
// Kosaraju Algorithm
#include <bits/stdc++.h>

using namespace std;

#define int long long
int n, m, k, q;
const int MAX = 1e5+2;

bool visited[MAX];
vector<int> g[MAX], gr[MAX];

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
void dfs(int i){
    comp[i] = cmp;
    for(auto x: gr[i]){
        if (comp[x] == -1)dfs(x);
    }
}
void solve(){
   cin >> n >> m;
    while(m--){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        gr[v].push_back(u);
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
    cout << cmp << endl;
    for(int i = 1; i <= n; i++)cout << comp[i] << " \n"[i==n];
}

int32_t main(){
    solve();
    return 0;
}

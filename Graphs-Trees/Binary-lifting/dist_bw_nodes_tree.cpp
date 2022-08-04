// https://cses.fi/problemset/task/1135/
#include <bits/stdc++.h>

using namespace std;


#define int long long
const int MAX = 2e5+2;
const int LMAX = 20;
int n, m, k, x, q;
vector<int> adj[MAX];
vector<int> depth;
int par[MAX][LMAX];

int find_k(int u, int k){
    for(int i = 0; i < LMAX; i++){
        if ((1 << i) & k){
        u = par[u][i];
        }
    }
    return u;
}
void dfs(int i = 1, int level = 0, int p = 1){
    depth[i] = level;
    par[i][0] = p;
    for(auto x: adj[i]){
        if (x!=p)
        dfs(x, level + 1, i);
    }
}
int lca(int a, int b){
   if (depth[a] > depth[b])swap(a, b);
    int d = depth[b] - depth[a];
    b = find_k(b, d);
    for(int i = LMAX-1; i >= 0; i--){
        if (par[a][i] != par[b][i]){
            a = par[a][i], b = par[b][i];
        }
    }
    if (a == b)return a;
    else return par[a][0];
}
void solve(){
    cin >> n >> q;
   memset(par, 0, sizeof(par));
    par[1][0] = 1;
    depth.assign(n+1, 0);
    for(int i = 0; i < MAX; i++)adj[i].clear();
    depth.assign(n+1, 0);
    par[1][0] = 1;
    for(int i = 1; i < n; i++){
        cin >> k >> x;
        adj[k].push_back(x);
        adj[x].push_back(k);
    }
    dfs();
        for(int j = 1; j < LMAX; j++){
            for(int i = 1; i <= n; i++){
            par[i][j] = par[par[i][j-1]][j-1];
        }
    }
    while(q--){cin >> k >> x, cout << depth[k]+depth[x] - 2*depth[lca(k, x)] << '\n';}
}
int32_t main(){
    
    int t= 1;
   while(t--)solve();
    return 0;
}

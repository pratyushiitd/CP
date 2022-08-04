// https://www.spoj.com/problems/LCA/
#include <bits/stdc++.h>

using namespace std;


#define int long long
const int MAX = 1e3+2;
int n, m, k, x, q;
vector<int> adj[MAX];
vector<int> depth;
int par[MAX][40];
int find_k(int u, int k){
    for(int i = 0; i < 32; i++){
        if ((1 << i) & k){
           u = par[u][i];
        }
    }
    return u;
}
void dfs(int i = 1, int level = 0){
    depth[i] = level;
    for(auto x: adj[i]){
        dfs(x, level + 1);
    }
}
int lca(int a, int b, int l = 40){
  if (depth[a] > depth[b])swap(a, b);
    int d = depth[b] - depth[a];
    b = find_k(b, d);
    for(int i = 32; i >= 0; i--){
        if (par[a][i] != par[b][i]){
            a = par[a][i], b = par[b][i];
        }
    }
    if (a == b)return a;
    else return par[a][0];
}
void solve(){
    cin >> n;
   memset(par, 1, sizeof(par));
    for(int i = 0; i < MAX; i++)adj[i].clear();
    depth.assign(n+1, 0);
    par[1][0] = 1;
    for(int i = 1; i <= n; i++){
        cin >> k;
        while(k--)cin >> x, par[x][0] = i, adj[i].push_back(x);
    }
    dfs();
    for(int i = 1; i <= n; i++){
        for(int j = 1; j < 40; j++){
            par[i][j] = par[par[i][j-1]][j-1];
        }
    }
    cin >> q;
    while(q--){cin >> k >> x, cout << lca(k, x) << endl;}
}
int32_t main(){
    
    int t; cin >> t;
   for(int i = 1; i <= t; i++){
       cout << "Case " << i << ":\n";
       solve();
       cout << endl;
   }
    return 0;
}

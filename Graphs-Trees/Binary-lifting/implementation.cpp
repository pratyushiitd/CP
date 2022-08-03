//https://cses.fi/problemset/task/1687/
#include <bits/stdc++.h>

#define int long long

using namespace std;

const int MAX = 2e5+2;
int n, q, k;
vector<int> adj[MAX];
int par[MAX][40];

int find_k(int v, int k){
    int node = v;
    for(int i = 0; i < 32; i++){
        if ((k & (1 << i)) > 0){
            node = par[node][i];
            if (node == -1)return -1;
        }
    }
    return node;
}
void solve(){
   cin >> n >> q;
   for(int i = 0; i < n-1; i++){
       int p; cin >> p;
       par[i+2][0] = p;
   }
    for(int i = 0; i < 32; i++)par[1][i] = -1;
    for(int i = 2; i <= n; i++){
        for(int j = 1; j < 30; j++){
            if (par[i][j-1] != -1)
            par[i][j] = par[par[i][j-1]][j-1];
            else par[i][j] = -1;
        }
    }
    while(q--){
        int v, k; cin >> v >> k;
        cout << find_k(v, k) << endl;
    }
}
int32_t main(){
    
    solve();
    return 0;
}
/*
1
2 3
  4 5
*/

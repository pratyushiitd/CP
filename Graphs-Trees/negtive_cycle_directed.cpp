// https://cses.fi/problemset/result/4441795/
#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
#define f first
#define s second
const int MAX = 1e4;
int n, m, a, b, w;
vector<int> rev[MAX], adj[MAX];
int dist[MAX];

void solve(){
    cin >> n >> m;
    vector<tuple<int, int, int>> edges;
    for(int i = 0; i < m; i++){
        cin >> a >> b >> w;
        edges.push_back({a, b, w});
    }
    for(int i = 1; i <= n; i++)dist[i] = INT_MAX;
    dist[1] = 0;
    vector<int> par(n+1, -1);
    for(int i = 0; i < n-1; i++){
        for( auto [x, y, w]: edges){
            if (dist[y] > dist[x] + w){
                dist[y] = dist[x] + w; par[y] = x;
            }
        }
    }
    int node = -1;
    for( auto [x, y, w]: edges){
            if (dist[y] > dist[x] + w)
                dist[y] = dist[x] + w, par[y] = x, node = y;
        }
    if (node == -1)cout << "NO" << endl;
    else{
        cout << "YES" << endl;
        for(int i = 0; i < n; i++)node = par[node];
        vector<int> cycle = {node};
        int curr = par[node];
        while(curr != node){
            cycle.push_back(curr);
            curr = par[curr];
        }
        cycle.push_back(node);
        reverse(cycle.begin(), cycle.end());
        for(auto x: cycle)cout << x << ' ';
        cout << endl;
     }
}
 
int32_t main(){
    
    solve();
    return 0;
}

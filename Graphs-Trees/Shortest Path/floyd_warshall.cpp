// https://cses.fi/problemset/task/1672/
#include <bits/stdc++.h>

using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define fi first
#define se second
#define ld long double
const int MAX = 200002;
int INF = 1e15;
int n,m,r;
int arr[MAX];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
vector<pair<int, pair<int, int>>> edges;
vector<int> adj[MAX];
vector<int> color; // 0-> white, 1-> grey, 2-> black
vector<int> parent;
map<pair<int, int>, int> weight;
stack<int> st;
vector<vector<int>> dist;
bool valid(int nx, int ny){
    return (nx >= 0 && ny >= 0 && nx < n && ny < m);
}

void solve(){
    int q;
    cin >> n >> m >> q;
    dist.resize(n+1, vector<int> (n+1));
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++)dist[i][j] = INF;
        dist[i][i] = 0;
    }
    while(m--){
        int u, v, w; cin >> u >> v >> w;
        dist[u][v] = dist[v][u] = min(w, dist[u][v]);
    }
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }
    while(q--){
        int u, v; cin >> u >> v;
        int ans = min(dist[u][v], dist[v][u]);
        if (ans >= INF)ans = -1;
        cout << ans << endl;
    }
}
int32_t main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--)solve();
    return 0;
}

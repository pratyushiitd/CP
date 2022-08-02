// https://www.hackerearth.com/practice/algorithms/graphs/shortest-path-algorithms/practice-problems/algorithm/shortest-path-revisited-9e1091ea/
#include <bits/stdc++.h>

using namespace std;

#define int long long
int n, m, k;
const int MAX = 1e5+2;

int arr[MAX];
vector<pair<int, int>> adj[MAX];
int dist[MAX][20];

void dijkstra(){
    set<pair<int, pair<int, int>>> st;
    st.insert({0, {1, k}});
    dist[1][k] = 0;
    while(!st.empty()){
        int u = (*st.begin()).second.first, f = (*st.begin()).second.second;
        st.erase(st.begin());
        for(auto p: adj[u]){
            int v = p.first, w = p.second;
            // u,f -> v,f
            if (dist[v][f] > dist[u][f] + w){
                st.erase({dist[v][f], {v,f}});
                dist[v][f] = dist[u][f] + w;
                st.insert({dist[v][f], {v,f}});
            }
            // u,f -> v, f-1
            if (f && dist[v][f-1] > dist[u][f]){
                st.erase({dist[v][f-1], {v,f-1}});
                dist[v][f-1] = dist[u][f];
                st.insert({dist[v][f-1], {v,f-1}});
            }
        }
    }
}
void solve(){
    cin >> n >> m >> k;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <=k; j++)dist[i][j] = INT_MAX;
    }
    while(m--){
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    dijkstra();
    for(int i = 1; i <= n; i++){
        // cout << i << ' ' << n << endl;
        int ans = INT_MAX;
        for(int j = 0; j <= k; j++){
            ans = min(ans, dist[i][j]);
        }
        cout << ans << " \n"[i == n];
    }
}
int32_t main(){

    solve();
    return 0;
}

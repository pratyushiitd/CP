// https://www.hackerrank.com/challenges/synchronous-shopping/problem
#include <bits/stdc++.h>

using namespace std;

#define int long long
int n, m, k;
const int MAX = 1001;
vector<pair<int, int>> adj[MAX];
vector<int> fish[MAX];
int dist[MAX][1ll<<12];

void dijkstra(){
    set<pair<int, pair<int, int>>> st;
    st.insert({0, {1, 0}});
    dist[1][0] = 0;
    while(!st.empty()){
        int u = (*st.begin()).second.first, m = (*st.begin()).second.second;
        st.erase(*st.begin());
        for(int f: fish[u]){
            if (dist[u][m | (1 << f)] > dist[u][m]){
                if (st.find({dist[u][m | (1 << f)], {u, m | (1 << f)}}) != st.end()){
                        st.erase(st.find({dist[u][m | (1 << f)], {u, m | (1 << f)}}));
                    }
                    dist[u][m | (1 << f)] = dist[u][m];
                    st.insert({dist[u][m | (1 << f)], {u, m | (1 << f)}});
            }
        }
        for(auto p: adj[u]){
            int v = p.first, w = p.second;
            if (dist[v][m] > dist[u][m]+w){
                    if (st.find({dist[v][m], {v, m}}) != st.end()){
                        st.erase(st.find({dist[v][m], {v, m}}));
                    }
                    dist[v][m] = dist[u][m]+w;
                    st.insert({dist[v][m], {v, m}});
            }
        }
    }
}
void solve(){
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++){
        int t; cin >> t;
        fish[i].resize(t);
        for(int j = 0; j < t; j++){
            cin >> fish[i][j];
            fish[i][j]--;
        }
    }
    while(m--){
        int u, v, c; cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < (1 << k); j++)
            dist[i][j] = INT_MAX;
    }
    dijkstra();
    int ans = LLONG_MAX;
    for(int i = 0; i < (1 << k); i++){
        for(int j = 0; j < (1 << k); j++){
            if ((i | j) == (1 << k)-1){
                ans = min(ans, max(dist[n][i],  dist[n][j]));
            }
        }
    }
    cout << ans << endl;
}
int32_t main(){
    solve();
    return 0;
}

// https://cses.fi/problemset/task/1195/
#include <bits/stdc++.h>

using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define fi first
#define se second
#define ld long double
const int MAX = 200002;
const int INF = 1000000000000000;
int arr[MAX];

vector<pair<int, int>> adj[MAX];
int n, m;
int dist[MAX][2];

void dijkstra(){
    
    set<pair<int, pair<int, int>>> st;
    st.insert({0, {1, 1}});
    dist[1][0] = dist[1][1] = 0ll;
    while(!st.empty()){
        
        int u = (*st.begin()).second.first, f = (*st.begin()).second.second;
        st.erase(*st.begin());
        for(auto p: adj[u]){
            int v = p.first, w = p.second;
            // u, 1 -> v, 1
                if (dist[v][f] > dist[u][f] + w){
                    if (st.find({dist[v][f], {v, f}}) != st.end())st.erase(st.find({dist[v][f], {v, f}}));
                    dist[v][f] = dist[u][f] + w;
                    st.insert({dist[v][f], {v, f}});
                }
            if (f && dist[v][f-1] > dist[u][f] + w/2){
                if (st.find({dist[v][f-1], {v, f-1}}) != st.end())st.erase(st.find({dist[v][f-1], {v, f-1}}));
                    dist[v][f-1] = dist[u][f] + w/2;
                    st.insert({dist[v][f-1], {v, f-1}});
            }
        }
    }
}
void solve(){
   cin >> n >> m;
    while(m--){
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    for(int i = 0; i < MAX; i++)dist[i][0] = dist[i][1] = INF;
    dijkstra();
    cout << dist[n][0] << endl;
}
int32_t main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--)solve();
    return 0;
}

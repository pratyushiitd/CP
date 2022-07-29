// https://cses.fi/problemset/task/1671/
#include <bits/stdc++.h>

using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define fi first
#define se second
#define ld long double
const int MAX = 200002;
const int INF = LLONG_MAX;
int n,m,r;
int arr[MAX];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
vector<pair<int, pair<int, int>>> edges;
vector<pair<int, int>> adj[MAX];
vector<int> color; // 0-> white, 1-> grey, 2-> black
vector<int> parent;
map<pair<int, int>, int> weight;
stack<int> st;
vector<int> dist;
bool valid(int nx, int ny){
    return (nx >= 0 && ny >= 0 && nx < n && ny < m);
}
void solve(){
    cin >> n >> m;
    dist.resize(n+1);
    for(int i = 0; i <= n; i++)dist[i] = INF;
    while(m--){
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    set<pair<int, int>> st;
    st.insert({0, 1});
    dist[1] = 0;
    while(!st.empty()){
        int u = (*st.begin()).second;
        st.erase(st.begin());
        for(auto x : adj[u]){
            if (dist[u] + x.se < dist[x.fi]){
                
                auto it = st.find({dist[x.fi], x.fi});
                if (it !=st.end()) st.erase(it);
                dist[x.fi] = dist[u] + x.se;
                st.insert({dist[x.fi], x.fi});
            }
        }
    }
    for (int i = 1; i <= n; i++){
        cout << dist[i] << " \n"[i==n];
    }
}
int32_t main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--)solve();
    return 0;
}

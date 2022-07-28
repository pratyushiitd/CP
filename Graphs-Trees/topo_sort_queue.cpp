#include <bits/stdc++.h>

using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define fi first
#define se second
#define ld long double
const int MAX = 200002;
int n,m,r;
int arr[MAX];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
vector<int> adj[MAX];
vector<int> indegree;
vector<bool> visited;
stack<int> st;

bool valid(int nx, int ny){
    return (nx >= 0 && ny >= 0 && nx < n && ny < m);
}
void dfs(int u){
    visited[u] = true;
    for(auto x: adj[u]){
        if (!visited[x])dfs(x);
    }
    st.push(u);
}
void solve(){
    cin >> n >> m;
    indegree.assign(n+1, 0);
    while(m--){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        indegree[v]++;
    }
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if (indegree[i] == 0)q.push(i);
    }
    vector<int> topo_sort;
    while(!q.empty()){
        int u = q.front(); q.pop();
        topo_sort.push_back(u);
        for(auto x: adj[u]){
            indegree[x] --;
            if (indegree[x] == 0){
                q.push(x);
            }
        }
    }
    if (topo_sort.size() != n){
        cout << "IMPOSSIBLE" << endl;
            return;
    }
    for(auto x: topo_sort)cout << x << ' ';
    cout << endl;
}
int32_t main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--)solve();
    return 0;
}

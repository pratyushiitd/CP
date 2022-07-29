// https://cses.fi/problemset/task/1678/
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
vector<int> color; // 0-> white, 1-> grey, 2-> black
vector<int> parent;
stack<int> st;
vector<int> path;
bool valid(int nx, int ny){
    return (nx >= 0 && ny >= 0 && nx < n && ny < m);
}
bool dfs(int u){
    color[u] = 1;
    for(auto x: adj[u]){
        if (color[x] == 0 ){
            parent[x] = u;
            if (dfs(x))return true;
        }
        else if (color[x] == 1){
            path.push_back(x);
            int node = u;
            while(node!=x){
                path.push_back(node);
                node = parent[node];
            }
            path.push_back(x);
            return true;
        }
    }
    color[u] = 2;
    return false;
}
void solve(){
    cin >> n >> m;
    color.resize(n+1);parent.resize(n+1);
    while(m--){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }
    for(int i = 1; i <= n; i++){
        if (color[i] == 0 && path.size() == 0)dfs(i);
    }
    reverse(path.begin(), path.end());
    if (path.size()){
        cout << path.size() << endl;
        for(auto x: path)cout << x << ' ';
        cout << endl;
    }
    else cout << "IMPOSSIBLE" << endl;
}
int32_t main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--)solve();
    return 0;
}

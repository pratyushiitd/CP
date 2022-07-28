// https://www.hackerearth.com/practice/algorithms/graphs/topological-sort/practice-problems/algorithm/lonelyisland-49054110/
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
vector<int> color;
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

    cin >> n >> m >> r;
    visited.resize(n+1);
    while(m--){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }
    dfs(r);
    vector<ld> prob(n+1, 0);
    prob[r] = 1.0;
    while(!st.empty()){
        int x = st.top(); st.pop();
        for(auto u: adj[x]){
            prob[u] += prob[x] / (ld)(adj[x].size());
        }
    }
    vector<pair<ld, int>> vec;
   for(int i = 1; i <= n; i++){
       if (adj[i].size() == 0)
       vec.push_back({prob[i], i});
   }
    sort(vec.begin(), vec.end());
    ld diff = 1e-9;
    int ind = vec.size()-1;
    vector<int> ans;
    while(ind>=0 && abs(vec[ind].first - vec[vec.size()-1].first) < diff ){
        ans.push_back(vec[ind].second);
        ind--;
    }
    sort(ans.begin(), ans.end());
    for(auto x: ans)cout << x << ' ';
    cout << endl;
}
int32_t main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--)solve();
    return 0;
}

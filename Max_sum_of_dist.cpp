// https://www.geeksforgeeks.org/sum-of-the-distances-from-every-node-to-all-other-nodes-is-maximum/

vector<int> adj[100001];
bool visited[100001];

void dfs(int i, vector<int> &dp){
    visited[i] = true;
    dp[i]+=1;
    for(auto x: adj[i]){
        if (!visited[x]){
            dfs(x, dp);
            dp[i]+=dp[x];
        }
    }
}
int maxWeightGraph(int n, vector<int> weights, vector<pair<int, int>> edges){
    for(auto p: edges){
        adj[p.first].push_back(p.second);
        adj[p.second].push_back(p.first);
    }
    vector<int> dp(n, 0);
    dfs(0, dp);
    // for(int i = 0; i < n; i++)cout << dp[i] << '\n';
    vector<int> edges_count;
    for(auto p: edges){
        int u = p.first, v = p.second;
        int c1 = min(dp[u], dp[v]);
        int c2 = n - c1;
        edges_count.push_back(c1*c2);
    }
    sort(edges_count.begin(), edges_count.end());
    sort(weights.begin(), weights.end());
    int ans=0;
    for(int i = 0; i < n-1; i++)ans+=weights[i]*edges_count[i];
    return ans;
}

int main() {
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        for(int i = 0; i < n; i++){
            adj[i].clear();
            visited[i] = false;
        }
        vector<int> weights(n-1, 0);
        for(int i = 0; i < n-1; i++)cin >> weights[i];
        vector<pair<int, int>> edges;
        for(int i = 0; i < n-1; i++){
            int u, v; cin >> u >> v; edges.push_back({--u,--v});
        }
        cout << maxWeightGraph(n, weights, edges);
    }
}

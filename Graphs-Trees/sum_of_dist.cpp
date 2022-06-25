// https://www.codingninjas.com/codestudio/problems/sum-of-distance_1231014?topList=siddharth-singh-coding-sheet-problems&leftPanelTab=1

#include <bits/stdc++.h>

vector<int> adj[100001];
bool visited[100001];

void dfs(int i, vector<int> &dp, vector<int> &nc){
    visited[i] = true;
    nc[i]+=1;
    for(auto x: adj[i]){
        if (!visited[x]){
            dfs(x, dp, nc);
            nc[i]+=nc[x];
            dp[i]+=dp[x]+nc[x];
        }
    }
}
vector<int> sumofDistance(vector<vector<int>> &edges, int n){
    for(auto p: edges){
        adj[p[0]].push_back(p[1]);
        adj[p[1]].push_back(p[0]);
    }
    vector<int> dp(n, 0);
    vector<int> nc(n, 0); // node count
    dfs(0, dp, nc);
    vector<int> ans(n, 0);
    ans[0] = dp[0];
    // for(int i = 0; i < n; i++)cout << dp[i]<< endl;
    queue<int> q;
    q.push(0);
    vector<bool> visited_l(n, 0);
    visited_l[0] = true;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto x: adj[u]){
            if (visited_l[x])continue;
            visited_l[x] = 1;
            ans[x] = ans[u]-nc[x] + n - nc[x];
            q.push(x);
        }
    }
    return ans;
}
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<vector<int>> edges;
        for(int i = 0; i < n; i++){
            visited[i] = 0;
            adj[i].clear();
        }
        for(int i = 0; i < n-1; i++){
            int a, b; cin >>a >> b;
            edges.push_back({a, b});
        }
        for(auto x: sumofDistance(edges, n)){
            cout << x <<' ';
        }
        cout << endl;
    }
    return 0;
}

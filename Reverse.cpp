//https://www.codechef.com/problems/REVERSE

#include <bits/stdc++.h>

using namespace std;

vector<int> adj[100001];
bool visited[100001];
map<pair<int, int>, int> type;
int n;
    int dist[100001];
int main(void)
{
    int m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b; 
        if (a==b || type[{a,b}]==1)continue;
        adj[a].push_back(b);adj[b].push_back(a);
        type[{a,b}] = 1;
        if (type[{b,a}]!=1)type[{b,a}] = 2;
    }
    deque<int> dq;
    memset(visited, 0, sizeof(visited));
    dq.push_front(1);
    for(int i = 0; i <= n; i++)dist[i] = 10000000;
    // cout << dist[1];
    dist[1] = 0;
    visited[1] = true;
    while(!dq.empty()){
        int u = dq.front();
        // cout << u << endl;
        visited[u] = true;
        dq.pop_front();
        for(auto x: adj[u]){
            if (visited[x])continue;
            if (type[{u,x}]==1){
                dq.push_front(x);
            }
            else dq.push_back(x);
            dist[x] = min(dist[x], dist[u] + type[{u,x}]-1);
        }
    }
    int ans = dist[n];
    if (ans ==10000000)cout << -1;
    else cout << ans;
}

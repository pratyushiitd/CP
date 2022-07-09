#include <bits/stdc++.h>

// Find paths with 1 as root which have a majority element in path (array C contains value for each node)
using namespace std;

// #define int int64_t

const int MAX = 1e5+1;
vector<int> adj[MAX];

int c[MAX];

bool visited[MAX];
int ans;
void dfs(int u, int cnt, int max_el){
    if (c[u] == max_el){cnt++;ans++;}
    else {
        if (cnt == 0){
            cnt=1;max_el = c[u];
        }else {cnt--;
            if (cnt == 0)ans++;
            else ans++;
              }
    }
    for(int x: adj[u]){
        if (visited[x])continue;
        visited[x] = true;
        dfs(x, cnt, max_el);
    }
}
void solve(){
    int n; cin >> n;
    for(int i = 1; i <= n; i++)cin >> c[i];
    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    memset(visited, 0, sizeof(visited));
    visited[1] = true;
    ans = 0;
    dfs(1, 0, c[1]);
    cout << ans << endl;
}
int32_t main(){
    int t; cin >> t;while(t--)
    solve();
}
/*
1
5
1 2 3 4 5
1 2
2 3
1 4
2 5


1
10 
1 3 6 1 6 6 1 6 2 1
10 9
7 4
4 6
5 7
2 6
5 1
3 9
6 8
9 4



*/

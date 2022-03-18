#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < b; i++)
#define f first
#define s second

int main(){
    int t;cin >> t;
    while(t--){
        vector<pair<int, pair<int, int>>> adjList;
        int n, m; cin >> n >> m;
        rep(i, 0, m){
            int a, b, c;cin >> a >> b >> c;
            adjList.push_back({c,{min(b-1,a-1), max(b-1,a-1)}});
        }
        int ans = 0;
        int parent[n];
        rep(i, 0, n)parent[i] = i;
        sort(adjList.begin(), adjList.end());
        rep(i, 0, m){
            int w = adjList[i].f;
            int x = adjList[i].s.f;
            int y = adjList[i].s.s;
            if (parent[x] == parent[y])continue;
            parent[x] = parent[y];
            ans+=w;
        }
        cout << ans << endl;
    }
}



#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void)
{
    int n, m; cin >> n >> m;
    vector<pair<int, int>> adj[n]; // {node,weight}
    for(int i = 0; i < m; i++){
        int x,y,wt; cin >> x >> y >> wt;
        adj[x].push_back({y,wt});
        adj[y].push_back({x, wt});
    }
    set<pair<int, int>> pq;
    pq.insert({0,0}); //0 -> source
    int d[n];
    for(int i = 0; i < n; i++)d[i] = INT_MAX;
    d[0] = 0;
    while(!pq.empty()){
        int node = pq.begin()->second;
        pq.erase(pq.begin());
        for(auto u : adj[node]){
            if (d[node] + u.second < d[u.first]){
                pq.erase({d[u.first], u.first});
                d[u.first] = u.second + d[node];
                pq.insert({d[u.first], u.first});
            }
        }
    }
    for(int i = 0; i < n; i++){
        cout << i << ' ' << d[i] << endl;
    }
}

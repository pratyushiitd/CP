// https://cses.fi/problemset/task/1675/
#include <bits/stdc++.h>

using namespace std;

#define int long long
int n, m, k, q;
const int MAX = 1e5+2;

int rnk[MAX];
int par[MAX];

void make_set(int n){
    for(int i = 1; i <= n; i++){
        par[i] = i; rnk[i] = 1;
    }
}

int find_set(int i){
    if (par[i] == i)return i;
    return par[i] = find_set(par[i]);
}
int merge(int a, int b){
    int p1 = find_set(a), p2 = find_set(b);
    if (p1 != p2){
        if (rnk[p1] > rnk[p2]){
            rnk[p1]+=rnk[p2];
            par[p2] = p1;
        }else{
            rnk[p2]+=rnk[p1];
            par[p1] = p2;
        }
    }
    return max(rnk[p1], rnk[p2]);
}
void solve(){
    cin >> n >> m;
    make_set(n);
    vector<pair<int, pair<int, int>>> edges;
    while(m--){
        int u, v, c; cin >> u >> v >> c;
        edges.push_back({c, {u, v}});
    }
    sort(edges.begin(), edges.end());
    int sum = 0;
    int cnt = 0;
    for(auto e:edges){
        int u = e.second.first, v = e.second.second;
        if (find_set(u) == find_set(v))continue;
        merge(u, v);
        sum+=e.first;    
        cnt++;
    }
    if (cnt == n-1)cout << sum << endl;
    else{
        cout << "IMPOSSIBLE" << endl;
    }
}
int32_t main(){
    solve();
    return 0;
}

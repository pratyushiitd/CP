// https://cses.fi/problemset/task/1196
#include <bits/stdc++.h>

using namespace std;
#define ar array
#define int long long
const int MAX = 1e5+2;
map<int, int> mp;
int arr[MAX], n, m, k;
vector<pair<int, int>> adj[MAX];
void solve(){
    cin >> n >> m >> k;
    while(m--){
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    int cnt[n+1];
    memset(cnt, 0, sizeof(cnt));
    vector<int> ans;
    while(!pq.empty() && cnt[n] < k){
        int c = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        cnt[u]++;
        if (u == n){
            ans.push_back(c);
        }
        if (cnt[u] <= k){
            for(auto v: adj[u]){
                pq.push({c+v.second, v.first});
            }
        }
    }
    sort(ans.begin(), ans.end());
    for(auto x: ans)cout << x << ' ';
    cout << endl;
}
int32_t main(){
    int t=1;
    while(t--)solve();
    return 0;
}

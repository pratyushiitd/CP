// https://www.spoj.com/problems/ARBITRAG/
#include <bits/stdc++.h>

using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define fi first
#define se second
#define ld long double
const int MAX = 200002;
const ld INF = -1e9;
map<string, int> id;
int n, m;
vector<vector<ld>> dist;
void solve(){
    int n; 
    int t = 1;
    string blank;
    while(cin >> n){
        if (n == 0)break;
        id.clear();
        dist.clear();
        dist.resize(n+1, vector<ld>(n+1));
        for(int i = 0; i < n; i++){
            string s; cin >> s;
            id[s] = i;
        }
        getline(cin, blank);
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= n; j++)dist[i][j] = INF;
            dist[i][i] = 0.0;
        }
        int m; cin >> m;
        while(m--){
            ld w;
            string a, b; cin >> a >> w >>  b;
            int u = id[a], v = id[b];
            dist[u][v] = max(dist[u][v], log(w));
        }
        getline(cin, blank);
        bool ans = false;
        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    dist[i][j] = max(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        for(int i = 0; i < n; i++){
            if (dist[i][i] > 0){
                ans = true;
                break;
            }
        }
        if (ans) cout << "Case " << t << ": " << "Yes\n"; 
        else cout << "Case " << t << ": " << "No\n"; 
        t++;
    }
}
int32_t main() {
    fast;
    solve();
    return 0;
}

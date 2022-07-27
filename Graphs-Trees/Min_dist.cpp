// https://www.spoj.com/problems/KATHTHI/
#include <bits/stdc++.h>

using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define fi first
#define se second
const int MAX = 1002;
int n,m;
string arr[MAX];
int dist[MAX][MAX];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool valid(int nx, int ny){
    return (nx >= 0 && ny >= 0 && nx < n && ny < m);
}
void get_set(){ // Dijkstra with set
    dist[0][0] = 0;
    set<pair<int, pair<int, int>>> st;
    st.insert({0, {0,0}});
    while(!st.empty()){
        pair<int, int> p = (*st.begin()).second;
        st.erase(st.begin());
        for(int k = 0; k < 4; k++){
            int nx = p.fi+dx[k], ny = p.se + dy[k];
            if (!valid(nx, ny))continue;
            int edge = arr[nx][ny] != arr[p.fi][p.se];
            if (dist[nx][ny] > dist[p.fi][p.se]+edge){
                st.erase({dist[nx][ny], {nx, ny}});
                dist[nx][ny] = dist[p.fi][p.se] + edge;
                st.insert({dist[nx][ny], {nx, ny}});
            }
        }
    }
}
void get_01(){ // 0-1 BFS Deque
    dist[0][0] = 0;
    deque<pair<int, pair<int, int>>> dq;
    dq.push_back({0, {0,0}});
    while(!dq.empty()){
        pair<int, int> p = dq.front().second;
        dq.pop_front();
        for(int k = 0; k < 4; k++){
            int nx = p.fi+dx[k], ny = p.se + dy[k];
            if (!valid(nx, ny))continue;
            int edge = arr[nx][ny] != arr[p.fi][p.se];
            if (dist[nx][ny] > dist[p.fi][p.se]+edge){
                dist[nx][ny] = dist[p.fi][p.se] + edge;
                if (edge == 0){
                    dq.push_front({dist[nx][ny], {nx, ny}});
                }else{
                     dq.push_back({dist[nx][ny], {nx, ny}});
                }
            }
        }
    }
}
void solve(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)cin >> arr[i];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)dist[i][j] = LLONG_MAX;
    }
    get_01();
    cout << dist[n-1][m-1] << endl;
}
int32_t main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}

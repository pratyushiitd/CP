// https://www.spoj.com/problems/BITMAP/
#include <bits/stdc++.h>

using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

const int MAX = 200;
int arr[MAX][MAX], n, m;
int ans[MAX][MAX];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

void bfs(int i, int j){
    queue<pair<int, int>> q;
    q.push({i, j});
    while(!q.empty()){
        int x = q.front().first, y = q.front().second;
        q.pop();
        for(int k = 0; k < 4; k++){
            int nx = x+dx[k], ny = y + dy[k];
            if (nx >= 0 && nx < n && ny>=0 && ny < m && ans[nx][ny] > ans[x][y] + 1 && arr[nx][ny] == 0){
                ans[nx][ny] = min(ans[nx][ny], ans[x][y]+1);
                q.push({nx, ny});
            }
        }
    }
}
void solve(){
    cin >> n >> m;
    vector<pair<int, int>> white;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        for(int j = 0; j < m; j++){
            arr[i][j] = s[j]-'0';
            ans[i][j] = INT_MAX;
            if (arr[i][j] == 1)white.push_back({i, j});
        }
    }
    for(auto x: white){
        int i = x.first, j = x.second;
        ans[i][j] = 0;
        bfs(i, j);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)cout << ans[i][j] << ' ';
        cout << endl;
    }
}
int32_t main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}

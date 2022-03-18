//https://codeforces.com/problemset/problem/1638/D

#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < b; i++)
#define f first
#define s second
int arr[1001][1001];

int main(){
    int n, m; cin >> n >> m;
    rep(i, 0, n){
        rep(j, 0, m){
            cin >> arr[i][j];
        }
    }
    queue<pair<int, int>> q;
    rep(i, 0, n-1)rep(j, 0, m-1){
        if (arr[i][j] == arr[i+1][j]
           && arr[i+1][j] == arr[i][j+1]
           && arr[i][j+1] == arr[i+1][j+1]){
            q.push({i,j});
        }
    }
    // while(!q.empty()){cout << q.front().f << ' ' << q.front().s << ' ';q.pop();}
        // cout << "hi";return 0;
    vector<pair<int, pair<int, int>>> ans;
    bool visited[n][m];
    memset(visited, false, sizeof(visited));
    while(!q.empty()){
        int i = q.front().f, j = q.front().s;q.pop();
        // cout << i << j;
        int c = 0;
        rep(a,0,2)rep(b,0,2){
            if (arr[i+a][j+b]> 0)c = arr[i+a][j+b];
            arr[i+a][j+b] = -1;
        }
        // cout << c << endl;return 0;
        if (c > 0)ans.push_back({i,{j, c}});
        rep(a,i-1,i+2)rep(b,j-1,j+2){
            if (!(a >= 0 && b >=0 && a < n && b < m) || visited[a][b])continue;
            int c = 0;bool valid = true;
            rep(q,a,a+2)rep(w,b,b+2){
                if (arr[q][w] == -1)continue;
                if (c == 0)c = arr[q][w];
                else if (c != arr[q][w])valid = 0;
            }
            if (valid){
                q.push({a,b});
                visited[a][b] = true;
            }
        }
    }
    int valid = true;
    rep(i, 0, n)rep(j, 0, m)if(arr[i][j]!=-1)valid = false;
    if (!valid){cout << -1 << endl;return 0;}
    cout << ans.size() << '\n';
    for(int i = ans.size()-1; i >=0 ; i--){
        cout << ans[i].first + 1 << ' ' << (ans[i].second).first + 1 << ' ' << (ans[i].second).second << '\n';
    }
}



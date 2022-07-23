// https://atcoder.jp/contests/dp/tasks/dp_u
#include <bits/stdc++.h>

using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

const int MAX = 18;
int n, arr[MAX][MAX];
int dp[(1<<20)];
const int inf = -1e18;
int get(int mask){
    if (dp[mask]!=inf)return dp[mask];
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if ((mask & (1<<i)) && (mask & (1 << j)))
                ans+=arr[i][j];
        }
    }
    for(int i = mask&(mask-1); i>0; i = (i-1)&mask){
        ans = max(ans, get(i)+get(mask^i));
    }
    return dp[mask] = ans;
}

void solve(){
    cin >> n;
    for(int i =0; i < (1<<n); i++)dp[i] = inf;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)cin >> arr[i][j];
    }
    cout << get((1<<n)-1) << endl;
}
int32_t main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--)solve();
    return 0;
}

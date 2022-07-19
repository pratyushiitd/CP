// https://atcoder.jp/contests/dp/tasks/dp_c

#include <bits/stdc++.h>

using namespace std;

#define int long long
const int MAX = 1000001;

int dp[MAX][4];
void solve(){
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        int a, b, c; cin >> a >> b >> c;
        if (i==1){
            dp[1][1] =a; dp[1][2] = b;dp[1][3] = c;
        }else{
            dp[i][1] = max(dp[i-1][2], dp[i-1][3]) + a;
            dp[i][2] = max(dp[i-1][3], dp[i-1][1]) + b;
            dp[i][3] = max(dp[i-1][2], dp[i-1][1]) + c;
        }
    }
    cout << max(dp[n][1], max(dp[n][2], dp[n][3]));
}
int32_t main(){
    
    int t = 1;
    // cin >> t;
    while(t--)solve();
    return 0;
}

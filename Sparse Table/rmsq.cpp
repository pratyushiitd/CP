// https://www.spoj.com/problems/RMQSQ/
#include <bits/stdc++.h>

#define int long long
const int MAX = 2e5+2;
int arr[MAX];
using namespace std;
int n, q, m;
int dp[MAX][25];
int lg[MAX];
void solve(){
    cin >> n;
    lg[1] = 0;
    for(int j = 2; j <= n+1; j++)lg[j] = lg[j/2]+1;
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= n; i++){
        cin >> dp[i][0];
    }
    for(int k = 1; k < 25; k++){
        for(int j = 1; j + (1 << (k-1)) <= n; j++){
            dp[j][k] = min(dp[j][k-1], dp[j + (1 << (k-1))][k-1]);
        }
    }
    int q; cin >> q;
    while(q--){
        int l, r; cin >> l >> r;
        l++; r++;
        int len = lg[r-l+1];
        cout << min(dp[l][len], dp[r-(1<<len)+1][len]) << endl;
    }
}
int32_t main(){
    
    solve();
    return 0;
}

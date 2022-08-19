// https://cses.fi/problemset/task/1158
#include <bits/stdc++.h>

using namespace std;
#define int long long
const int MAX = 2e5+2;

int dp[MAX], n, m, a, b, x;
int lg[MAX], arr[MAX], brr[MAX];
void solve(){
    cin >> n >> x;
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < n; i++)cin >> arr[i];
    for(int i = 0; i < n; i++)cin >> brr[i];
    for(int j = 0; j < n; j++){
        for(int i = x; i >= 0; i--){
        if (i)dp[i] = max(dp[i], dp[i-1]);
            if (i - arr[j] >= 0){
                dp[i] = max(dp[i], dp[i-arr[j]]+brr[j]);
            }
        }
    }
    cout << dp[x] << endl;
}
int32_t main(){
    
    int t = 1;
    // cin >> t;
    while(t--)solve();
    return 0;
}

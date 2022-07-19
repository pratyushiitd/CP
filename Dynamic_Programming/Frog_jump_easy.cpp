// https://atcoder.jp/contests/dp/tasks/dp_a
#include <bits/stdc++.h>

using namespace std;

#define int long long
const int MAX = 1000001;

int dp[MAX];
void solve(){
    memset(dp, 0, sizeof(dp));
    int n; cin >> n;
    vector<int> arr(n+1);
    for(int i = 0; i < n; i++){
        cin >> arr[i+1];
    }
    dp[1] = 0;
    dp[2] = dp[1]+abs(arr[1]-arr[2]);
    for(int i = 3; i <= n; i++)dp[i] = min(dp[i-2]+abs(arr[i]-arr[i-2]),
                                          dp[i-1]+abs(arr[i]-arr[i-1]));
    cout << dp[n] << endl;
}
int32_t main(){
    
    int t = 1;
    // cin >> t;
    while(t--)solve();
    return 0;
}

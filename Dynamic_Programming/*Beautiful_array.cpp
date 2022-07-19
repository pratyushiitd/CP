// https://codeforces.com/contest/1475/problem/G 
#include <bits/stdc++.h>

using namespace std;

#define int long long
const int MAX = 2000001;


void solve(){
    int dp[MAX] = {0};
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)cin >> arr[i];
    sort(arr, arr+n);
    int ans = INT_MAX;
    for(int i = 0; i < n; i++){
        int x = arr[i];
        if (i && arr[i]==arr[i-1])dp[x]++;
        else 
        for(int j = 1; j*j <= x; j++){
            if (x%j==0)dp[x] = max(dp[x], max(dp[j],dp[x/j])+1);
        }
        ans = min(ans, n-dp[x]);
    }
    cout << ans << '\n';
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}

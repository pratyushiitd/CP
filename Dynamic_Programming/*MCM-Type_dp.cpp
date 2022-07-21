// https://www.spoj.com/problems/MIXTURES/

#include <bits/stdc++.h>

using namespace std;
const int MAX = 101;
int dp[MAX][MAX];
int arr[MAX];
int pre[MAX];
int n;
int get(int l, int r){
    if (l == r)return 0;
    if (dp[l][r] != -1)return dp[l][r];
    if (l == r-1)return dp[l][r] = arr[l]*arr[r];
    dp[l][r] = INT_MAX;
    for(int k = l; k < r; k++){
        int s1 = get(l, k);
        int s2 = get(k+1, r);
        int val1 = (pre[k+1] - pre[l])%100;
        int val2 = (pre[r+1] - pre[k+1])%100;
        dp[l][r] = min(dp[l][r], s1+s2+val1*val2);
    }
    return dp[l][r];
}
void solve(int n){
    memset(dp, -1, sizeof(dp));
    memset(pre, 0, sizeof(pre));
    for(int i = 1; i <= n; i++){
        pre[i]+=pre[i-1]+arr[i-1];
    }
    cout << get(0, n-1) << endl;
}
int32_t main(){
    
    while(cin >> n){
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        solve(n);
    }
    return 0;
}

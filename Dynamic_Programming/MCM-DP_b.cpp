// https://atcoder.jp/contests/dp/tasks/dp_n
// Time: 17:44
  
#include <bits/stdc++.h>

using namespace std;

#define int long long
const int MAX = 405;
int dp[MAX][MAX];
int n, arr[MAX];
int pre[MAX];
int get(int l, int r){

    if (l == r-1)return 0;
    if (l == r-2)return arr[l]+arr[l+1];
    if (dp[l][r]!=-1)return dp[l][r];
    int val = LLONG_MAX;
    for(int k = l+1; k < r; k++){
        int v1 = get(l, k)+pre[k] - pre[l];
        int v2 = get(k, r) + pre[r] - pre[k];
        val = min(val, v1+v2);
    }
    return dp[l][r] = val;
}
void solve(){
    memset(dp, -1, sizeof(dp));
    memset(pre, 0, sizeof(pre));
    memset(arr, 0, sizeof(arr));
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        pre[i+1]+=pre[i]+arr[i];
    }
    cout << get(0, n) << endl;
}
    
int32_t main(){
    int t = 1;
    while(t--)solve();
    return 0;
}

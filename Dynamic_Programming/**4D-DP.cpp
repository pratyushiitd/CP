// https://codeforces.com/problemset/problem/1286/A
#include <bits/stdc++.h>

using namespace std;
const int MAX = 101;
int arr[MAX];
int n;
int dp[MAX][MAX][MAX][3];

int solve(int i, int o, int e, int prev){
    if (o < 0 || e < 0)return INT_MAX-1;
    if (i == n)return 0;
    if (dp[i][o][e][prev+1]>=0)return dp[i][o][e][prev+1];
    if (i==0){
        if (arr[i]>=0)return dp[i][o][e][prev+1] = solve(i+1, o, e, arr[i]);
        else return dp[i][o][e][prev+1] = min(solve(i+1, o-1, e, 1),solve(i+1, o, e-1, 0)) ;
    }
    else{
        if (arr[i]>=0)return dp[i][o][e][prev+1] = solve(i+1, o, e, arr[i]) + (prev != arr[i]);
        else return dp[i][o][e][prev+1] = min(solve(i+1, o-1, e, 1) + (prev == 0), solve(i+1, o, e-1, 0) + (prev == 1));
    }
}
void solve(){
    cin >> n;
    memset(arr, -1, sizeof(arr));
    int e = n/2, o = (n+1)/2;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if (x == 0)continue;
        x%=2;
        if (x)o--;
        else e--;
        arr[i] = x;
    }
    memset(dp, -1 ,sizeof(dp));
    cout << solve(0, o, e, -1) << endl;
}
int32_t main(){
    int t = 1; 
    // cin >> t;
    while(t--)solve();
    return 0;
}
 // 1 -1 -1 0 0 -1 1 -1 1 -1 0 -1 1 -1 1 -1 0 -1 -1 0

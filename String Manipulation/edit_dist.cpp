#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e3+2;
int n, m, t, q;
int lps[MAX];
int dp[MAX][MAX];
string a, b;
int get(int i, int j){
    if (dp[i][j] != -1)return dp[i][j];
    if (a[i-1] == b[j-1]){
        return dp[i][j] = get(i-1, j-1);
    }
    else return dp[i][j] = 1+min(get(i-1, j), min(get(i, j-1), get(i-1, j-1)));
}
void solve(){
    cin >> a >> b;
    n = a.length(), m = b.length();
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i <= m; i++){
        dp[0][i] = i;
    }
    for(int j = 0; j <= n; j++){
        dp[j][0] = j;
    }
    // for(int i(0); i++<n;){
    //     for(int j(0); j++<m;){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << get(n, m) << endl;
}
int main() {
    // your code goes here
    cin >> t;
    // int t = 1;
    while(t--)solve();
    return 0;
}

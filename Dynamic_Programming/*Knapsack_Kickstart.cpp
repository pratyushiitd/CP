// https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc7/00000000001d3f56
#include <bits/stdc++.h>

using namespace std;

int n, k, p;
int dp[51][1501];
int solve(){
    cin >> n >> k >> p;
    memset(dp, 0, sizeof(dp));
    int x;
    for(int i = 0; i < n; i++){
        memcpy(dp[i+1], dp[i], sizeof(dp[0]));
        for(int j = 0, s = 0; j < k; j++){
            cin >> x;
            s+=x;
            // use j+1 plates
            for(int l = 0; l+j+1<= p; l++){
                dp[i+1][l+j+1] = max(dp[i+1][l+j+1], dp[i][l]+s);
            }
        }
    }
    return dp[n][p];
}
int32_t main(){
    
    int t;cin >> t;
    for(int i = 0; i < t; i++){
        printf("Case #%d: %d\n", i+1, solve());
    }
    return 0;
}

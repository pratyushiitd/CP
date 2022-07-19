// https://www.hackerearth.com/practice/algorithms/dynamic-programming/2-dimensional/practice-problems/algorithm/exponential-subset-f78d066f/
#include <bits/stdc++.h>

#define int long long

using namespace std;

const int MAX = 10001;
void solve(){
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)cin >> arr[i];
    int dp[MAX];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = MAX-1; j >= 0; j--){
            if (j-arr[i]>=0) dp[j] |= dp[j-arr[i]];
        }
    }
    for(int i = 0; i < n; i++){
        int x = arr[i]*arr[i];;
        bool valid = false;
        for(int j = 0; j < MAX; j++){
            if (!dp[j])continue;
            if (x == 1){
                valid = dp[1];
                continue;
            }
            while(x < MAX){
                if (dp[x])valid = true;
                x*=arr[i];
            }
        }
        if (valid )cout << "1 ";
            else cout << "0 ";
    }
    cout << endl;
}
int32_t main(){
    int t; cin >> t;
    while(t--)solve();
    return 0;
}

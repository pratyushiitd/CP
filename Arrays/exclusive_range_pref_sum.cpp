// https://codeforces.com/contest/1473/problem/D
#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve(){
    int n, m;
    cin >> n >> m;
    string str; cin >> str;
    int max_val[n+1], min_val[n+1];
    
    max_val[0] = 0;
    min_val[0] = 0;
    int curr_val = 0;
    for(int i = 1; i <= n; i++){
        if(str[i-1]=='-')curr_val--;
        else curr_val++;
        max_val[i] = max(max_val[i-1], curr_val);
        min_val[i] = min(min_val[i-1], curr_val);
    }
    int suffix_max[n], suffix_min[n];
    int prefix_sum[n];
    str[0] == '-' ? prefix_sum[0] = -1 : prefix_sum[0] = 1;
    for(int i = 1; i < n; i++)str[i] == '-' ? prefix_sum[i] = prefix_sum[i-1]-1:
    prefix_sum[i] = prefix_sum[i-1]+1;
    suffix_max[n-1] = prefix_sum[n-1];
    suffix_min[n-1] = prefix_sum[n-1];
    for(int i = n-2; i >= 0; i--){
        suffix_max[i] = max(suffix_max[i+1], prefix_sum[i]);
        suffix_min[i] = min(suffix_min[i+1], prefix_sum[i]);
    }
    
    // for(int i = 0; i < n; i++){
    //     cout << max_val[i+1] << min_val[i+1] << suffix_max[i] << suffix_min[i] << prefix_sum[i] << endl;
    // }
    for(int i = 0; i < m; i++){
        int l, r; cin >> l >> r;
        int max_ = max_val[l-1];
        int min_ = min_val[l-1];
        int max2 = 0, min2 = 0;
        // cout << min_ << ' ' << max_ << endl;
        l--; r--;
        if (r!=str.length()-1){
            max2 = suffix_max[r+1] - prefix_sum[r];
            min2 = suffix_min[r+1] - prefix_sum[r];
        }
            if (l > 0){
                max2+=prefix_sum[l-1];
                min2+=prefix_sum[l-1];
            }
        int ans = 0;
        if (min_ > max2 || min2 > max_){
            ans = max2-min2+1 + max_ - min_ + 1;
        }
        else {
            ans = max(max_, max2) - min(min_, min2) + 1;
        }
        // cout << min2 << ' ' << max2 << endl;
        cout << ans << endl;
    }
}
int32_t main() {
    int t; cin >> t;
    while(t--)solve();
    return 0;
}

// -+--+--+
// -1, +1, -1, -1, +1, -1, -1, +1
// -1, 0, -1, -2, -1, -2, -3, -2
/*
1
2
4
4
3
3
4
2
3
2
1
2
2
2

*/

// https://www.hackerearth.com/practice/algorithms/dynamic-programming/bit-masking/practice-problems/algorithm/trophy-of-xorasia-0a2d466a/
#include <bits/stdc++.h>

using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

const int MAX = 22;
int n, arr[MAX];
int dp_max[(1<<MAX)];
int dp_min[(1<<MAX)];

int get_max(int mask){
    if (dp_max[mask]!=-1)return dp_max[mask];
    if (__builtin_popcount(mask) == 0)return 0;
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if ((mask & (1<<i)) && (mask & (1 << j)))
                ans= max(ans, (arr[i]^arr[j]) + get_max(mask ^ (1 << i) ^ (1 << j)));
        }
    }
    return dp_max[mask] = ans;
}
int get_min(int mask){
    if (dp_min[mask]!=-1)return dp_min[mask];
    if (__builtin_popcount(mask) == 0)return 0;
    int ans = LLONG_MAX;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if ((mask & (1<<i)) && (mask & (1 << j)))
                ans= min(ans, (arr[i]^arr[j]) + get_min((mask ^ (1 << i)) ^ (1 << j)));
        }
    }
    if (ans == LLONG_MAX)ans = 0;
    return dp_min[mask] = ans;
}

void solve(){
    cin >> n;
    memset(dp_max, -1, sizeof(dp_max));
    memset(dp_min, -1, sizeof(dp_min));
    for(int i = 0; i < n; i++)cin >> arr[i];
    cout << get_min((1<<n)-1) << ' ' << get_max((1<<n)-1) << endl;
}
int32_t main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--)solve();
    return 0;
}

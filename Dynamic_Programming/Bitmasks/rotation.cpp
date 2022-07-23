// https://codeforces.com/problemset/problem/1097/B
#include <bits/stdc++.h>

using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

const int MAX = 1e5+2;
int n, arr[MAX];


void solve(){
    cin >> n;
    for(int i = 0; i < n; i++)cin >> arr[i];
    int valid = false;
    for(int mask = 0; mask < (1<<n); mask++){
        int sum = 0;
        if (valid)break;
        for(int i = 0; i < n; i++)
        {
            if (mask & (1 << i))sum+=arr[i];
            else sum-=arr[i];
        }
        if (sum%360 == 0)valid = true;
    }
    if (valid)cout << "YES" << endl;
    else cout << "NO" << endl;
}
int32_t main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--)solve();
    return 0;
}

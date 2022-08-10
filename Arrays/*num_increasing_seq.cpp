// https://cses.fi/problemset/result/4404618/
#include <bits/stdc++.h>

#define int long long
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define f first
#define s second

using namespace std;
int n, m, x, y, k, a, b, t;
const int MAX = 2e6+2, mod = 1e9+7;
int arr[MAX];
map<int, int> mp;
void solve(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        mp[--arr[i]] = i;
    }
    int ans = 1;
    for(int i = 1; i < n; i++)ans+= mp[i-1] > mp[i];
    cout << ans << endl;
}

int32_t main(){
    fast;
    // cin >> t;
    t = 1;
    while(t--)solve();
    return 0;
}

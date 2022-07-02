// https://codeforces.com/problemset/problem/776/B

#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve(){
    int n; cin >> n;
    n++;
    bool is_prime[n+1];
    for(int i = 0; i <= n; i++)is_prime[i] = 1;
    for(int i = 2; i*i <= n; i++){
        if (is_prime[i])
        for(int j = i*i; j <= n; j+=i){
            is_prime[j] = 0;
        }
    }
    if (n-1 > 2){
        cout << 2 << endl;
    }
    else cout << 1 << endl;
    for(int i = 2; i <= n; i++){
        if (is_prime[i])cout << "1 ";
        else cout << "2 ";
    }
    cout << endl;
}
int32_t main(){
    // int t; cin >> t;
    int t = 1;
    while(t--)solve();
    return 0;
}

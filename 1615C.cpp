//https://codeforces.com/contest/1615/problem/C

#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < b; i++)
#define f first
#define s second

int main(){
int t;cin >> t;
    while(t--){
        int n; cin >> n;
        string a, b; cin >> a >> b;
        int cnt_a = 0, cnt_b = 0, cnt_ab = 0;
        rep(i, 0, n){
            if (a[i] == '1')cnt_a++;
            if (b[i] == '1')cnt_b++;
            if (a[i] == '1' && b[i] =='1')cnt_ab++;
        }
        int ans = INT_MAX;
        if(cnt_a == cnt_b){
            ans =  (cnt_a - cnt_ab)*2;
        }
        int cnt_00 = n - cnt_a - cnt_b + cnt_ab;
        if (cnt_00 == cnt_ab-1){
            ans = min(ans, cnt_00*2+1);
        }
        if (ans == INT_MAX)ans = -1;
        cout << ans << '\n';
    }
}



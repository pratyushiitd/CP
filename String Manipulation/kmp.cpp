// https://www.spoj.com/problems/NHAY/
#include <bits/stdc++.h>
 
using namespace std;
#define int long long
int n, m, x, y, k;
const int MAX = 2e5+1;
vector<int> adj[MAX];
int dp[MAX], arr[MAX], lps[MAX];
const int mod = 1e9+7;

void solve(){
    memset(lps, 0, sizeof(lps));
    string s, p; cin >> p >> s;
    n = s.length(), m = p.length();
    // cout << s << ' ' << p << endl;
    for(int i = 1; i < m; i++){
        int j = lps[i-1];
        while(j && p[i]!=p[j]) {
            j = lps[j-1];
        }
        if (p[i] == p[j])j++;
        lps[i] = j;
        // cout << lps[i] << endl;
    }
    int i(0), j(0);
    while(i < n){
        if (s[i] == p[j]){
            j++;
            i++;
            if (j == m)cout << i-j << endl;
        }
        else if(s[i]!=p[j]){
            if (j)
            j=lps[j-1];
            else i++;
        }
    }
    cout << endl;
}
int32_t main(){
    
    // int t = 1;
    // cin >> t;
    // while(t--)solve();
    while(cin >> x)solve();
    return 0;
}

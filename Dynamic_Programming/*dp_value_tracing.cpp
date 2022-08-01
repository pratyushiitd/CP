// https://codeforces.com/contest/1714/problem/D

#include <bits/stdc++.h>

using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define fi first
#define se second
#define ld long double
const int MAX = 200002;
const int INF = 1e9;
int arr[MAX];
map<string, int> id;
int n, m;
vector<int> adj[MAX];
int val[MAX][2];
int A[MAX];
int B[MAX];
int ans[MAX];
string t, s[MAX];
int dp[MAX];
int p[MAX];
int sol(int i = 0){
    if (i >= (int)t.length())return 0;
    if (dp[i]!=-1)return dp[i];
    int ans = INT_MAX;
    for(int k = 0; k < n; k++){
        int b = s[k].length();
        if (t.substr(i, b) == s[k]){
            for(int j = i+1; j <= i+b; j++){
                int val = sol(j);
                ans = min(ans, 1ll+val);
            }
        }
    }
     return dp[i] = ans;
}
void pat(int i= 0){
    for(int k = 0; k < n; k++){
        int b = s[k].length();
        if (t.substr(i, b) == s[k]){
            if (dp[i] == 1 && i+b == (int)t.length()){
                p[i+1]=k+1;return;
            }
            for(int j = i+1; j <= i+b; j++){
                if (dp[j] == dp[i] - 1){
                    pat(j);
                    p[i+1] = k+1;
                    break;
                }
            }
        }
    }
}
void solve(){
    cin >> t;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    memset(p, -1, sizeof(p));
    for(int i = 0; i < n; i++)cin >> s[i];
    sol();
    if (dp[0] >= INT_MAX){
        cout << -1 << endl;
    }else{
        cout << dp[0] << endl;
        pat();
        for(int i = 1; i <= (int)t.length(); i++){
            if (p[i]!=-1)cout << p[i] << ' ' << i << endl;
        }
    }
}
int32_t main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}

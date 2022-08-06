// https://www.spoj.com/problems/PERIOD/
#include <bits/stdc++.h>
 
using namespace std;
#define int long long
int n, m, x, y, k;
const int MAX = 2e6+1;
vector<int> adj[MAX];
int dp[MAX], arr[MAX], lps[MAX];
const int mod = 1e9+7;
int tt = 0;
void solve(){
    tt++;
    cout << "Test case #" << tt << endl;
    cin >> n; 
    string s; cin >> s;
    memset(lps, 0, sizeof(lps));
    memset(arr, 0, sizeof(arr));
    for(int i = 1; i < n; i++){
        int j = lps[i-1];
        while(j && s[i]!=s[j])j = lps[j-1];
        if (s[i] == s[j])j++;
        lps[i] = j;
        int r = i - lps[i] + 1;
        if ((i+1) % r == 0 && (i+1)/r > 1){
            cout << i+1 << ' ' << (i+1)/r << endl;
        }
    }
    cout << endl;
}
int32_t main(){
    
    int t = 1;
    cin >> t;
    while(t--)solve();
    // while(cin >> x)solve();
    return 0;
}

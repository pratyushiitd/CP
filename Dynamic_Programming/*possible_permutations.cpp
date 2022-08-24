// https://atcoder.jp/contests/dp/tasks/dp_t
#include <bits/stdc++.h>

#define int long long
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define test int t; cin >> t; while(t--)
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define ff first
#define ss second
#define ld long double
#define pii pair<int, int>
#define fo(i, n) for(int i = 0; i < n; i++)
using namespace std;

const int MAX = 3001;
const int mod = 1e9+7;
const int inf = LLONG_MAX;

int n,x,y,c,d,k,q, v, w, m;

string a, b;
vector<int> adj[MAX];
int bin_pow(int a, int b, int m){
	if (b == 1)return a%m;
	int sq = bin_pow(a, b/2, m);
	if (b%2) return ((sq%m) * (sq%m) * a) % m;
	else return ((sq%m) * (sq%m)) % m;
}

int dp[MAX][MAX];

// dp [ i ] [ j ] [ k ] = > 1....i , last = atmost j, k = 0 -> > j or < j

void solve(){
	cin >> n >> a;
	memset(dp, 0, sizeof(dp));
	dp[0][1] = 1;
	for(int i = 1; i <= n-1; i++){
		vector<int> pre(n+1);
		pre[0] = dp[i-1][0];
		for(int j = 1; j <= n; j++)pre[j] = (pre[j-1] + dp[i-1][j]) % mod;
 		for(int j = 1; j <= i+1; j++){
			if (a[i-1] == '<'){
				for(int k = 1; k < j; k++)dp[i][j] = pre[k];
			}
			else {
				for(int k = j; k <= i+1; k++)dp[i][j] = (pre[n] - pre[j-1] + mod) % mod;
			}
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i++)ans+= dp[n-1][i];
		cout << ans % mod << endl;
}
// 0-> (1, 2, 3, 4)
// 1-> (1, 2) 1
// (1, 3) 2
// (1, 4) 
// (2, 3) 
// (2, 4) 
// (3, 4)
int32_t main(){

	fast;

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	// test 
	solve();
	return 0;
}

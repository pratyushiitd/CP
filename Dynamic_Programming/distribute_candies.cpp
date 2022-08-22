//https://atcoder.jp/contests/dp/tasks/dp_m

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

const int MAX = 3e5+3;
const int mod = 1e9+7;
const int inf = INT_MAX;

int n,x,y,c,d,k,q, v, w, m;

string a, b;
vector<int> adj[MAX];
vector<int> rev[MAX];
int bin_pow(int a, int b, int m){
	if (b == 1)return a%m;
	int sq = bin_pow(a, b/2, m);
	if (b%2) return ((sq%m) * (sq%m) * a) % m;
	else return ((sq%m) * (sq%m)) % m;
}
bool visited[MAX];
int arr[MAX];
int pre[MAX];
int dp[101][MAX];

void solve(){
	cin >> n >> k;
	fo(i, n)cin >> arr[i+1];
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	int pre[MAX];
	memset(pre, 0, sizeof(pre));
	for(int j = 1; j <= n; j++){
		pre[0] = dp[j-1][0] % mod;
		for(int i = 1; i <= k; i++)pre[i] = (pre[i-1] + dp[j-1][i]) % mod;
		for(int i = 0; i <= k; i++){
			dp[j][i] = pre[i] % mod;
			if (i - arr[j] -1 >= 0)dp[j][i] = (dp[j][i] - pre[i-arr[j]-1]) % mod + mod;
		}
	}
	cout << dp[n][k] % mod << endl;

}
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

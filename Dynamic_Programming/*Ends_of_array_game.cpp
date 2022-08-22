// https://atcoder.jp/contests/dp/tasks/dp_l
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

const int MAX = 3e3+3;
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
int dp[MAX][MAX][3];
int get(int i, int j, int p){
	if (i == j)return arr[i];
	if (dp[i][j][p] != -1)return dp[i][j][p];
	return dp[i][j][p] = max(
			arr[i] + pre[j] - pre[i] - get(i+1, j, 3-p),
			arr[j] + pre[j-1] - pre[i-1] - get(i, j-1, 3-p)
		);
}
void solve(){
	memset(pre, 0, sizeof(pre));
	cin >> n;
	for(int i = 1; i <= n; i++)cin >> arr[i];
		arr[0] = 0;
	for(int i = 1; i <= n; i++)pre[i] = pre[i-1] + arr[i];
	memset(dp, -1, sizeof(dp));
	cout << 2*get(1, n, 1) - (pre[n]) << endl;
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

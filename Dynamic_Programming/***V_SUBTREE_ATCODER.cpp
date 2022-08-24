// https://atcoder.jp/contests/dp/tasks/dp_v
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

const int MAX = 1e5+3;
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

int dp[MAX][2];
vector<int> prod[MAX][2];
void dfs(int i = 1, int par = -1){
	int ans = 1;
	vector<int> temp;
	for(auto x: adj[i]){
		if (x != par){
			dfs(x, i);
			temp.push_back((dp[x][0] + 1) % m);
			ans = (ans * (dp[x][0] + 1)) % m;
		}
	}
    dp[i][0] = ans;
    if (temp.size() == 0)return;
	prod[i][0].push_back(temp[0]);
	for(int ii = 1; ii < temp.size(); ii++)prod[i][0].push_back((prod[i][0].back() * temp[ii]) % m);
	reverse(temp.begin(), temp.end());
	prod[i][1].push_back(temp[0]);
	for(int ii = 1; ii < temp.size(); ii++)prod[i][1].push_back((prod[i][1].back() * temp[ii]) % m);
	reverse(prod[i][1].begin(), prod[i][1].end());
}
void dfs2(int i = 1, int par = -1){
	int t = 0;
	for(auto x: adj[i]){
		if (x!=par){
			int par_cnt2 = 1;
			dp[x][1] = dp[i][1] + 1;
			if (t > 0)dp[x][1] = (dp[x][1] * prod[i][0][t-1]) % m;
			if (t +1 < prod[i][1].size())dp[x][1] = (dp[x][1] * prod[i][1][t+1]) % m;
			dp[x][0] = (dp[x][0] * (dp[x][1] + 1)) % m;
 			dfs2(x, i);
 			t++;
		}
	}
}

// x = (x * (p+x+1)) / (x+1);

void solve(){
	cin >> n >> m;
	for(int i = 0; i < n-1; i++){
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs();
	dp[1][1] = 0;
	dfs2();
	for(int i = 1; i <= n; i++)
	cout << dp[i][0] << endl;
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

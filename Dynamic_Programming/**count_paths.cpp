// https://atcoder.jp/contests/dp/tasks/dp_r
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

const int MAX = 52;
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

vector<vector<int>> mult1(vector<vector<int>> &fir, vector<vector<int>> &sec){
	vector<vector<int>> ans(n, vector<int> (n, 0));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			for(int k = 0; k < n; k++)
				ans[i][j] = (ans[i][j] + fir[i][k] * sec[k][j]) % mod;
	return ans;
}
vector<vector<int>> mult(vector<vector<int>> &arr, int k){
	if (k == 1)return arr;
	vector<vector<int>> half = mult(arr, k/2);
	vector<vector<int>> brr = mult1(half, half);
	if (k % 2 == 0)return brr;
	else return mult1(brr, arr);
}
void solve(){
	cin >> n >> k;
	vector<vector<int>> arr(n, vector<int> (n));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)cin >> arr[i][j];
	vector<vector<int>> ans = mult(arr, k);
	int count = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)count = ( count + ans[i][j] ) % mod;
	cout << count << endl;
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

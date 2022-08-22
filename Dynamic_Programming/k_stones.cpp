// https://atcoder.jp/contests/dp/tasks/dp_k

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
bool dp[MAX];
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
void solve(){
	cin >> n >> k;
	memset(dp, 0, sizeof(dp));
	// dp[i] -> will player 1 win for pile = k
	fo(i, n) cin >> arr[i+1];
	int curr = 0;
	for(int j = 0; j <= k; j++){
		dp[j] = false;
		if (j < arr[1])continue;
		for(int i = 1; i <= n; i++){
			if (j-arr[i] >=0 && dp[j - arr[i]] == 0)dp[j] = true;
		}
	}
	if (dp[k] == 0)
		cout << "Second" << endl;
	else cout << "First" << endl;
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

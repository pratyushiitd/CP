// https://atcoder.jp/contests/dp/tasks/dp_q
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

const int MAX = 3e5+2;
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
int arr[MAX], brr[MAX];

// dp[i][0] -> white
// dp[i][1] -> black

vector<int> bit;

void add(int k, int val){
	bit[k] = val;
	while(k < MAX)bit[k] = max(bit[k], val), k += k & (-k);
}
int get(int k){
	int val = bit[k];
	while(k > 0)
		val = max(val, bit[k]), k -= k & (-k);
	return val;
}
void solve(){
	cin >> n;
	for(int i = 0; i < n; i++)cin >> arr[i];
	for(int i = 0; i < n; i++)cin >> brr[i];
	
	bit.resize(MAX);
	int ans = 0;
	for(int i = 0; i < n; i++){
		int num = get(arr[i]-1);
		ans = max(ans, num + brr[i]);
		add(arr[i], num + brr[i]);
	}
	cout << ans << endl;
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

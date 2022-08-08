// https://cses.fi/problemset/task/1138/
#include <bits/stdc++.h>

using namespace std;
#define int long long 
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const int MAX = 2e5+2;
int n, q;
int arr[MAX];
vector<int> bit, adj[MAX], vec;
int last[MAX], start[MAX];
void dfs(int i = 1, int p = -1){
	int sub = 1;
	start[i] = vec.size();
	vec.push_back(arr[i]);
	for(auto x: adj[i]){
		if (x!=p)dfs(x, i);
	}
	last[i] = vec.size();
	vec.push_back(-arr[i]);
}
void update(int k, int val){
	while(k <= 2*n){
		bit[k]+=val; k+=k&(-k);
	}
}
int get(int k){
	int sum = 0;
	while(k > 0){
		sum+=bit[k];
		k-= k & (-k);
	}
	return sum;
}
void solve(){
	cin >> n >> q;
	vec.push_back(0);
	bit.resize(2*n+1);
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
	}
	for(int i = 0; i < n-1; i++){
		int u, v; cin >> u >> v;
		adj[u].push_back(v); adj[v].push_back(u);
	}
	dfs();
	for(int i = 1; i <= 2*n; i++){
		update(i, vec[i]);
	}
	cout << endl;
	while(q--){
		int t; cin >> t;
		if (t == 1){
			int s, x; cin >> s >> x;
			update(start[s], x - arr[s]);
			update(last[s], -x + arr[s]);
			arr[s] = x;
		}else{
			int s; cin >> s;
			cout << get(start[s]) << endl;
		}
	}
}
int32_t main(){
	
	int t = 1;
	// cin >> t;
	solve();
	return 0;
}

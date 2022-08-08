// https://cses.fi/problemset/task/1137/
#include <bits/stdc++.h>

using namespace std;
#define int long long 
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const int MAX = 2e5+2;
int n, q;
int arr[MAX];
vector<int> bit, adj[MAX], vec;
int sz[MAX], ind[MAX];
int dfs(int i = 1, int p = -1){
	int sub = 1;
	ind[i] = vec.size();
	vec.push_back(arr[i]);
	for(auto x: adj[i]){
		if (x!=p){
			sub += dfs(x, i);
		}
	}
	sz[i] = sub;
	return sz[i];
}
void update(int k, int val){
	while(k <= n){
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
	bit.resize(n+1);
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
	}
	for(int i = 0; i < n-1; i++){
		int u, v; cin >> u >> v;
		adj[u].push_back(v); adj[v].push_back(u);
	}
	dfs();
	for(int i = 1; i <= n; i++){
		update(i, vec[i]);
	}
	while(q--){
		int t; cin >> t;
		if (t == 1){
			int s, x; cin >> s >> x;
			update(ind[s], x - arr[s]);
			arr[s] = x;
		}else{
			int s; cin >> s;
			cout << get(ind[s] + sz[s]-1) - get(ind[s] - 1) << endl;
		}
	}
}
int32_t main(){
	
	int t = 1;
	// cin >> t;
	solve();
	return 0;
}

// https://www.spoj.com/problems/KQUERY/
#include <bits/stdc++.h>

#define int long long
#define fast ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
vector<int> bit;
int n, m, x;

struct segtree{
	int size;
	vector<vector<int>> vec;
	
	vector<int> operation(const vector<int> &a, const vector<int> &b){
		vector<int> ans;;
		int n = a.size(), m = b.size();
		int i = 0, j = 0;
		while(i < n || j < m){
			if ( i!=n && (j == m || a[i] <= b[j] )){
				ans.push_back(a[i++]);
			}else ans.push_back(b[j++]);
		}
		return ans;
	}
	void merge(int x){
		vec[x] = operation(vec[2*x+1], vec[2*x+2]);
	}
	void build(const vector<int> &arr, int x, int lx, int rx){
		if (rx - lx == 1){
			if (lx < arr.size())vec[x] = {arr[lx]};
			return;
		}
		int m = (lx + rx) >> 1;
		build(arr, 2*x+1, lx, m);
		build(arr, 2*x+2, m, rx);
		merge(x);
	}
	void build(const vector<int> &arr){
		build(arr, 0, 0, size);
	}
	void init(int n){
		size = 1;
		while(size < n)size*= 2;
		vec.resize(2*size);
	}	
	int get(int k, int l, int r, int x, int lx, int rx){
		if (l >= rx || r <= lx)return 0;
		if (lx >= l && rx <= r) return vec[x].size() - (upper_bound(vec[x].begin(), vec[x].end(), k) - vec[x].begin()) ;
		int m = (lx + rx) >> 1;
		return get(k, l, r, 2*x+1, lx, m) + get(k, l, r, 2*x+2, m, rx);
	}
	int get(int k, int l ,int r){
		return get(k, l, r, 0, 0, size);
	}
};
int32_t main(){
	fast;
	cin >> n;
	segtree st;
	st.init(n);
	vector<int> vec(n);
	for(int i = 1; i <= n; i++){
		cin >> vec[i-1];
	}
	st.build(vec);
	cin >> m;
	for(int i = 1; i <= m; i++){
		int a, b, k;
		cin >> a >> b >> k;
		cout << st.get(k, a-1, b) << '\n';
	}
	return 0;
}

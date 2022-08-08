// https://cses.fi/problemset/task/1143/
#include <bits/stdc++.h>

#define int long long

using namespace std;
vector<int> bit;
int n, m, x;

struct segtree{
	int size;
	vector<int> vec;
	
	int operation(int a, int b){
		return max(a, b);
	}
	void merge(int x){
		vec[x] = operation(vec[2*x+1], vec[2*x+2]);
	}
	void build(vector<int> &arr, int x, int lx, int rx){
		if (rx - lx == 1){
			if (lx < arr.size())vec[x] = arr[lx];
			return;
		}
		int m = (lx + rx) >> 1;
		build(arr, 2*x+1, lx, m);
		build(arr, 2*x+2, m, rx);
		merge(x);
	}
	void build(vector<int> &arr){
		build(arr, 0, 0, size);
	}
	void init(int n){
		size = 1;
		while(size < n)size*= 2;
		vec.assign(2*size, 0);
	}	
	void update(int i, int val, int x, int lx, int rx){
		if (rx - lx == 1){
			vec[x] -= val;
			return;
		}
		int m = (lx + rx) >> 1;
		if (i < m)update(i, val, 2*x+1, lx, m);
		else update(i, val, 2*x+2, m, rx);
		merge(x);
	}
	void update(int i, int val){
		update(i, val, 0, 0, size);
	}
	int get(int l, int r, int x, int lx, int rx){
		if (l >= rx || r <= lx)return 0;
		if (lx >= l && rx <= r)return vec[x];
		int m = (lx + rx) >> 1;
		int v1 = get(l, r, 2*x+1, lx, m);
		int v2 = get(l, r, 2*x+2, m, rx);
		return operation(v1, v2);
	}
	int get(int l ,int r){
		return get(l, r, 0, 0, size);
	}
};
int32_t main(){
	cin >> n >> m;
	bit.resize(n+1, 0);
	segtree st;
	st.init(n);
	vector<int> vec(n);
	for(int i = 1; i <= n; i++){
		cin >> vec[i-1];
	}
	st.build(vec);
	for(int i = 1; i <= m; i++){
		cin >> x;
		int lo = 1, hi = n;
		int ans = -1;
		while(lo <= hi){
			int m = lo + (hi - lo) / 2;
			int f = st.get(0, m);
			if (f >= x){
				ans = m;
				hi = m-1;
			}else{
				lo = m+1;
			}
		}
		if (ans == -1)cout << 0 << ' ';
		else {
			cout << ans << ' ';
			st.update(ans-1, x);
		}
	}
	cout << endl;
	return 0;
}

// https://cses.fi/problemset/task/1739/
#include <bits/stdc++.h>

using namespace std;
#define int long long 
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const int MAX = 2e3+2;
int n, q;
int arr[MAX][MAX];
vector<vector<int>> bit;
void update(int x, int y, int val){
	while(x <= n){
		int d = y;
		while(d <= n){
			bit[x][d] += val;
			d+= d & (-d);
		}
		x += x & (-x);
	}
}
int get(int x, int y){
	int sum = 0;
	while(x > 0){
		int d = y;
		while(d > 0){
			sum+=bit[x][d];
			d-= d & (-d);
		}
		x -= x & (-x);
	}
	return sum;
}
void solve(){
	cin >> n >> q;
	bit.resize(n+1,  vector<int> (n+1));
	memset(arr, 0, sizeof(arr));
	for(int i = 1; i <= n; i++){
		string s; cin >> s;
		for(int j = 1; j <= n; j++){
			if (s[j-1] == '*'){
				update(i, j, 1);
				arr[i][j] = 1;
			}
		}
	}
	while(q--){
		int t; cin >> t;
		if (t == 1){
			int i, j; cin >> i >> j;
			if (arr[i][j]){
				update(i, j, -1);
				arr[i][j] = 0;
			}else{
				update(i, j, 1);
				arr[i][j] = 1;
			}
		}else{
			int a, b, c, d;
			cin >> a >> b >> c >> d;
			cout << get(c, d) - get(a-1, d) - get(c, b-1) + get(a-1, b-1) << endl;
		}
	}
}
int32_t main(){
	
	int t = 1;
	// cin >> t;
	solve();
	return 0;
}

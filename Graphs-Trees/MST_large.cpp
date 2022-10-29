// https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/practice-problems/algorithm/hacker-land-a4c9de07/

#include <bits/stdc++.h>

using namespace std;
#define int long long

const int MAX = 1e5+2;
int par[MAX], rnk[MAX];

void init(int n){
	for(int i = 0; i < n; i++)par[i] = i, rnk[i] = 1;
}
int find_set(int i){
	if (par[i] == i)return i;
	return par[i] = find_set(par[i]);
}
void merge(int a, int b){
	int p1 = find_set(a), p2 = find_set(b);
	if (p1 == p2)return;
	if (rnk[p1] > rnk[p2])swap(p1, p2);
	rnk[p2] += rnk[p1];
	par[p1] = p2; 
}
void solve(){
	int n; cin >> n;
	set<pair<int, int>> st;
	int arr[n][2];
	for(int i = 0; i < n; i++){
		cin >> arr[i][0];
	}
	for(int i = 0; i < n; i++){
		cin >> arr[i][1];
	}
	for(int i = 0; i < n; i++){
		st.insert({arr[i][0], arr[i][1]});
	}
	n = st.size();
	init(n);
	int cost = 0;
	vector<pair<int, int>> arx, ary;
	int cnt = 0;
	for(auto [x, y]: st)arx.push_back({x, cnt}), ary.push_back({y, cnt++});
	sort(arx.begin(), arx.end());
	sort(ary.begin(), ary.end());
	vector<pair<int, pair<int, int>>> edges;
	for(int i = 1; i < n; i++){
		edges.push_back({abs(arx[i].first - arx[i-1].first), {arx[i].second, arx[i-1].second}});
		edges.push_back({abs(ary[i].first - ary[i-1].first), {ary[i].second, ary[i-1].second}});
	}
	sort(edges.begin(), edges.end());
	for(int i = 0; i < edges.size(); i++){
		int i1 = edges[i].second.first, i2 = edges[i].second.second;
		if (find_set(i1) == find_set(i2))continue;
		merge(i1, i2);
		cost += edges[i].first;
	}
	cout << cost << endl;
}
int32_t main(){
	int t; cin >> t;
	while(t--)solve();
	return 0;
}

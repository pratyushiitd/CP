// https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/another-substring-problem-900ce141/
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define MAX 100001
int arr[MAX];
void solve(){
	int n, k; cin >> n >> k;
	for(int i = 0; i < n; i++)cin >> arr[i];
	int max_len = INT_MAX;
	unordered_map<int, int> mp;
	int i = 0;
	for(int j = 0; j < n; j++){
		mp[arr[j]]++;
		while(mp.size() == k){
			max_len = min(max_len, j-i+1);
			if (mp[arr[i]] == 1){
				mp.erase(arr[i]);
			}else{
				mp[arr[i]]--;
			}
			i++;
		}
	}
	cout << max_len << endl;
}
int main() {
	int t; cin >> t;
	while(t--)solve();
}

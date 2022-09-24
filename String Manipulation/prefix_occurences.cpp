#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
	string s, t;
	cin >> s >> t;
	int n = s.length(),  m = t.length();
	int lps[n];
	lps[0] = 0;
	for(int i = 1; i < n; i++){
		int j = lps[i-1];
		while(j && s[j] != s[i])j = lps[j-1];
		if (s[i] == s[j])j++;
		lps[i] = j;
	}
	vector<int> counts(n+1);
	for(int i = 0; i < n; i++)counts[lps[i]]++;
	for(int i = n-1; i > 0; i--)counts[lps[i-1]] += counts[i];
	for(int i = 0; i <= n; i++)counts[i]++;
	for(int i = 1; i <= n; i++)cout << counts[i] << ' ';
}
int32_t main(){
	int t = 1;
	cin >> t;
	while(t--)solve();
	
	return 0;
}

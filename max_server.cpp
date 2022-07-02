// https://www.hackerrank.com/contests/code-spectrum/challenges/faccha-in-trouble/problem

/*
Given jobs si,ti. Find the minimum servers required to run all jobs. Overlapping jobs must run on different servers.

Basically, find maximum number of overlapping jobs at a given instant. Return val - 1.
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve(){
    int n; cin >> n;
    pair<int, int> arr[n];
    map<int, int> m;
    for(int i = 0; i < n; i++){
        cin >> arr[i].first >> arr[i].second;
        m[arr[i].first]++;
        m[arr[i].second]--;
    }
    vector<int> vec;
    for(auto p: m){
        // cout << p.first << ' ' << p.second << endl;
        vec.push_back(p.second);
    }
    int ans = 0;
    int max_ans = INT_MIN;
    for(int i = 0; i < vec.size(); i++){
        ans+=vec[i];
        max_ans = max(max_ans, ans);
        }
    cout << max_ans -1 << endl;
}
int32_t main(){
    // int t; cin >> t;
    int t = 1;
    while(t--)solve();
    return 0;
}

// 10 8 20 5 -> 5 8 10 20
// 2 1 4 -> lcm = 4
// 40 -> 1 2 4 8 

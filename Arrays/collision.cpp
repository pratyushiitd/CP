//https://www.hackerearth.com/practice/algorithms/searching/linear-search/practice-problems/algorithm/bouncing-balls-b9c19a3d/

#include <bits/stdc++.h>

using namespace std;
#define int long long

bool comp(pair<pair<int, int>, double> &p1, pair<pair<int, int>, double> &p2){
    return p1.second < p2.second;
}
void solve(){
    int n; cin >> n;
    int x[n], v[n];
    for(int i = 0; i < n; i++)cin >> x[i];
    for(int i = 0; i < n; i++)cin >> v[i];
    vector<pair<pair<int, int>, double>> vec;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if (x[i] < x[j] && v[i] > 0 && v[j] < 0){
                vec.push_back({{i, j}, (double)(x[j] - x[i]) / (double)(v[i] - v[j])});
            }
        }
    }
    sort(vec.begin(), vec.end(), comp);
    int idx[n];
    int ans[n];
    iota(idx, idx+n, 0);
    memset(ans, 0, sizeof(ans));
    for(auto x: vec){
        int i1 = x.first.first, i2 = x.first.second, t = x.second;
        ans [idx[i1]] += t;
        ans [idx[i2]] += t;
        swap(idx[i1], idx[i2]);
    }
    for(int i = 0; i < n; i++)cout << ans[i] << endl;
}
int32_t main(){
    int t; cin >> t;
    while(t--)solve();
    return 0;
}

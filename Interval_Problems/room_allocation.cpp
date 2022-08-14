// https://cses.fi/problemset/task/1164/
#include <bits/stdc++.h>

using namespace std;
#define int long long
int n, m, k, a, b, x, y;
#define f first
#define s second
vector<int> bit;

void solve(){
    cin >> n;
    vector<tuple<int, int, int>> vec;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        vec.push_back({a, 0, i});
        vec.push_back({b, 1, i});
    }
    sort(vec.begin(), vec.end());
    vector<int> free;
    int ans[n];
    int curr_ind = 0;
    for(auto [x,t,i]: vec){
        if (t == 0){
            if (free.size()){
                ans[i] = free.back();
                free.pop_back();
            }else{
                curr_ind++;
                ans[i] = curr_ind;
            }
        }
        else{
            free.push_back(ans[i]);
        }
    }
    cout << *max_element(ans, ans+n) << endl;
    for(int i = 0; i < n; i++)cout << ans[i] << ' ';
}
int32_t main(){
    solve();
    return 0;
}

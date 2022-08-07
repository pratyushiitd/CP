// https://cses.fi/problemset/task/1648/
#include <bits/stdc++.h>

#define int long long
const int MAX = 2e5+2;
int arr[MAX];
using namespace std;
int n, q, m;
int dp[MAX][25];
int lg[MAX];
vector<int> vec;

void update(int i, int val){
    while(i <= n){
        vec[i]+=val;
        i+= i & (-i);
    }
}
int get(int i){
    int sum = 0;
    while(i > 0){
        sum+=vec[i];
        i-= i & (-i);
    }
    return sum;
}
void solve(){
    cin >> n >> q;    
    vec.resize(n+1, 0);
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        update(i, arr[i]);
    }
    while(q--){
        int t; cin >> t;
        if (t == 1){
            int k, u; cin >> k >> u;
            update(k, u - arr[k]);
            arr[k] = u;
        }else{
            int a, b; cin >> a >> b;
            cout << get(b) - get(a-1) << endl;
        }
    }
}
int32_t main(){
    
    solve();
    return 0;
}

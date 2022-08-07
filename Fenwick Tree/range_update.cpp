// https://cses.fi/problemset/task/1651/

#include <bits/stdc++.h>

#define int long long
const int MAX = 2e5+2;
int arr[MAX];
using namespace std;
int n, q, m;
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
    vec.resize(n+2, 0);
    int pre[n+2];
    pre[0] = 0;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        update(i, arr[i]);
        pre[i] = pre[i-1]+arr[i];
    }
    while(q--){
        int t; cin >> t;
        if (t == 2){
            int k; cin >> k; 
            cout << get(k) - pre[k] + arr[k] << endl;
        }
        else{
            int a, b, u; cin >> a >> b >> u;
            update(a, u);
            update(b+1, -u);
        }
    }
}
int32_t main(){
    int t = 1; 
    // cin >> t;
    while(t--)solve();
    return 0;
}

// https://www.spoj.com/problems/INVCNT/
#include <bits/stdc++.h>

#define int long long
using namespace std;
vector<int> vec;
int n, m, t;
const int MAX = 1e7+2;

void update(int k, int u){
    while(k <= MAX){
        vec[k]+=u;
        k+= (k&(-k));
    }
}

int get(int k){
    int sum = 0;
    while(k>0){
        sum+=vec[k];
        k-=(k&(-k));
    }
    return sum;
}
void solve(){
    cin >> n;
    vec.clear();
    vec.resize(MAX+1, 0);
    int num = 0;
    for(int i = 1; i <= n; i++){
        int q; cin >> q;
        num += get(MAX) - get(q);
        update(q, 1);
    }
    cout << num << endl;
}
int32_t main(){
    cin >> t;
    while(t--)solve();
    return 0;
}

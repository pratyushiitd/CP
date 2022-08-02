// https://www.hackerrank.com/challenges/merging-communities/problem#:~:text=People%20connect%20with%20each%20other,communities%20which%20and%20belong%20to.
#include <bits/stdc++.h>

using namespace std;

#define int long long
int n, m, k, q;
const int MAX = 1e5+2;

int rnk[MAX];
int par[MAX];

void make_set(int n){
    for(int i = 1; i <= n; i++){
        par[i] = i; rnk[i] = 1;
    }
}

int find_set(int i){
    if (par[i] == i)return i;
    return par[i] = find_set(par[i]);
}
void merge(int a, int b){
    int p1 = find_set(a), p2 = find_set(b);
    if (p1 != p2){
        if (rnk[p1] > rnk[p2]){
            rnk[p1]+=rnk[p2];
            par[p2] = p1;
        }else{
            rnk[p2]+=rnk[p1];
            par[p1] = p2;
        }
    }
}
void solve(){
    cin >> n >> q;
    make_set(n);
    while(q--){
        char c; cin >> c;
        if (c == 'M'){
            int a, b; cin >> a >> b;
            merge(a, b);
        }else{
            int a; cin >> a;
            cout << rnk[find_set(a)] << endl;
        }
    }
}
int32_t main(){
    solve();
    return 0;
}

//https://codeforces.com/contest/1698/problem/D
#include <bits/stdc++.h>

using namespace std;

// #define int long long

void make_query(int l , int r){
    cout << "? " << l <<  ' ' << r << endl;
    cout.flush();
}
int find_recursive(int l , int r){
    if ( l == r)return l;
    int mid = (l+r)/2;
    make_query(l, mid);
    int found = 0;
    
    for(int i = 0; i < mid-l+1; i++){
        int x; cin >> x; 
        if (x>= l && x <= mid)found ++;
    }
    if (found%2)return find_recursive(l ,mid);
    else return find_recursive(mid+1, r);
}
void solve(){
    int n; cin >> n;
    int ans = find_recursive(1, n);
    cout << "! " << ans  << endl;
    cout.flush();
}
int32_t main() {
    int t; cin >> t;
    while(t--)solve();
    return 0;
}

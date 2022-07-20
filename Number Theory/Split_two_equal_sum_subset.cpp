// Split 1... n to two equal sum subsets

#include <bits/stdc++.h>

#define int long long

using namespace std;

const int MAX = 10001;
void solve(){
    int m; cin >> m;
    int n = m;
    bool valid = true;
    if ((n*n+n) % 4 != 0)valid = false;
    if (!valid){
        cout << "NO";
        return;
    }
    n%=4;
    if (n&&n<3){
        cout << "NO\n";return;
    }
    else cout << "YES\n";
    vector<int> v1,v2;
    if (n == 3){
        v1.push_back(1);
        v1.push_back(2);
        v2.push_back(3);
    }
    if (n == 4){
        v1.push_back(1);
        v1.push_back(4);
        v2.push_back(2);
        v2.push_back(3);
    }
    for(int i = n+1; i <= m; i+=4){
        v1.push_back(i);
        v1.push_back(i+3);
        v2.push_back(i+1);
        v2.push_back(i+2);
    }
    cout << v1.size() << endl;
    for(auto &x: v1)cout << x << ' ';
    cout << endl;
    cout << v2.size() << endl;
    for(auto &x: v2)cout << x << ' ';
    cout << endl;
}
int32_t main(){
    int t = 1;
    // cin >> t;
    while(t--)solve();
    return 0;
}

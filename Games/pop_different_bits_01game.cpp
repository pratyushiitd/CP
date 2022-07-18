// https://codeforces.com/contest/1373/problem/B
#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    int t; cin >> t; while(t--){
    string s; cin >> s;
    int a = 0, b = 0;
    for(char c: s){c=='0' ? a++:b++;}
        // cout << a << b << endl;
    a = min(a, b);
    if (a%2)cout << "DA";
    else cout << "NET";
        cout << endl;
    }
}

/*
LOOK FOR -> int overflow, 
            array bounds
            special cases (n=1?)
            Different approaches
*/

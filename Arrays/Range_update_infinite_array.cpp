// https://www.hackerrank.com/contests/code-spectrum/challenges/the-endgame/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

#define int int64_t
int32_t main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int p; cin >> p;
    map<int, int> m;
    while(p--){
        int l, r, x; cin >> l >> r >> x;
        m[l]+=x;
        m[r+1]-=x;
    }
    vector<pair<int, int>> vec;
    for(auto p: m){
        if (vec.size())vec.push_back({p.first, p.second+vec[vec.size()-1].second});
        else vec.push_back({p.first, p.second});
    }
    // for(auto x: vec)cout << x.first << ' ' << x.second << endl;
    int w; cin >> w;
    while(w--){
        int x; cin >> x;
        if (x < vec[0].first || x > vec[vec.size()-1].first){
            cout << 0 << endl;continue;
        }
        if (x == vec[0].first){
            cout << vec[0].second << endl;continue;
        }
        if (x == vec[vec.size()-1].first){
            cout << vec[vec.size()-1].second << endl;continue;
        }
        auto it = lower_bound(vec.begin(), vec.end(), make_pair(x, 0L));
        if (m.find(x) == m.end())it--;
        // cout << it->first << ' ' << it->second << endl;
        cout << it->second << endl;
    }
    return 0;
}

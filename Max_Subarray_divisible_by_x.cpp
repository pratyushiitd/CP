// https://www.hackerrank.com/contests/code-spectrum/challenges/post-gabba-stress-disorder/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;


int32_t main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int x, n; cin >> x >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        arr[i]%=x;
    }
    map<int, int> m;
    int ans = 0;
    for(int i = 0; i <n; i++){
        if (i) arr[i]+=arr[i-1];
        arr[i]%=x;
        if (arr[i] == 0){
            ans = max(ans, i+1);
            continue;
        }
        if (m.find(arr[i]) != m.end()){
            ans = max(ans, i - m[arr[i]]);
        }else m[arr[i]] = i;
    }
    cout << ans << endl;
    return 0;
}
// 1 1 1 1
/*
m[1] = 0;
m[2] = 1;

*/

// https://codeforces.com/edu/course/2/lesson/9/2/practice/contest/307093/problem/B
#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    int n, s; cin >> n >> s;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++)cin >> a[i];
    a[0] = 0;
    int ans = LLONG_MAX;
    int l = 1, r = 1, sum = a[1];
    while(l <= n && r <= n){
        if (sum < s){
            r++;if (r == n+1)break;sum+=a[r];
        }else{
            ans = min(ans, r-l+1);
            sum-=a[l];
            l++;
        }
    }
    if (ans == LLONG_MAX)ans = -1;
    cout << ans << endl;
}

/*
LOOK FOR -> int overflow, 
            array bounds
            special cases (n=1?)
            Different approaches
*/

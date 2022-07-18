// https://www.hackerrank.com/challenges/queries-with-fixed-length/problem

#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    int n; cin >> n;
    queue<int> q1;
    stack<int> q2;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        q1.push(x);
    }
    int req = 1;
    bool valid = true;
    while(!q1.empty() || !q2.empty() || req <= n){
        while(!q1.empty() && q1.front()==req){
            q1.pop(); req++;
        }
        while(!q2.empty() && q2.top()==req){
            q2.pop(); req++;
        }
        if (q1.empty() && !q2.empty()){valid = false;break;}
        if (!q1.empty() && q1.front()!=req){
            q2.push(q1.front());
            q1.pop();
        }
    }
    if (valid && req == n+1){
        cout << "yes";
    }else {
        cout << "no";
    }
}

/*
LOOK FOR -> int overflow, 
            array bounds
            special cases (n=1?)
            Different approaches
*/

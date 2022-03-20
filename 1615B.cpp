//https://codeforces.com/contest/1615/problem/B
#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < b; i++)
#define f first
#define s second
int arr[200001][20];
int main(){
    int t;cin >> t;
    memset(arr, 0, sizeof(arr));
    for(int b = 1; b < 200001; b++){
        rep(k, 0, 20)arr[b][k] = arr[b-1][k];
        int c = 0;
        int num = b;
        while(num > 0){
            arr[b][c++] += num&1;num>>=1;
        }
    }
    while(t--){
        int l, r; cin >> l >> r;
        int count = INT_MAX;
        // for(int i = 0; i < 32; i++)cout << arr[i] << ' ';
        for(int i = 0; i < 20; i++)count = min(count, r-l+1-(arr[r][i]-arr[l-1][i]));
        cout << count << '\n';
        }
    
    }



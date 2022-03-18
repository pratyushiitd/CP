//https://codeforces.com/contest/1623/problem/C
#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < b; i++)
#define f first
#define s second
int arr2[2000001];
int bin_search(int arr[], int start, int end, int n){
    rep(i, 0, n)arr2[i] = arr[i];
    int mid = start + (end - start) / 2;
    // cout << mid << endl;
    if (start == end)return start;
    for(int i = n-1; i >= 2; i--){
        if (arr2[i] < mid)return bin_search(arr, start, mid, n);
        int d = arr2[i] - mid;
        d = min(d, arr[i]);
        d /= 3;
        arr2[i-1]+=d;
        arr2[i-2]+=2*d;
        arr2[i]-=3*d;
        if (arr2[i] < mid)return bin_search(arr, start, mid, n);
    }
    if (arr2[0] < mid || arr2[1] < mid)
        return bin_search(arr, start, mid, n);
    return bin_search(arr, mid+1,end, n);
}
int main(){
int t;cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n];
        rep(i, 0, n)cin >> arr[i];
        cout << bin_search(arr, 0, 1000000001, n)-1 << '\n';
    }
}



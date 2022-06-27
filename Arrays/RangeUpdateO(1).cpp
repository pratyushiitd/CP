// Q queries of the form
// l, r, x -> add x to add elements from l to r
// Print the final array

#include <bits/stdc++.h>

using namespace std;

#define int long long
int32_t main() {
    int n, q; cin >> n >> q;
    int arr[n+1];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    arr[n] = 0;
    for(int i = 0; i < q; i++){
        int l, r, x; cin >> l >> r >> x;
        arr[l]+=x;
        arr[r+1] -=x;
    }
    for(int i = 1; i <= n; i++){
        arr[i]+=arr[i-1];
    }
    for(int i = 0; i < n; i++)cout << arr[i]<< ' ';
    cout << endl;
}

// https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc7/00000000001d3f5b
#include <bits/stdc++.h>

using namespace std;

int arr[100001], n, k;
int solve(){
    cin >> n >> k;
    for(int i = 0; i < n; i++)cin >> arr[i];
    int lo = 1, hi = arr[n-1] - arr[0];
    int ans =1;
    while(lo <= hi){
        int m = lo + (hi - lo) / 2;
        int k_req = 0;
        for(int i = 1; i < n; i++){
            int d = arr[i] - arr[i-1];
            k_req += d/m - (d%m==0);
        }
        if (k >= k_req){
            ans = m;
            hi = m-1;
        }else lo = m+1;
    }
    return ans;
}
 // 2 8 3
int32_t main(){
    
    int t;cin >> t;
    for(int i = 0; i < t; i++){
        printf("Case #%d: %d\n", i+1, solve());
    }
    return 0;
}

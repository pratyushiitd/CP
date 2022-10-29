//https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/pirates-and-swords-89e51e63/

#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve(){
   int n, m, d;
   cin >> n >> m >> d;
   int arr[n], brr[m];
   for(int i = 0; i < n; i++)cin >> arr[i];
   for(int j = 0; j < m; j++)cin >> brr[j];
   int lo = 0, hi = min(m, n);
   sort(brr, brr+m);
   sort(arr, arr+n);
   pair<int, int> ans;
   while(lo <= hi){
      int mid = lo + (hi - lo) / 2;
      int d_req = 0;
      int req = 0;
      for(int i = 0; i < mid; i++){
         d_req += max(0ll, brr[i] - arr[n-mid+i]);
         req += brr[i];
      }
      if (d_req <= d){
         ans = {mid, max(0ll, req - d)};
         lo = mid+1;
      }
      else hi = mid-1;
   }
   cout << ans.first << ' ' << ans.second << endl;
}
int32_t main(){
   solve();
}

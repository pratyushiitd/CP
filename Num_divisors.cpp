// https://www.hackerearth.com/problem/algorithm/number-of-divisors-5/

#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAX = 1e6+1;
int spf_arr[MAX+1];

void seive_prime(int n, int arr[]){
    arr[1] = 0;
    arr[2] = 2;
    for(int i = 2; i*i <= n; i++){
        if (arr[i]==i){
            for(int j = i*i; j <=n; j+=i){
                if (arr[j] == j)arr[j] = i;
            }
        }
    }
}
int32_t main(){
    for(int i = 1; i <= MAX; i++)spf_arr[i] = i;
    seive_prime(MAX, spf_arr);
    int q; cin >> q; 
    while(q--){
        int n; cin >> n;
        int ans = 1;
        while(n>1 && n < MAX){
            int cnt = 0;
            int spf = spf_arr[n];
            while(n%spf == 0){
                n/=spf;cnt++;
            }
            ans*=cnt+1;
        }
        if(n > 1){ // If input is larger than 10^6, spf_array would be out of limit, so use normal procedure.
            ans = 0;
            for(int i = 1; i*i <= n; i++){
                if (n%i == 0){
                    ans += 2-(i == n/i);
                }
            }
        }
        cout << ans << endl;;
    }
    return 0;
}

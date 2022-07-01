#include <bits/stdc++.h>

using namespace std;

#define int long long

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
    int n = 100;
    int spf_arr[n+1];
    for(int i = 1; i <= n; i++)spf_arr[i] = i;
    seive_prime(n, spf_arr);
    for(int i = 2; i <= n; i++){
        cout << i << ' ' << spf_arr[i] << endl;
    }
    return 0;
}

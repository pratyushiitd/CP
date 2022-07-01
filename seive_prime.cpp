#include <bits/stdc++.h>

using namespace std;

#define int long long

void seive_prime(int n, bool arr[]){
    arr[1] = 0;
    arr[2] = 1;
    for(int i = 2; i*i <= n; i++){
        if (arr[i])
        for(int j = i*i; j <=n; j+=i){
            arr[j] = false;
        }
    }
}
int32_t main(){
    int n = 100;
    bool arr[n+1];
    memset(arr, 1, sizeof(arr));
    seive_prime(n, arr);
    for(int i = 1; i <= n; i++){
        if (arr[i])cout << i << endl;
    }
    return 0;
}

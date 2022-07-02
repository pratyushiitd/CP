#include <bits/stdc++.h>

using namespace std;

#define int long long

// int32_t main(){
//     int t; cin >> t;
//     for(int i = 0; i < t; i++){
//         printf("Case #%d: %s\n", i+1,solve().c_str());
//     }
//     return 0;
// }

const int MAX = 1000001;
int32_t main(){
    
    // SUM OF PRIME DIVISORS
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)cin >> arr[i];
    bool is_prime[MAX+1];
    is_prime[0] = is_prime[1] = 0;
    for(int i = 2; i <= MAX; i++)is_prime[i] = 1;
    for(int i = 2; i*i <= MAX; i++){
        if (is_prime[i]){
            for(int j = i*i; j <= MAX; j+=i)is_prime[j] = 0;
        }
    }
    int sum_of_primes[MAX+1];
    memset(sum_of_primes, 0, sizeof(sum_of_primes));
    sum_of_primes[2] = 2;
    for(int i = 2; i*i <= MAX; i++){
        if (is_prime[i]){
            for(int j = i; j <= MAX; j+=i)sum_of_primes[j] += i;
        }
    }
    for(int i = 0; i < n; i++){
        cout << arr[i] << ' ' << sum_of_primes[arr[i]] << endl;
    }
}

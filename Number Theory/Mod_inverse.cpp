
#include <bits/stdc++.h>

using namespace std;

int binexp(int a, int x, int m){
  if (x <= 1)return x==0? 1: a%m;
  if (x%2){
    int y = binexp(a, x/2, m) % m;
    y*=y%m;
    y*=a%m;
    return y%m;
    }
  else {
    int y = binexp(a, x/2, m) % m;
    y*=y%m;
    return y%m;
  }
  
}
int main() {
    int a, m; 
    // find (a^(-1))%m = (a^(m-2))%m
  a = 5;
    m = 3;
    cout << binexp(a, m-2,m);
    return 0;
}

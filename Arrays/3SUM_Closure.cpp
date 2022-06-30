// https://codeforces.com/contest/1698/problem/C
#include <bits/stdc++.h>

using namespace std;

// #define int long long

void solve(){
    int n; cin >> n;
    int arr[n];
    int p = 0,nw = 0,z = 0;
    for(int i = 0; i < n ; i++){
        cin >> arr[i];
        if (arr[i] > 0)p++;
        if (arr[i] < 0)nw++;
        if (arr[i]==0)z++;
    }
    if (p>2 || nw >2 || ((p==2 || nw == 2) && z > 0)){
        cout << "NO" << endl;return;
    }
    sort(arr, arr+n);
    vector<int> vec;
    if (n < 5){
        for(int i = 0; i < n; i++){
            vec.push_back(arr[i]);
        }
    }
    else{
        vec.push_back(arr[0]);
        vec.push_back(arr[n-1]);
        vec.push_back(0);
         vec.push_back(0);
    }
    // cout << vec.size()<<endl;
    set<int> mp;
    for(int i = 0; i < vec.size();i++)mp.insert(vec[i]);
    for(int i = 0; i < vec.size(); i++){
        for(int j = i+1; j < vec.size(); j++){
            for(int z = j+1; z < vec.size(); z++){
                bool found = false;
                for(int q = 0; q < vec.size(); q++)
                    if (vec[q] == vec[i]+ vec[j]+vec[z])found = true;
                if (!found){
                    cout << "NO"<<endl;return;
                }
            }
        }
    }
    cout << "YES"<<endl;return;
}
int32_t main() {
    int t; cin >> t;
    while(t--)solve();
    return 0;
}

// https://codeforces.com/edu/course/2/lesson/2/1

#include <bits/stdc++.h>

using namespace std;

#define int int64_t

void radix_sort(vector<pair<pair<int, int>, int>> &vec){
    int n = vec.size();
    vector<int> cnt(n, 0);
    vector<pair<pair<int, int>, int>> ans(n);
    for(auto x: vec)cnt[x.first.second]++;
    vector<int> pos(n);
    pos[0] = 0;
    for(int i = 1; i < n; i++){
        pos[i] = pos[i-1]+cnt[i-1];
    }
    for(int i = 0; i < n; i++){
        ans[pos[vec[i].first.second]++] = vec[i];
    }
    vec = ans;
    vector<int> cnt_new(n, 0);
    vector<pair<pair<int, int>, int>> ans_new(n);
    for(auto x: vec)cnt_new[x.first.first]++;
    vector<int> pos_new(n);
    pos_new[0] = 0;
    for(int i = 1; i < n; i++){
        pos_new[i] = pos_new[i-1]+cnt_new[i-1];
    }
    for(int i = 0; i < n; i++){
        ans_new[pos_new[vec[i].first.first]++] = vec[i];
    }
    vec = ans_new;
    
}
int32_t main(){
    
    string s; cin >> s;
    s+='$';
    int n = s.size();
    vector<int> p(n), c(n); // c-> equivalent classes, p -> position of the string
    // Eg. ababba$
    {
        vector<pair<char, int>> a(n);
        for(int i = 0; i < n; i++)a[i] = {s[i], i};
        sort(a.begin(), a.end());
        for(int i = 0; i < n; i++)p[i] = a[i].second;
        c[p[0]] = 0;
        for(int i = 1; i < n; i++){
            if (a[i].first == a[i-1].first)c[p[i]] = c[p[i-1]];
            else c[p[i]] = c[p[i-1]]+1;
        }
    }
    int k = 0;
    while((1<<k) < n){
        vector<pair<pair<int, int>, int>> a(n);
        for(int i = 0; i < n; i++){
            a[i] = {{c[i], c[(i+(1<<k))%n]}, i};
        }
        // sort(a.begin(), a.end());
        radix_sort(a);
        for(int i = 0; i < n; i++)p[i] = a[i].second;
        c[p[0]] = 0;
        for(int i = 1; i < n; i++){
            if (a[i].first == a[i-1].first)c[p[i]] = c[p[i-1]];
            else c[p[i]] = c[p[i-1]]+1;
        }
        k++;
    }
    for(int i = 0; i < n; i++){
        // cout << p[i] << ' '<< s.substr(p[i])<< endl;
        cout << p[i] << ' ';
    }
    cout << endl;
    return 0;
}

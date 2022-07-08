https://codeforces.com/edu/course/2/lesson/2/3/practice/contest/269118/problem/B

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

void count_sort(vector<int> &p, vector<int> &c){
    int n = c.size();
    vector<int> cnt(n, 0);
    vector<int> ans(n);
    for(auto x: c)cnt[x]++;
    vector<int> pos(n);
    pos[0] = 0;
    for(int i = 1; i < n; i++){
        pos[i] = pos[i-1]+cnt[i-1];
    }
    for(int i : p){
        ans[pos[c[i]]++] = i;
    }
    p = ans;
}
vector<int> solve(string &s){
    
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
        for(int x = 0; x < p.size(); x++)p[x] = (p[x]-(1<<k)+n)%n;
        count_sort(p, c);
        
        vector<int> c_new(n);
        c_new[p[0]] = 0;
        for(int i = 1; i < n; i++){
            if (make_pair(c[p[i-1]], c[(p[i-1]+(1<<k))%n]) ==
                make_pair(c[p[i]], c[(p[i]+(1<<k))%n])) 
                c_new[p[i]] = c_new[p[i-1]];
            else c_new[p[i]] = c_new[p[i-1]]+1;
        }
        c = c_new;
        k++;
    }
    return p;
}
int32_t main(){
    string s; cin >> s;
    vector<int> suff_arr = solve(s);
    // cout << suff_arr[1] << suff_arr.size()<< endl;
    int n; cin >> n;
    while(n--){
        string k; cin >> k;
        int start = -1, end = -2;
        {
            int lo = 0, hi = s.size()-1;
            while(lo <= hi){
                int mid = lo + (hi - lo)/2;
                if (s.substr(suff_arr[mid], k.length()) == k){
                    start = mid;
                    hi = mid-1;
                }
                else if (s.substr(suff_arr[mid], k.length()) < k)lo = mid+1;
                else hi = mid-1;
            }
        }
        {
            int lo = 0, hi = s.size()-1;
            while(lo <= hi){
                int mid = lo + (hi - lo)/2;
                if (s.substr(suff_arr[mid], k.length()) == k){
                    end = mid;
                    lo = mid+1;
                }
                else if (s.substr(suff_arr[mid], k.length()) < k)lo = mid+1;
                else hi = mid-1;
            }
        }
       cout << end - start +1<< endl;
    }
}

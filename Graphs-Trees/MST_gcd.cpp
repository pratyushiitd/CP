// https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/practice-problems/algorithm/complete-journey-bf38d697/
#include <bits/stdc++.h>

using namespace std;
#define int long long

const int MAX = 1e5+2;

int par[MAX], rnk[MAX];

void init(int n){
    for(int i = 0; i < n; i++)par[i] = i, rnk[i] = 1;
}

int find_set(int i){
    if (par[i] == i)return i;
    return par[i] = find_set(par[i]);
}
void merge(int a, int b){
    int p1 = find_set(a), p2 = find_set(b);
    if (p1 == p2)return;
    if (rnk[p2] > rnk[p1])swap(p1, p2);
    rnk[p1] += rnk[p2];
    par[p2] = p1;
}
int32_t main(){
	int n; cin >> n;
    init(n);
    map<int, vector<int>> vec;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        vec[x].push_back(i);
    }
    int ans = 0;
    int cost = 0;
    for(int i = MAX; i >= 1; i--){
        int r = -1;
        for(int j = i; j < MAX; j+= i){
            for(auto x: vec[j]){
                if (r == -1)r = x;
                else{
                    if (find_set(r) == find_set(x))continue;
                    merge(r, x);
                    cost += i;
                }
            }
        }
    }
    cout << cost << endl;
}

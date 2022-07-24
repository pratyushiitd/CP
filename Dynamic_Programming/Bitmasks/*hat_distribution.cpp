// https://leetcode.com/problems/number-of-ways-to-wear-different-hats-to-each-other/
class Solution {
public:
    const static int MAX = 12, HAT = 41 ; int n;
    vector<set<int>> vec;
    int mod = 1e9+7;
    int dp[(1LL << MAX)][HAT];
    int get(int mask, int hat){
        if (mask == (1 << n)-1)return 1;
        if (hat == HAT)return 0;
        int k = __builtin_popcount(mask);
        int ans = 0;
        if (dp[mask][hat]!=-1)return dp[mask][hat];
        for(int i = 0; i < n; i++){
            for(int ht = hat; ht < HAT; ht++)
            if ( (mask & (1 << i)) == 0 && vec[i].find(ht)!=vec[i].end()){
                ans = (ans + get(mask ^ (1 << i), ht+1) % mod) % mod;
            }
        }
        return dp[mask][hat] = ans % mod;
    }
    int numberWays(vector<vector<int>>& hats) {
        n = hats.size();
        vec.resize(n);
        for(int i = 0; i < n; i++){
            for(auto x: hats[i])vec[i].insert(x);
        }
        memset(dp, -1, sizeof(dp));
        return get(0, 1);
    }
};

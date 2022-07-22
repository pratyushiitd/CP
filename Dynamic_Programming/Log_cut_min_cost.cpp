// https://leetcode.com/problems/minimum-cost-to-cut-a-stick/
class Solution {
public:
    const static int MAX = 105;
     int dp[MAX][MAX];
    int get(int l, int r, vector<int> &vec){
        // inclusive
        int len = vec[r] - vec[l];
        if (l == r-1)return 0;
        if (dp[l][r]!=-1)return dp[l][r];
        int ans = INT_MAX;
        for(int k = l+1; k < r; k++){
            int v1 = get(l, k, vec);
            int v2 = get(k, r, vec);
            ans = min(ans, v1+v2);
        }
        return dp[l][r] = ans+len;
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        vector<int> vec;
        memset(dp, -1, sizeof(dp));
        vec.resize(cuts.size()+2);
        int m = cuts.size();
        vec[0] = 0;
        for(int i = 0; i < m; i++)vec[i+1] = cuts[i];
        vec[m+1] = n;
        return get(0, m+1, vec);
    }
};

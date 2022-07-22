// https://leetcode.com/problems/number-of-ways-to-divide-a-long-corridor/
#define ll long long
class Solution {
public:
    int mod = 1e9+7;
    int dp[100002];
    int get(int i, string &s){
        int n = s.length();
        if (dp[i]!=-1)return dp[i];
        int num_seat = 0;
        int j = i;
        while(j < n && num_seat < 2)num_seat+=(s[j++]=='S');
        if (num_seat <= 1)return dp[i] = 0;
        int val = 0;
        int cnt = 0;
        for(int k = j; k < n; k++){
            cnt++;
            if (s[k] == 'S'){
                val = (val+((ll)cnt%mod)*((ll)get(k, s)%mod))%mod;
                break;
            }
        }
        return dp[i] = max((int)1, val);
    }
    int numberOfWays(string &corridor) {
        memset(dp,-1, sizeof(dp));
        int tot = 0;
        for(char c: corridor)tot+=(c == 'S');
        if (tot %2)return 0;
        return get(0, corridor);
    }
};

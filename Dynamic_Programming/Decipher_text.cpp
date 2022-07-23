// https://leetcode.com/problems/decode-ways-ii/
#define ll long long
class Solution {
public:
    ll mod = 1e9+7;
    ll dp[100001];
    ll get(int i, string &s){
        int n = s.length();
        if (i >= n)return 1;
        if (s[i]=='0')return 0;
        if (dp[i]!=-1)return dp[i];
        if (s[i] == '*'){
            if (i+1<n && s[i+1]=='*')return dp[i] = (15*(ll)get(i+2, s)%mod)%mod
                + (9*(ll)get(i+1, s)%mod)%mod;
            int val = dp[i] = (9*(ll)get(i+1, s)%mod)%mod;
            if (i+1<n && s[i+1]-'0'<= 6)
            return dp[i] = (2*(ll)get(i+2, s)%mod)%mod+val;
            if (i+1<n && s[i+1]-'0'>6)
                return dp[i] = ((ll)get(i+2, s)%mod)%mod+val;
                return dp[i] = val;
        }else{
            int dig = s[i]-'0';
            int curr = dig;
            if (i+1<n)curr = (s[i]-'0')*10+(s[i+1]-'0');
            int val = 0;
            if (curr >= 10 && curr <= 26 && s[i+1]!='*'){
                val+= ((ll)get(i+2, s)%mod)%mod;
            }else if (i+1<s.length() && s[i+1]=='*'){
                if (s[i]-'0'==1)
                    val+=((9)*(ll)get(i+2, s)%mod)%mod;
                else if (s[i]-'0'==2){
                    val+=((6)*(ll)get(i+2, s)%mod)%mod;
                }
            }
            val+=((ll)get(i+1, s)%mod)%mod;
            return dp[i] = val;
        }
    }
    int numDecodings(string s) {
        memset(dp, -1, sizeof(dp));
        return get(0, s)%mod;
    }
};

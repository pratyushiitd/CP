// https://leetcode.com/problems/longest-string-chain/submissions/

#include <bits/stdc++.h>

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        vector<vector<string>> vec(20);
        for(string word: words){
            int n = word.length();
            vec[n].push_back(word);
        }
        map<string, int> dp;
        for(auto arr: vec){
            for(string s: arr){
                for(int i = 0; i < (int)s.length(); i++){
                    string r = s.substr(0, i)+s.substr(i+1);
                    dp[s] = max(dp[s], dp[r]+1);
                }
            }
        }
        int ans = 1;
        for(auto x: dp)ans = max(ans, x.second);
        return ans;
    }
};

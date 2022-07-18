// https://leetcode.com/problems/3sum/submissions/
class Solution {
public:

    vector<vector<int>> threeSum(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        set<vector<int>> ans;
        int n = arr.size();
        for(int i = 0; i < (int)arr.size(); i++){
            if (i && arr[i]==arr[i-1])continue;
            int l = i+1, r = n-1;
            int req = -arr[i];
            while(l < r){
                int sum = arr[l]+arr[r];
                if (sum == req){
                    ans.insert({arr[i], arr[l], arr[r]});
                    l++;r--;
                }
                else if (sum < req)l++;
                else r--;
            }
        }
        vector<vector<int>> vec(ans.begin(), ans.end());
        return vec;
    }
}; // -4, -1, -1, 0, 1, 2

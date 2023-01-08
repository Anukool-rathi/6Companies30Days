//Problem Link - https://leetcode.com/problems/largest-divisible-subset/

//Solution - 

/*
n - size of array
Time complexity - O(n^2)
Space complexity - O(n)
*/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> prev_idxs(n);
        for(int i = 0; i < n; i++){
            prev_idxs[i] = i;
        }
        int max_idx = 0;
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] % nums[j] == 0){
                    if(dp[j] + 1 > dp[i]){
                        dp[i] = dp[j] + 1;
                        prev_idxs[i] = j;
                    }
                }
            }
            if(dp[max_idx] < dp[i]){
                max_idx = i;
            }
        }
        vector<int> ans;
        while(prev_idxs[max_idx] != max_idx){
            ans.push_back(nums[max_idx]);
            max_idx = prev_idxs[max_idx];
        }
        ans.push_back(nums[max_idx]);
        return ans;
    }
};

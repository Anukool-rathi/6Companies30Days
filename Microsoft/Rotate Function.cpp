//Problem Link - https://leetcode.com/problems/rotate-function/

//Solution - 


class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int possible_ans = 0;
        int ans = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            possible_ans += i * nums[i];
        }
        ans = possible_ans;
        for(int i = 1; i < n; i++){
            possible_ans = possible_ans + sum - (n * nums[n - i]);
            ans = max(ans, possible_ans);
        }
        return ans;
    }
};

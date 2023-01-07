//Problem Link - https://leetcode.com/problems/shortest-unsorted-continuous-subarray/

//Solution 1 ( using stack ) -

/*
n = length of array
Time complexity - O(n)
Space Complexity - O(n)
*/

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int start = INT_MAX;
        int end = INT_MIN;
        stack<int> mono_stk;
        for(int i = 0; i < n; i++){
            while(!mono_stk.empty() && nums[i] < nums[mono_stk.top()]){
                int top = mono_stk.top();
                mono_stk.pop();
                start = min(start, top);
            }
            mono_stk.push(i);
        }
        mono_stk = stack<int>();
        for(int i = n - 1; i >= 0; i--){
            while(!mono_stk.empty() && nums[i] > nums[mono_stk.top()]){
                int top = mono_stk.top();
                mono_stk.pop();
                end = max(end, top);
            }
            mono_stk.push(i);
        }
        if(start > end){
            return 0;
        }
        return end - start + 1;
    }
};

//Solution 2 ( using two pointers ) - 

/*
n = length of array
Time complexity - O(n)
Space complexity - O(1)
*/

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int max_ele = INT_MIN;
        int min_ele = INT_MAX;
        int start = INT_MAX;
        int end = INT_MIN;
        for(int i = 0; i < n; i++){
            max_ele = max(max_ele, nums[i]);
            min_ele = min(min_ele, nums[n - 1 - i]);
            if(nums[i] < max_ele){
                end = i;
            }
            if(nums[n - 1 - i] > min_ele){
                start = n - 1 - i;
            }
        }
        if(start > end){
            return 0;
        }
        return end - start + 1;
    }
};

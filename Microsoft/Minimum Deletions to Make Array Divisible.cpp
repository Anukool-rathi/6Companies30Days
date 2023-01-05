//Problem Link - https://leetcode.com/problems/minimum-deletions-to-make-array-divisible/

//Solution - 


class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int n = numsDivide.size();
        int m = nums.size();
        int gcd = numsDivide[0];
        int num;
        int count = 0;
        for(int i = 1; i < n; i++){
            gcd = __gcd(numsDivide[i], gcd);
        }
        sort(nums.begin(), nums.end());
        for(int i = 0; i < m; i++){
            num = nums[i];
            if(num > gcd){
                return -1;
            }
            if(gcd % num == 0){
                return count;
            }
            count++;
        }
        return -1;
    }
};

//Problem Link - https://leetcode.com/problems/increasing-triplet-subsequence/

//Solution - 
/*
n - size of array
Time complexity - O(n)
Space complexity - O(1)
*/

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int ele1 = INT_MAX;
        int ele2 = INT_MAX;
        for(int& num : nums){
            if(num <= ele1){
                ele1 = num;
            }
            else if(num <= ele2){
                ele2 = num;
            }
            else{
                return true;
            }
        }
        return false;
    }
};

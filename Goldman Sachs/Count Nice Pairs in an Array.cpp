//Problem Link - https://leetcode.com/problems/count-nice-pairs-in-an-array/

//Solution - 

/*
n - size of array
Time complexity - O(n)
Space complexity - O(n)
*/

class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(nums.begin(), nums.end());
        unordered_map<int, long> freqs;
        long ans = 0;
        int mod = 1e9 + 7;
        for(int i = 0; i < n; i++){
            int rev = getRev(nums[i]);
            arr[i] -= rev;
        }
        for(int i = 0; i < n; i++){
            if(freqs.count(arr[i])){
                ans += freqs[arr[i]];
            }
            freqs[arr[i]]++;
        }
        int res = ans % mod;
        return res;
    }
    
    int getRev(int num){
        int res = 0;
        int temp;
        while(num){
            temp = num % 10;
            num /= 10;
            res *= 10;
            res += temp;
        }
        return res;
    }
};

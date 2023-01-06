//Problem Link - https://leetcode.com/problems/split-array-into-consecutive-subsequences/

//Solution 1 (using unordered_map) - 

/*  
n = length of array
Time complexity = O(n)
Space complexity = O(n)
*/


class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> freq;
        unordered_map<int, int> sequences;
        for(const int& num : nums)
            freq[num]++;
        for(const int& num : nums){
            if(freq[num] == 0)
                continue;
            else if(sequences.count(num - 1) && sequences[num - 1] != 0){
                sequences[num - 1]--;
                sequences[num]++;
                freq[num]--;
            }
            else{
                if((!freq.count(num + 1) || !freq.count(num + 2)) && (freq[num + 1] == 0 || freq[num + 2] == 0))
                    return false;
                freq[num + 1]--;
                freq[num + 2]--;
                sequences[num + 2]++;
            }
        }
        return true;
    }
};


//Solution 2 (using constant space) -

/*
n = length of array
Time complexity = O(n)
Space complexity = O(1)
*/

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int n = nums.size();
        int cur_num;
        int prev_num = nums[0] - 1;
        int cur_len1;
        int cur_len2;
        int cur_len3;
        int prev_len1 = 0;
        int prev_len2 = 0;
        int prev_len3 = 0;
        for(int i = 0; i < n;){
            int cur_num_count = 0;
            cur_num = nums[i];
            while(i < n && nums[i] == cur_num){
                cur_num_count++;
                i++;
            }
            if(cur_num != prev_num + 1){
                if(prev_len1 || prev_len2){
                    return false;
                }
                cur_len1 = cur_num_count;
                cur_len2 = 0;
                cur_len3 = 0;
            }
            else{
                if(cur_num_count < prev_len1 + prev_len2){
                    return false;
                }
                cur_len2 = prev_len1;
                cur_len3 = prev_len2 + min(prev_len3, cur_num_count - prev_len1 - prev_len2);
                cur_len1 = max(0, cur_num_count - cur_len2 - cur_len3);
            }
            prev_len1 = cur_len1;
            prev_len2 = cur_len2;
            prev_len3 = cur_len3;
            prev_num = cur_num;
        }
        if(prev_len1 || prev_len2){
            return false;
        }
        return true;
    }
};

//Problem Link - https://leetcode.com/problems/minimum-consecutive-cards-to-pick-up/

//Solution - 

/*
n = length of array
Time complexity = O(n)
Space complexity = O(n)
*/

class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int ans = INT_MAX;
        int n = cards.size();
        unordered_map<int, int> val_to_idx;
        for(int i = 0; i < n; i++){
            if(val_to_idx.count(cards[i])){
                ans = min(ans, i - val_to_idx[cards[i]] + 1);
            }
            val_to_idx[cards[i]] = i;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};

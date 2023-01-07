//Problem Link - https://leetcode.com/problems/number-of-people-aware-of-a-secret/

//Solution - 

/*
n - number of days
Time complexity - O(n)
Space complexity - O(n)
*/

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> dp(n, 0);
        dp[0] = 1;
        int sharing = 0;
        int ans = 0;
        int mod = 1e9 + 7;
        for(int i = 1; i < n; i++){
            if(i >= delay)
                sharing = ((sharing % mod) + (dp[i - delay] % mod)) % mod;
            if(i >= forget)
                sharing = ((sharing % mod) - (dp[i - forget] % mod) + mod) % mod;
            dp[i] = sharing;
        }
        for(int i = n - forget; i < n; i++)
            ans = ((ans % mod) + (dp[i] % mod)) % mod;
        return ans;
    }
};

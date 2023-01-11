//Problem Link - https://leetcode.com/problems/maximum-good-people-based-on-statements/

//Solution - 

/*
n - number of people
Time complexity - O(n^2 * 2^n)
Space complexity - O(n)
*/

class Solution {
public:
    int maximumGood(vector<vector<int>>& statements) {
        int n = statements.size();
        vector<int> good_arr(n, 0);
        int count = 0;
        int ans = dfs(statements, good_arr, count, 0, n);
        return ans;
    }
    
    int dfs(vector<vector<int>>& statements, vector<int>& good_arr, int& count, int idx, int& n){
        if(idx == n){
            if(isValid(statements, good_arr, n)){
                return count;
            }
            return 0;
        }
        int ans;
        int bad = dfs(statements, good_arr, count, idx + 1, n);
        good_arr[idx] = 1;
        count++;
        int good = dfs(statements, good_arr, count, idx + 1, n);
        good_arr[idx] = 0;
        count--;
        ans = max(bad, good);
        return ans;
    }
    
    bool isValid(vector<vector<int>>& statements, vector<int>& good_arr, int& n){
        for(int i = 0; i < n; i++){
            if(good_arr[i] == 1){
                for(int j = 0; j < n; j++){
                    if(statements[i][j] != 2 && statements[i][j] != good_arr[j]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

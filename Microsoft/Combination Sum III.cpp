//Problem Link - https://leetcode.com/problems/combination-sum-iii/

//Solution - 


class Solution {
public:
    vector<vector<int>> ans;
    vector<int> possible_ans;
    vector<vector<int>> combinationSum3(int k, int n) {
        possible_ans.resize(k, -1);
        dfs(k, n, 1, 0, 0);
        return ans;
    }
    
    void dfs(int size, int target, int num, int pointer, int sum){
        if(sum == target){
            for(int i = 0; i < size; i++){
                if(possible_ans[i] == -1)
                    return;
            }
            ans.emplace_back(possible_ans);
            return;
        }
        if(pointer >= size)
            return;
        for(int i = num; i < 10; i++){
            if(sum + i <= target){
                possible_ans[pointer] = i;
                dfs(size, target, i + 1, pointer + 1, sum + i);
                possible_ans[pointer] = -1;
            }
        }
    }
};

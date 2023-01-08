//Problem Link - https://leetcode.com/problems/all-elements-in-two-binary-search-trees/

//Solution - 

/*
n - number of nodes in tree1
m - number of nodes in tree2
Time complexity - O(n + m)
Space complexity - O(n + m)
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> list1;
        vector<int> list2;
        vector<int> ans;
        dfs(root1, list1);
        dfs(root2, list2);
        int list1_size = list1.size();
        int list2_size = list2.size();
        int list1_ptr = 0;
        int list2_ptr = 0;
        while(list1_ptr < list1_size && list2_ptr < list2_size){
            if(list1[list1_ptr] <= list2[list2_ptr]){
                ans.push_back(list1[list1_ptr]);
                list1_ptr++;
            }
            else{
                ans.push_back(list2[list2_ptr]);
                list2_ptr++;
            }
        }
        while(list1_ptr < list1_size){
            ans.push_back(list1[list1_ptr]);
            list1_ptr++;
        }
        while(list2_ptr < list2_size){
            ans.push_back(list2[list2_ptr]);
            list2_ptr++;
        }
        return ans;
    }
    
    void dfs(TreeNode* root, vector<int>& list){
        if(!root){
            return;
        }
        dfs(root->left, list);
        list.push_back(root->val);
        dfs(root->right, list);
    }
};

//Problem Link - https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/

//Solution - 

/*
n - number of node in tree
h - height of tree
Time complexity - O(n)
Space complexity - O(h)
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
class Element {
public:
    int sum;
    int ele_count;
    Element(int sum, int ele_count){
        this->sum = sum;
        this->ele_count = ele_count;
    }
};
class Solution {
public:
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
    
    Element dfs(TreeNode* root, int& ans){
        if(!root)
            return {0, 0};
        Element left_tree = dfs(root->left, ans);
        Element right_tree = dfs(root->right, ans);
        int sum = left_tree.sum + right_tree.sum + root->val;
        int ele_count = left_tree.ele_count + right_tree.ele_count + 1;
        if(root->val == sum / ele_count){
            ans++;
        }
        return {sum, ele_count};
    }
};

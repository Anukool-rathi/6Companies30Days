//Problem Link - https://leetcode.com/problems/count-good-triplets-in-an-array/

//Solution - 

/*
n - size of array
Time complexity - O(n * logn)
Space complexity - O(n)
*/

class BinaryIndexedTree {
public:
    int n;
    vector<int> BIT;
    BinaryIndexedTree(int n){
        this->n = n;
        BIT.resize(n, 0);
    }
    
    void update(int x, int val){
        for(; x < n; x += x & (-x))
            BIT[x] += val;
    }
    
    int prefixSum(int x){
        int sum = 0;
        for(; x > 0; x -= x & (-x))
            sum += BIT[x];
        return sum;
    }
    
    int suffixSum(int x){
        int whole_sum = prefixSum(n - 1);
        int prefix_sum = prefixSum(x - 1);
        return whole_sum - prefix_sum;
    }
};
class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        long long ans = 0;
        int n = nums1.size();
        BinaryIndexedTree right_tree(n + 1);
        BinaryIndexedTree left_tree(n + 1);
        vector<int> idxs(n);
        for(int i = 0; i < n; i++){
            idxs[nums2[i]] = i;
        }
        for(int i = 0; i < n; i++){
            int cur_idx = idxs[nums1[i]] + 1;
            right_tree.update(cur_idx, 1);
        }
        for(int i = 0; i < n; i++){
            int cur_idx = idxs[nums1[i]] + 1;
            int next_idx = cur_idx + 1;
            int prev_idx = cur_idx - 1;
            right_tree.update(cur_idx, -1);
            ans += (long long)left_tree.prefixSum(prev_idx) * right_tree.suffixSum(next_idx);
            left_tree.update(cur_idx, 1);
        }
        return ans;
    }
};

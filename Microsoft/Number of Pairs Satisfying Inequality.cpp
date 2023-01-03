//Problem Link - https://leetcode.com/problems/number-of-pairs-satisfying-inequality/

//Solution - 


class BinaryIndexedTree {
private:
    vector<int> bit;
    int n;
public:
    BinaryIndexedTree(int& n){
        bit.resize(n + 1, 0);
        this->n = n + 1;
    }
    
    void update(int idx, int val){
        for(; idx < n; idx += idx & (-idx)){
            bit[idx] += val;
        }
    }
    
    int query(int idx){
        int sum = 0;
        for(; idx > 0; idx -= idx & (-idx)){
            sum += bit[idx];
        }
        return sum;
    }
};
class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int n = nums1.size();
        vector<int> nums(n);
        int min_ele = INT_MAX;
        int max_ele = INT_MIN;
        for(int i = 0; i < n; i++){
            nums[i] = nums1[i] - nums2[i];
            // cout<<nums[i]<<" ";
            min_ele = min(min_ele, nums[i]);
        }
        // cout<<"\n";
        min_ele = abs(min_ele);
        min_ele++;
        // diff += min_ele;
        for(int i = 0; i < n; i++){
            nums[i] += min_ele;
            // cout<<nums[i]<<" ";
            max_ele = max(max_ele, nums[i]);
        }
        // cout<<"\n";
        max_ele++;
        BinaryIndexedTree bit(max_ele);
        // cout<<max_ele<<"\n";
        long long ans = 0;
        for(int i = 0; i < n; i++){
            // cout<<nums[i]<<" == ";
            int max_allowed = min(max_ele ,nums[i] + diff);
            // cout<<max_allowed<<"\n";
            ans += bit.query(max_allowed);
            bit.update(nums[i], 1);
        }
        return ans;
    }
};

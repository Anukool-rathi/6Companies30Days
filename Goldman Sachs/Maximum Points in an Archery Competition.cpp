//Problem Link - https://leetcode.com/problems/maximum-points-in-an-archery-competition/

//Solution - 

/*
n = number of arrows
Time complexity - O(n)
Space complexity - O(n)
*/

class Solution {
public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        vector<int> bobArrows(12, 0);
        vector<int> temp(12, 0);
        int sum = 0, ans = 0;
        helper(numArrows, aliceArrows, bobArrows, temp, sum, ans, 0);
        return bobArrows;
    }
    
    void helper(int& numArrows,const vector<int>& aliceArrows, vector<int>& bobArrows, vector<int>& temp, int& sum, int& ans, int pos){
        if(sum > ans){
            ans = sum;
            bobArrows.assign(temp.begin(), temp.end());
            if(numArrows)
                bobArrows[0] += numArrows;
        }
        if(pos == 12){
            return;
        }

        int arrowsNeeded = aliceArrows[pos] + 1;
        if(numArrows >= arrowsNeeded){
            temp[pos] = arrowsNeeded;
            numArrows -= arrowsNeeded;
            sum += pos;
            helper(numArrows, aliceArrows, bobArrows, temp, sum, ans, pos + 1);
            temp[pos] = 0;
            numArrows += arrowsNeeded;
            sum -= pos;
        }
        helper(numArrows, aliceArrows, bobArrows, temp, sum, ans, pos + 1);
    }
};

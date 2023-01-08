//Problem Link - https://leetcode.com/problems/max-points-on-a-line/

//Solution - 

/*
n - number of points
Time complexity - O(n^2)
Space complexity - O(n)
*/

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 1;
        for(int i = 0; i < n; i++){
            unordered_map<double, int> slope_count;
            for(int j = 0; j < n; j++){
                if(i != j){
                    double dx = points[i][0] - points[j][0];
                    double dy = points[i][1] - points[j][1];
                    double slope = dy / dx;
                    slope_count[slope]++;
                }
            }
            for(auto& [slope, count] : slope_count){
                ans = max(ans, count + 1);
            }
        }
        return ans;
    }
};

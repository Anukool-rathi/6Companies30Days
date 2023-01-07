//Problem Link - https://leetcode.com/problems/number-of-boomerangs/

//Solution -

/*
n = number of points
Time Complexity - O(n^2)
Space Complexity - O(n)
*/

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            unordered_map<long, int> dist_count;
            for(int j = 0; j < n; j++){
                if(i == j){
                    long dist = getDist(points, i, j);
                    if(dist_count.count(dist)){
                        int freq = dist_count[dist];
                        ans += 2 * freq;
                    }
                    dist_count[dist]++;   
                }
            }
        }
        return ans;
    }
    long getDist(vector<vector<int>>& points, int& i, int& j){
        long dist = pow(points[i][0] - (long)points[j][0], 2) + pow(points[i][1] - (long)points[j][1], 2);
        return dist;
    }
};

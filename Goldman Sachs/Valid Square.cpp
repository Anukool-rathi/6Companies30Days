//Problem Link - https://leetcode.com/problems/valid-square/

//Solution - 

/*
Time complexity - O(1)
Sapce complexity - O(1)
*/

class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        unordered_set<int> dists;
        vector<vector<int>> points = {p1, p2, p3, p4};
        for(int i = 0; i < 4; i++){
            for(int j = i + 1; j < 4; j++){
                int dist = getDist(points[i], points[j]);
                if(dist == 0){
                    return false;
                }
                dists.insert(dist);
            }
        }
        if(dists.size() == 2){
            return true;
        }
        return false;
    }
    
    int getDist(vector<int>& x, vector<int>& y){
        int dy = pow(x[1] - y[1], 2);
        int dx = pow(x[0] - y[0], 2);
        int ans = dy + dx;
        return ans;
    }
};

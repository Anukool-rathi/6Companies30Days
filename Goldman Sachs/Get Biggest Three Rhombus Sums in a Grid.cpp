//Problem Link - https://leetcode.com/problems/get-biggest-three-rhombus-sums-in-a-grid/

//Solution - 

/*
n - dimensions of grid
Time complexity - O(n^4)
Space complexity - O(1)
*/

class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        set<int> sum;
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                for (int size = 0; i + size < n && i - size >= 0 && j + 2 * size < m; size++) {
                    int x = i;
                    int y = j;
                    int cur_sum = 0;
                    do{
                        cur_sum += grid[x][y];
                        x++;
                        y++;
                    }while (x < i + size);
                    if (size > 0) {
                        do{
                            cur_sum += grid[x][y];
                            x--;
                            y++;
                        }while (y < j + 2 * size);
                        do{
                            cur_sum += grid[x][y];
                            x--;
                            y--;
                        }while (x > i - size);
                        do{
                            cur_sum += grid[x][y];
                            x++;
                            y--;
                        }while (x < i);
                    }
                    sum.insert(cur_sum);
                    if (sum.size() > 3)
                        sum.erase(sum.begin());                
                }
            }
        }
        vector<int> ans(sum.rbegin(), sum.rend());
        return ans;
    }
};

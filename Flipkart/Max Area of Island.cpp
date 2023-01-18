//Problem Link - https://leetcode.com/problems/max-area-of-island/

//Solution -

/*
n - size of grid
Time complexity - O(n * n)
Space complexity - O(n * n)
*/

class Element {
public:
    int x;
    int y;
    Element(int x, int y){
        this->x = x;
        this->y = y;
    }
};
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        int islandDigit = 1;
        vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == islandDigit){
                    queue<Element> todo;
                    todo.push({i, j});
                    grid[i][j] = 0;
                    int currentArea = 0;
                    while(!todo.empty()){
                        Element cur_cell = todo.front();
                        todo.pop();
                        currentArea++;
                        ans = max(ans, currentArea);
                        for(vector<int>& direction : directions){
                            int indexX = cur_cell.x + direction[0];
                            int indexY = cur_cell.y + direction[1];
                            if(isValidIndex(indexX, indexY, m, n) && grid[indexX][indexY] == islandDigit){
                                todo.push({indexX, indexY});
                                grid[indexX][indexY] = 0;
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
    bool isValidIndex(int x, int y, int m, int n){
        return x >= 0 && x < m && y >= 0 && y < n;
    }
};

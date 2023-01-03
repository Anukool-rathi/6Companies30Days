//Problem Link - https://leetcode.com/problems/course-schedule/

//Solution - 


class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> list(numCourses, vector<int>());
        int temp;
        vector<int> in_degree(numCourses, 0);
        for(vector<int> pre : prerequisites){
            list[pre[1]].emplace_back(pre[0]);
            in_degree[pre[0]]++;
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(!in_degree[i])
                q.push(i);
        }
        while(!q.empty()){
            temp = q.front();
            q.pop();
            numCourses--;
            for(int i : list[temp]){
                in_degree[i]--;
                if(in_degree[i] == 0)
                    q.push(i);
            }
        }
        return numCourses == 0;
    }
};

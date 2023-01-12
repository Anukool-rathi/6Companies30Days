//Problem Link - https://leetcode.com/problems/minimum-genetic-mutation/

//Solution - 

/*
n - size of bank array
Time complexity - O(n)
Space complexity - O(n)
*/

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> dict;
        vector<char> allowed_gene = {'A', 'G', 'C', 'T'};
        for(string& valid_gene : bank){
            dict.insert(valid_gene);
        }
        if(!dict.count(end)){
            return -1;
        }
        queue<string> todo;
        todo.push(start);
        int mutation_count = -1;
        while(!todo.empty()){
            int size = todo.size();
            mutation_count++;
            while(size--){
                string cur_gene = todo.front();
                todo.pop();
                if(cur_gene == end){
                    return mutation_count;
                }
                for(int i = 0; i < 8; i++){
                    char cur_char = cur_gene[i];
                    for(int j = 0; j < 4; j++){
                        cur_gene[i] = allowed_gene[j];
                        if(dict.count(cur_gene)){
                            todo.push(cur_gene);
                            dict.erase(cur_gene);
                        }
                    }
                    cur_gene[i] = cur_char;
                }
            }
        }
        return -1;
    }
};

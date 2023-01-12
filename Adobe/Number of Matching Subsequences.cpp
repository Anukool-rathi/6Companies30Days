//Problem Link - https://leetcode.com/problems/number-of-matching-subsequences/

//Solution - 

/*
n - size of string s
m - size of words array
Time complexity - O(m * n)
Space complexity - O(n)
*/

class Element {
public:
    int index;
    int letter_index;
    Element(int index = 0, int letter_index = 0){
        this->index = index;
        this->letter_index = letter_index;
    }
};
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<char, vector<Element>> next_pointer;
        int ans = 0;
        int n = words.size();
        for(int i = 0; i < n; i++){
            string word = words[i];
            next_pointer[word[0]].push_back({i, 0});
        }
        
        for(char& c : s){
            vector<Element> temp = next_pointer[c];
            next_pointer[c].clear();
            for(auto& [index, letter_index] : temp){
                int size = words[index].size();
                if(letter_index == size - 1)
                    ans++;
                else{
                    letter_index++;
                    next_pointer[words[index][letter_index]].push_back({index, letter_index});
                }
            }
        }
        return ans;
    }
};

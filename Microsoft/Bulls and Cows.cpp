//Problem Link - https://leetcode.com/problems/bulls-and-cows/

//Solution - 


class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.size();
        string hint = "";
        int bulls = 0;
        int cows = 0;
        vector<int> freqs(10, 0);
        for(int i = 0; i < n; i++){
            if(secret[i] == guess[i]){
                secret[i] = '!';
                guess[i] = '!';
                bulls++;
            }
        }
        for(int i = 0; i < n; i++){
            if(secret[i] != '!'){
                int val = secret[i] - '0';
                freqs[val]++;
            }
        }
        for(int i = 0; i < n; i++){
            if(guess[i] != '!'){
                int val = guess[i] - '0';
                if(freqs[val] > 0){
                    cows++;
                    freqs[val]--;
                }
            }
        }
        hint = to_string(bulls) + "A" + to_string(cows) + "B";
        return hint;
    }
};

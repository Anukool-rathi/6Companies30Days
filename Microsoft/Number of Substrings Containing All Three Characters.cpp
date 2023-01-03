//Problem Link - https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/

//Solution - 


class Solution {
public:
    int numberOfSubstrings(string s) {
        long n = s.size();
        int t2 = atMostK(s, 2);
        long t1 = n * (n + 1) / 2;
        return t1 - t2;
    }
    int atMostK(string& s, int k){
        int n = s.size();
        int ans = 0;
        array<int, 3> freq = {0};
        int front = 0;
        int rear = 0;
        while(front < n){
            freq[s[front] - 'a']++;
            front++;
            while(inValid(freq, k)){
                freq[s[rear] - 'a']--;
                rear++;
            }
            ans += front - rear;
        }
        return ans;
    }
    
    bool inValid(array<int, 3>& freq, int k){
        int count = 0;
        for(int i = 0; i < 3; i++){
            if(freq[i])
                count++;
        }
        return count > k;
    }
};

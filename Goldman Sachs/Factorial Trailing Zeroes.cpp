//Problem Link - https://leetcode.com/problems/factorial-trailing-zeroes/

//Solution - 


class Solution {
public:
    int trailingZeroes(int n) {
        int div = 5, count = 0;
        while(n / div >= 1){
            count += n / div;
            div *= 5;
        }
        return count;
    }
};

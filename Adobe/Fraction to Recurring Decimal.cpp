//Problem Link - https://leetcode.com/problems/fraction-to-recurring-decimal/

//Solution - 


class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0){
            return "0";
        }
        string ans = "";
        if(numerator > 0 ^ denominator > 0){
            ans += '-';
        }
        long ntr = abs(numerator);
        long dtr = abs(denominator);
        long remainder = ntr % dtr;
        ans += to_string(ntr / dtr);
        if(remainder == 0){
            return ans;
        }
        ans += '.';
        unordered_map<long, int> val_to_pos;
        while(remainder){
            if(val_to_pos.count(remainder)){
                int idx = val_to_pos[remainder];
                ans.insert(idx, "(");
                ans += ')';
                return ans;
            }
            int idx = ans.size();
            val_to_pos[remainder] = idx;
            remainder *= 10;
            ans += to_string(remainder / dtr);
            remainder %= dtr;
        }
        return ans;
    }
};

//Problem Link - https://leetcode.com/problems/ipo/

//Solution - 

/*
k - number of projects
w - initial capital
n - size of profit and capital array
Time complexity - O(n * logn)
Space complexity - O(n)
*/

class Element {
public:
    int profit;
    int capital;
    Element(int profit, int capital){
        this->profit = profit;
        this->capital = capital;
    }
};
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        int ans = w;
        int i = 0;
        vector<Element> profit_capital_arr(n, {0, 0});
        priority_queue<int> max_profit;
        for(int i = 0; i < n; i++){
            profit_capital_arr[i] = {profits[i], capital[i]};
        }
        sort(profit_capital_arr.begin(), profit_capital_arr.end(), cmp);
        while(k--){
            while(i < n && profit_capital_arr[i].capital <= w){
                max_profit.push(profit_capital_arr[i].profit);
                i++;
            }
            if(max_profit.empty()){
                break;
            }
            int top = max_profit.top();
            max_profit.pop();
            w += top;
        }
        return w;
    }
    
    static bool cmp(Element& x, Element& y){
        return x.capital < y.capital;
    }
};

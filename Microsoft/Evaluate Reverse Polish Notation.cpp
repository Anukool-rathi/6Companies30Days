//Problem Link - https://leetcode.com/problems/evaluate-reverse-polish-notation/

//Solution - 


class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int> todo;
        for(int i = 0; i < n; i++){
            if(isOperator(tokens[i])){
                int op1 = todo.top();
                todo.pop();
                int op2 = todo.top();
                todo.pop();
                int res = solve(op1, op2, tokens[i]);
                todo.push(res);
            }
            else{
                int val = stoi(tokens[i]);
                todo.push(val);
            }
        }
        int ans = todo.top();
        return ans;
    }
    
    bool isOperator(string& token){
        return token == "+" || token == "-" || token == "*" || token == "/";
    }
    
    int solve(int& op1, int& op2, string& oper){
        if(oper == "+"){
            return op2 + op1;
        }
        if(oper == "-"){
            return op2 - op1;
        }
        if(oper == "/"){
            return op2 / op1;
        }
        return op2 * op1;
    }
};

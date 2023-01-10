//Problem Link - https://leetcode.com/problems/invalid-transactions/

//Solution - 

/*
n - number of transaction
Time complexity - O(n^2)
Space complexity - O(n)
*/

class Element {
public:
    string name;
    int time;
    int amount;
    string city;
    Element(string name = "", int time = 0, int amount = 0, string city = ""){
        this->name = name;
        this->time = time;
        this->amount = amount;
        this->city = city;
    }
};
class ArrElement {
public:
    int time;
    string city;
    int idx;
    ArrElement(int time = 0, string city = "", int idx = -1){
        this->time = time;
        this->city = city;
        this->idx = idx;
    }
};
class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        int n = transactions.size();
        vector<Element> transactions_arr(n);
        vector<string> ans;
        unordered_set<int> ans_idxs;
        unordered_map<string, vector<ArrElement>> name_to_details;
        for(int i = 0; i < n; i++){
            transactions_arr[i] = getVals(transactions[i]);
        }
        
        for(int i = 0; i < n; i++){
            string name = transactions_arr[i].name;
            int time = transactions_arr[i].time;
            int amount = transactions_arr[i].amount;
            string city = transactions_arr[i].city;
            name_to_details[name].push_back({time, city, i});
            if(amount > 1000){
                ans_idxs.insert(i);
            }
        }
        for(auto& [name, details] : name_to_details){
            int size = details.size();
            for(int i = 0; i < size; i++){
                int cur_time = details[i].time;
                string cur_city = details[i].city;
                int cur_idx = details[i].idx;
                for(int j = 0; j < size; j++){
                    int time = details[j].time;
                    string city = details[j].city;
                    int idx = details[j].idx;
                    if(cur_city != city && abs(cur_time - time) <= 60){
                        ans_idxs.insert(idx);
                        ans_idxs.insert(cur_idx);
                    }
                }
            }
        }
        for(const int& idx : ans_idxs){
            ans.push_back(transactions[idx]);
        }
        return ans;
    }
       
    Element getVals(string& transaction){
        Element res;
        string name = "";
        int time = 0;
        int amount = 0;
        string city = "";
        int n = transaction.size();
        int i = 0;
        while(transaction[i] != ','){
            name += transaction[i];
            i++;
        }
        i++;
        while(transaction[i] != ','){
            time *= 10;
            time += transaction[i] - '0';
            i++;
        }
        i++;
        while(transaction[i] != ','){
            amount *= 10;
            amount += transaction[i] - '0';
            i++;
        }
        i++;
        while(i < n){
            city += transaction[i];
            i++;
        }
        res = {name, time, amount, city};
        return res;
    }
};

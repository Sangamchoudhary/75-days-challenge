class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int profit = 0 , buy = 0,sell = 0;
        for (int i = 1; i < arr.size(); i++){
            if(arr[i] > arr[i-1]){
                sell++;
            }else{
                profit += arr[sell] - arr[buy];
                buy = sell = i;
            }
        }
        profit += arr[sell] - arr[buy];
        return profit;
    }
};
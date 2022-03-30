class Solution {
public:
    int findDuplicate(vector<int>& arr){
        //piegeonhole principle
        int n = arr.size();
        for(int i=0;i<n;i++){
            if(arr[abs(arr[i])] < 0) return abs(arr[i]);
            else arr[abs(arr[i])] *= -1; 
        }
        return -1;
        
        //normal sum
        int sum = 0;
        for(auto it : arr) sum += it;
        int totalNumber = n-1;
        int orgSum = (totalNumber * (totalNumber + 1)) / 2;
        int ans = sum - orgSum;
        return ans;
    }
};
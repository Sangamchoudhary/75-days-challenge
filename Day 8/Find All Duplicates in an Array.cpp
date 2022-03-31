class Solution {
public:
    vector<int> findDuplicates(vector<int>& arr) {
        vector<int> ans;
        int n = arr.size();
        
        int i=0;
        while(i < n){
            int cIdx = arr[i] - 1;
            if(arr[i] != arr[cIdx]) swap(arr[i],arr[cIdx]);
            else i++;
        }
        
        i=0;
        while(i<n){
            if(arr[i] != i+1) ans.push_back(arr[i]);
            i++;
        }
        
        return ans;
    }
};
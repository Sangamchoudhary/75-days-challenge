class Solution {
public:
    vector<string> solve(int n){
        if(n == 1) return {"0","1"};
        
        vector<string> arr = solve(n-1);
        
        vector<string> code;
        
        for(int i=0;i<arr.size();i++) code.push_back("0" + arr[i]);
        
        for(int i=arr.size()-1;i>=0;i--) code.push_back("1" + arr[i]);
        
        return code;
    }
    
    vector<int> grayCode(int n) {
        vector<int> ans;
        for(auto it : solve(n))
            ans.push_back(stoi(it,0,2)); // converting from binary to int
        return ans;
    }
};
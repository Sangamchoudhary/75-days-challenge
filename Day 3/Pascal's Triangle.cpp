class Solution {
public:
    vector<vector<int>> generate(int b) {
        vector<vector<int>> ans;
        
        ans.push_back({1});
        
        for(int i=1;i<b;i++){
            int size = ans[i-1].size();
            vector<int> temp;
            int prev = 0;
            for(int j=0;j<size;j++){
                temp.push_back(prev + ans[i-1][j]);
                prev = ans[i-1][j];
            }
            temp.push_back(ans[0][0]);
            ans.push_back(temp);
        }
        
        return ans;
    }
};
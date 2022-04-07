class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int m =  mat.size() , n = mat[0].size();
        int i = 0 , j = n-1;
        
        while(i < m and j >= 0){
            
            if(target < mat[i][j])  j--;
            
            else if(target > mat[i][j]) i++;
            
            else return true;
            
        }
        
        return false;
    }
};
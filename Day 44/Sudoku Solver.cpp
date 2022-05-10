class Solution {
private:
    bool isSafe(vector<vector<char>> &grid,int i,int j,char num){
        //row
        for(int row = 0;row<9;row++){
            if(grid[row][j] == num) return false;
        }
        
        //coloumn
        for(int col = 0;col<9;col++){
            if(grid[i][col] == num) return false;
        }
        
        //subgrid
        int subRow = (i/3) * 3, subCol = (j/3) * 3;
        for(int row = subRow;row < subRow+3;row++){
            for(int col = subCol;col < subCol+3;col++){
                if(grid[row][col] == num) return false;
            }
        }
        
        return true;
    }
    
    bool solve(vector<vector<char>> &grid,int i,int j){
        if(i == 9) return true;
        if(j == 9) return solve(grid,i+1,0);
        
        if(grid[i][j] != '.') return solve(grid,i,j+1);
        
        for(char num = '1';num <= '9';num++){
            if(isSafe(grid,i,j,num)){
                grid[i][j] = num;
                if(solve(grid,i,j+1)) return true;
            }
        }
        
        grid[i][j] = '.';
        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board,0,0);    
    }
};
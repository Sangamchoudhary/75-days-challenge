class Solution {
    public:
    bool isSafe(int grid[9][9],int i,int j,int num){
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
    
    bool solve(int grid[9][9],int i,int j){
        if(i == 9) return true;
        if(j == 9) return solve(grid,i+1,0);
        
        if(grid[i][j] != 0) return solve(grid,i,j+1);
        
        for(int num = 1;num <= 9;num++){
            if(isSafe(grid,i,j,num)){
                grid[i][j] = num;
                if(solve(grid,i,j+1)) return true;
            }
        }
        
        grid[i][j] = 0;
        return false;
    }
    
    bool SolveSudoku(int grid[N][N]) {
        return solve(grid,0,0);
    }
    
    void printGrid (int grid[N][N]) {
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cout<<grid[i][j]<<" ";
            }
        }
    }
};
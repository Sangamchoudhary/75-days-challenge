class Solution {
public:
    int iarr[8] = {-1,-1,-1,0,0,1,1,1};
    int jarr[8] = {0,-1,1,-1,1,0,-1,1};

    bool isValid(int i,int j,int m,int n){
        if(i < 0 or j < 0 or i >= m or j >= n) return false;
        return true;
    }

    bool condn(int condnNumber,int row,int col,int m,int n,vector<vector<int>> &board){
        int sum = 0;
        for(int i=0;i<8;i++){
            if(isValid(row+iarr[i], col+jarr[i], m, n)){
                sum += board[row+iarr[i]][col+jarr[i]]; 
            }
        }
        if(condnNumber == 1 and sum < 2) return true;
        else if(condnNumber == 2 and (sum == 2 or sum == 3) ) return true;
        else if(condnNumber == 3 and sum>3) return true;
        else if(condnNumber == 4 and sum == 3) return true;
        else return false;
    }
    void gameOfLife(vector<vector<int>>& board){
        int m = board.size(), n = board[0].size();
        vector<vector<int>> ans = board;  
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){        
                if(board[i][j] and condn(1,i,j,m,n,board)){
                    ans[i][j] = 0;
                }else if(board[i][j] and condn(2,i,j,m,n,board)){
                    ans[i][j] = 1;
                }else if(board[i][j] and condn(3,i,j,m,n,board)){
                    ans[i][j] = 0;
                }else if(!board[i][j] and condn(4,i,j,m,n,board)){
                    ans[i][j] = 1;
                }
            }
        }
        board = ans;
    }    
};

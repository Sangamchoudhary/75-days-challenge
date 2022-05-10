class Solution{
public:
    bool isValid(int i,int j,vector<vector<int>> &board,int &n){
        //upper row
        int row = i-1,col = j;
        while(row>=0 and col>=0 and row<n and col<n){
            if(board[row][col] != 0){
                return false;
            }
            row--;
        }
        //upper left diagonal
        row = i-1,col = j-1;
        while(row>=0 and col>=0 and row<n and col<n){
            if(board[row][col] != 0){
                return false;
            }
            row--,col--;
        }
        //upper right diagonal
        row = i-1,col = j+1;
        while(row>=0 and col>=0 and row<n and col<n){
            if(board[row][col] != 0){
                return false;
            }
            row--,col++;
        }
        //If everything is correct
        return true;
    }

    void solve(int row,vector<int> &temp,vector<vector<int>> &board,vector<vector<int>> &ans,int &n){
        if(row == n){
            ans.push_back(temp);
            return;
        }
        for(int j=0;j<n;j++){
            if(isValid(row,j,board,n)){
                temp.push_back(j + 1);
                board[row][j] = 1;
                solve(row+1,temp,board,ans,n);
                board[row][j] = 0;
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> ans;
        vector<vector<int>> board(n ,vector<int> (n,0));
        vector<int> temp;
        solve(0,temp,board,ans,n);
        return ans;
    }
};
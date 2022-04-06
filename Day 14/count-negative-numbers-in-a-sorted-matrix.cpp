int countNegatives(vector<vector<int>>& grid) {
    int n=grid.size();
    int m=grid[0].size();
    if(n<0 or m<0) return 0;
    int count=0;
    int i=n-1,j=0;
    // i is for row and j is for columns
    while(i>=0 and j<m) {
        if(grid[i][j]<0) {
            i--; // if we found out an -ve element then move upwards in row
            count+=m-j; //if its an -ve element then rest will be the negative as well bcoz array is sorted
        }else j++; //else move forward in columns
    }
    return count;
}
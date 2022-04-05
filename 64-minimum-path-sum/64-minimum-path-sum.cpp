class Solution {
    // int pathSum(int i,int j,vector<vector<int>>&grid,int n,int m,vector<vector<int>>& memo)
    // {
    //     if(i>=n || j>=m)
    //         return INT_MAX;
    //     if(i==n-1 && j==m-1)
    //         return grid[i][j];
    //     if(memo[i][j]!=-1)
    //         return memo[i][j];
    //     return memo[i][j]=min(pathSum(i+1,j,grid,n,m,memo),pathSum(i,j+1,grid,n,m,memo))+grid[i][j];
    // }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        // vector<vector<int>>memo(n,vector<int>(m,-1));
        // return pathSum(0,0,grid,n,m,memo);
        for(int i=1;i<n;i++)
        {
            grid[i][0]+=grid[i-1][0];
        }
        for(int i=1;i<m;i++)
        {
            grid[0][i]+=grid[0][i-1];
        }
        
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                grid[i][j]+=min(grid[i-1][j],grid[i][j-1]);
            }
        }
        return grid[n-1][m-1];
    }
};
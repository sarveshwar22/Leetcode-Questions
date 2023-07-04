class Solution {
    void dfs(vector<vector<int>>& grid, int i, int j)
    {
        int m = grid.size();
        int n = grid[0].size();
        
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j])
             return;
        grid[i][j] = 1;
        dfs(grid,i+1,j);
        dfs(grid,i-1,j);
        dfs(grid,i,j+1);
        dfs(grid,i,j-1);
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i=0;i<m;i++)
        {
            if(!grid[i][0])
                dfs(grid,i,0);
            if(!grid[i][n-1])
                dfs(grid,i,n-1);
        }
        for(int j=1;j<n-1;j++)
        {
            if(!grid[0][j])
                dfs(grid,0,j);
            if(!grid[m-1][j])
                dfs(grid,m-1,j);
        }
        int ans = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!grid[i][j])
                {
                    dfs(grid,i,j);
                    ans++;
                }
            }
        }
        return ans;
            
    }
};
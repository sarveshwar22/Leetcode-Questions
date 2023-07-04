class Solution {
    void dfs(vector<vector<int>>&grid,int x, int y)
    {
        int m = grid.size();
        int n = grid[0].size();
        if(x<0 || x>m-1 ||y<0 ||y>n-1 || !grid[x][y])
            return;
        grid[x][y]=0;
        dfs(grid,x+1,y);
        dfs(grid,x-1,y);
        dfs(grid,x,y+1);
        dfs(grid,x,y-1);
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0;i<m;i++)
        {
           if(grid[i][0])
               dfs(grid,i,0);
            if(grid[i][n-1])
                dfs(grid,i,n-1);
        }
        for(int j=1;j<n-1;j++)
        {
            if(grid[0][j])
                dfs(grid,0,j);
            if(grid[m-1][j])
                dfs(grid,m-1,j);
        }
        int res = 0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(grid[i][j])
                    res++;
        return res;
    }
};
class Solution {
    void dfs(vector<vector<char>>& grid,vector<vector<bool>>& visited, int i, int j)
    {
        int n=grid.size();
        int m=grid[0].size();
        if(i<0||i>=n||j<0||j>=m|| grid[i][j]=='0'|| visited[i][j])
        {
            return;
        }
        visited[i][j]=true;
        dfs(grid,visited,i+1,j);
        dfs(grid,visited,i-1,j);
        dfs(grid,visited,i,j+1);
        dfs(grid,visited,i,j-1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        if(n==0)
            return 0;
        int m=grid[0].size();
        int NoOfIslands=0;
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!visited[i][j] && grid[i][j]=='1')
                {
                    NoOfIslands++;
                    dfs(grid,visited,i,j);
                }
            }
        }
        return NoOfIslands;
    }
};
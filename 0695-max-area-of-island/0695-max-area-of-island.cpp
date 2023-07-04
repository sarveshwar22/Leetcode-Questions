class Solution {
    vector<vector<bool>> visited;
        
    void dfs(vector<vector<int>>& grid, int i, int j, int &cur)
    {
        int n=grid.size();
        int m = grid[0].size();
        if(i<0 || j<0 || i>=n || j>=m || !grid[i][j] ||visited[i][j])
            return;
        cur++;
        visited[i][j] = true;
        dfs(grid,i+1,j,cur);
        dfs(grid,i-1,j,cur);
        dfs(grid,i,j+1,cur);
        dfs(grid,i,j-1,cur);
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res,cur;
        res = cur = 0;
        int n=grid.size();
        int m = grid[0].size();
        visited = vector<vector<bool>>(n,vector<bool>(m,false));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!visited[i][j]){
                    cur = 0;
                    dfs(grid,i,j,cur);
                    res = max(res,cur);
                }
            }
        }
        return res;
    }
};
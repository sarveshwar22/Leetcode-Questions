static int MOD = 1e9+7;
static vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
class Solution {
    vector<vector<long long>> dp;
    int n,m;
    long long dfs(vector<vector<int>>& grid,int i,int j)
    {
        long long res=1;
        if(dp[i][j]!=-1)
            return dp[i][j];
        for(int k=0;k<4;k++)
        {
            if(i+dir[k][0]>=0 && i+dir[k][0]<n && j+dir[k][1]>=0 && j+dir[k][1]<m && grid[i+dir[k][0]][j+dir[k][1]]>grid[i][j])
                res=(res+dfs(grid,i+dir[k][0],j+dir[k][1]))%MOD;
        }
        return dp[i][j]=res%MOD;
    }
public:
    int countPaths(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        dp=vector<vector<long long>>(n,vector<long long>(m,-1));
        long long res=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                res=(res+dfs(grid,i,j))%MOD;
            }
        }
        return res%MOD;
    }
};
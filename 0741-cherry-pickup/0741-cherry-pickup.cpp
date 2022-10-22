class Solution {int dp[51][51][51];
    int dfs(int r1,int c1,int r2,int n,vector<vector<int>>&grid)
    {
        int c2=r1+c1-r2;
        if(r1>=n || r2>=n || c1>=n || c2>=n || grid[r1][c1]==-1 || grid[r2][c2]==-1)
            return INT_MIN;
        
        if(dp[r1][c1][r2]!=-1)
            return dp[r1][c1][r2];
        
        
        if(r1==n-1 && c1==n-1)
            return grid[r1][c1];
        
        int ans=grid[r1][c1];
        if(r1!=r2)
            ans += grid[r2][c2];
        
        ans+= max({dfs(r1+1,c1,r2+1,n,grid),dfs(r1,c1+1,r2,n,grid),dfs(r1+1,c1,r2,n,grid),dfs(r1,c1+1,r2+1,n,grid)});
        return dp[r1][c1][r2]=ans;
    }
public:       
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        int n=grid.size();
        return max(0,dfs(0,0,0,n,grid));
    }
};
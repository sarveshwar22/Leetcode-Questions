class Solution {
public:
    int dp[42][42][1609];
    const static int MAX = 1e7;
    
    int shortestPath(vector<vector<int>>& grid, int k) {
        return help(grid, grid.size() - 1, grid[0].size() - 1, k, k);
    }
    
    int help(vector<vector<int>>& grid, int x, int y, int z, int k){
        
        if(x == 0 && y  == 0)return 0;
        if(dp[x][y][z]) return dp[x][y][z];
        if(grid[x][y] == 1 && z == 0)return MAX;
        if(z >= x + y)return dp[x][y][z] = x+y;
        
        vector<vector<int>> dirs = {{-1,0}, {0,-1}, {1,0}, {0,1}};
        dp[x][y][z] = MAX;
        
        for(auto dir:dirs){
            if(x + dir[0] >= 0 && x + dir[0] < grid.size() && y + dir[1] >=0 && y + dir[1] < grid[0].size() )
            {
                dp[x][y][z] = min(dp[x][y][z], help(grid, x + dir[0], y + dir[1], z - grid[x][y], k) + 1);
            }
        }
        if(z == k && x == grid.size() - 1 && y == grid[0].size() - 1 && dp[x][y][z] == MAX)
            return -1;
        return dp[x][y][z];
        
    }
	};
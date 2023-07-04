class Solution {
    vector<vector<int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};
    bool isValid(int x,int y, int m,int n)
    {
        if(x<0 || y<0 || x>=m || y>=n)
            return false;
        return true;
    }
public:
    int maxDistance(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        int ans = -1;
        vector<vector<int>> res(m,vector<int>(n,-1));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j])
                {
                    q.push({i,j});
                    res[i][j] = 0;
                }
            }
        }
        while(!q.empty())
        {
            pair<int,int> point = q.front();
            q.pop();
            for(vector<int>& dir:directions)
            {
                int x = point.first + dir[0];
                int y = point.second + dir[1];
                if(isValid(x,y,m,n) && res[x][y]==-1)
                {
                    q.push({x,y});
                    res[x][y] = 1+res[point.first][point.second];
                    ans = max(ans,res[x][y]);
                }
            }
        }
        return ans;
    }
};
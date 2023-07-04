class Solution {
    vector<vector<int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};
    bool isValid(int x, int y, int m, int n)
    {
        if(x<0 || y<0 || x>=m || y>=n)
            return false;
        return true;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<vector<int>> q;
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2)
                    q.push({0,i,j});
            }
        }
        int res = 0;
        while(!q.empty())
        {
            vector<int> front = q.front();
            q.pop();
            res = max(res,front[0]);
            for(vector<int>& dir:directions)
            {
                int time = front[0]+1;
                int x = front[1]+dir[0];
                int y = front[2]+dir[1];
                if(isValid(x,y,m,n) && grid[x][y]==1)
                {
                    grid[x][y] = 2;
                    q.push({time,x,y});
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                    return -1;
            }
        }
        return res;
        
    }
};
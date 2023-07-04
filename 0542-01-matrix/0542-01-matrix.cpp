class Solution {
    vector<vector<int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};
    bool isValid(int x,int y, int m, int n)
    {
        if(x<0 || y<0 || x>=m || y>=n)
            return false;
        return true;
    }
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dis(m,vector<int>(n,-1));
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==0)
                {
                    q.push({i,j});
                    dis[i][j] = 0;
                }
            }
        }
        
        while(!q.empty())
        {
            pair<int,int> curr = q.front();
            q.pop();
            for(vector<int>& dir:directions)
            {
                int x = curr.first+dir[0];
                int y = curr.second+dir[1];
                if(isValid(x,y,m,n) && dis[x][y]==-1)
                {
                    q.push({x,y});
                    dis[x][y] = dis[curr.first][curr.second]+1;
                }
            }
        }
        return dis;
    }
};
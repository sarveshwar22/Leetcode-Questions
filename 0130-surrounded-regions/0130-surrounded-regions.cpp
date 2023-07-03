class Solution {
    vector<vector<bool>> circles;
    void dfs(int x,int y,vector<vector<char>>& board)
    {
        int m = board.size();
        int n = board[0].size();
        if(x<0 || x>=m || y<0 || y>=n || board[x][y]!='O' || circles[x][y])
            return;
        circles[x][y] = true;
        dfs(x+1,y,board);
        dfs(x-1,y,board);
        dfs(x,y-1,board);
        dfs(x,y+1,board);
    }
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        circles = vector<vector<bool>> (m,vector<bool>(n,false));
        for(int i=0;i<m;i++)
        {
            if(board[i][0]=='O')
            {
                dfs(i,0,board);
                
            }
            if(board[i][n-1]=='O')
            {
                dfs(i,n-1,board);
            }
        }
        for(int j=1;j<n-1;j++)
        {
            if(board[0][j]=='O')
            {
                dfs(0,j,board);
            }
            if(board[m-1][j]=='O')
            {
                dfs(m-1,j,board);
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(circles[i][j])
                    board[i][j]='O';
                else
                    board[i][j] = 'X';
            }
        }
    }
};
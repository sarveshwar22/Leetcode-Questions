class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> visited1(9,vector<bool>(9,false));
        vector<vector<bool>> visited2(9,vector<bool>(9,false));
        vector<vector<bool>> visited3(9,vector<bool>(9,false));
        
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]!='.')
                {
                    int curr=board[i][j]-'1';
                    int k=i/3*3+j/3;
                    if(visited1[i][curr]||visited2[j][curr]||visited3[k][curr])
                        return false;
                    visited1[i][curr]=visited2[j][curr]=visited3[k][curr]=true;
                }
            }
        }
        return true;
    }
};
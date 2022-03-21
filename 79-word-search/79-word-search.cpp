class Solution {
    bool dfs(vector<vector<char>>&board,int i,int j,string word)
    {
        if(word.size()==0)
            return true;
        if(i<0||i>=board.size()||j<0||j>=board[0].size()||board[i][j]!=word[0])
            return false;
        
        char c=board[i][j];
        board[i][j]='*';
        string s=word.substr(1);
        bool ans=dfs(board,i+1,j,s)||
            dfs(board,i-1,j,s)||
            dfs(board,i,j-1,s)||
            dfs(board,i,j+1,s);
        board[i][j]=c;
        return ans;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int count=0;
        for(int i=1;i<word.size();i++)
        {
            if(word[i]==word[i-1])
                count++;
            else
            {
                if(count>6)
                {
                    reverse(word.begin(),word.end());
                    break;
                }
            }
        }
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(dfs(board,i,j,word))
                    return true;
            }
        }
        return false;
    }
};
// class Solution {
//     bool dfs(vector<vector<char>>& board,int startX,int startY,string word,int curr)
//     {
//         if(curr==word.size())
//             return true;
        
//         if(startX<0 || startX>=board.size() || startY<0 || startY>=board[0].size() || (board[startX][startY]=='#' || board[startX][startY]!=word[curr]))
//             return false;
        
//         char c=board[startX][startY];
//         board[startX][startY]='#';
//         bool ans=dfs(board,startX+1,startY,word,curr+1)||
//             dfs(board,startX-1,startY,word,curr+1)||
//             dfs(board,startX,startY+1,word,curr+1)||
//             dfs(board,startX,startY-1,word,curr+1);
//         board[startX][startY]=c;
//         return ans;
        
//     }
    
// public:
//     vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
//         vector<vector<vector<int>>> pos(26);
//         int n=board.size();
//         int m=board[0].size();
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<m;j++)
//             {
//                 vector<int> v={i,j};
//                 (pos[board[i][j]-'a']).push_back(v);
//             }
//         }
//         vector<string> res;
//         for(int i=0;i<words.size();i++)
//         {
//             if(words[i].size()==0)
//                 continue;
//             if((pos[words[i][0]-'a']).size()==0)
//                 continue;
            
//             for(int j=0;j<pos[words[i][0]-'a'].size();j++)
//             {
//                 int startX=pos[words[i][0]-'a'][j][0];
//                 int startY=pos[words[i][0]-'a'][j][1];
                
//                 if(dfs(board,startX,startY,words[i],0))
//                 {
//                     res.push_back(words[i]);
//                     goto x;
//                 }
//             }
//             x:continue;
//         }
//         return res;
        
//     }
// };

class Solution {
    
public:
    struct node
    {
        char c;
        int ending;
        string word;
        node *childrens[26];
    };
    
    node* getNode(char c)
    {
        node* newNode=new node;
        newNode->c=c;
        newNode->ending=0;
        newNode->word="";
        for(int i=0;i<26;i++)
            newNode->childrens[i]=NULL;
        return newNode;
    }
    
    node* root= getNode('/');
    
    void insert(string s)
    {
        node* curr=root;
        for(int i=0;i<s.size();i++)
        {
            if(curr->childrens[s[i]-'a']==NULL)
            {
                curr->childrens[s[i]-'a']=getNode(s[i]);
            }
            curr=curr->childrens[s[i]-'a'];
        }
        curr->ending++;
        curr->word=s;
    }
    
    void dfs(vector<vector<char>>&board,int i,int j,vector<string> &res,node* curr)
    {
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j]=='#')
            return;
        if(curr->childrens[board[i][j]-'a']==NULL)
            return;
        curr=curr->childrens[board[i][j]-'a'];
        if(curr->ending>0)
        {
            res.push_back(curr->word);
            curr->ending--;
        }
        
        char ch=board[i][j];
        board[i][j]='#';
        dfs(board,i+1,j,res,curr);
        dfs(board,i-1,j,res,curr);
        dfs(board,i,j+1,res,curr);
        dfs(board,i,j-1,res,curr);
        board[i][j]=ch;
    }
    
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for(string word:words)
            insert(word);
        vector<string> res;
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                dfs(board,i,j,res,root);
            }
        }
        return res;
        
    }
};

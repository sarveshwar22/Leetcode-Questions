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

// class Solution {
    
// public:
//     struct node
//     {
//         char c;
//         int ending;
//         string word;
//         node *childrens[26];
//     };
    
//     node* getNode(char c)
//     {
//         node* newNode=new node;
//         newNode->c=c;
//         newNode->ending=0;
//         newNode->word="";
//         for(node* child:newNode->childrens)
//             child=NULL;
//         return newNode;
//     }
    
//     node* root= getNode('/');
    
//     void insert(string s)
//     {
//         node* curr=root;
//         for(int i=0;i<s.size();i++)
//         {
//             if(curr->childrens[s[i]-'a']==NULL)
//             {
//                 curr->childrens[s[i]-'a']=getNode(s[i]);
//             }
//             curr=curr->childrens[s[i]-'a'];
//         }
//         curr->ending++;
//         curr->word=s;
//     }
    
//     void dfs(vector<vector<char>>&board,int i,int j,vector<string> &res,node* curr)
//     {
//         if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j]=='#')
//             return;
//         if(curr->childrens[board[i][j]-'a']==NULL)
//             return;
//         curr=curr->childrens[board[i][j]-'a'];
//         if(curr->ending>0)
//         {
//             res.push_back(curr->word);
//             curr->ending--;
//         }
        
//         char ch=board[i][j];
//         board[i][j]='#';
//         dfs(board,i+1,j,res,curr);
//         dfs(board,i-1,j,res,curr);
//         dfs(board,i,j+1,res,curr);
//         dfs(board,i,j-1,res,curr);
//         board[i][j]=ch;
//     }
    
    
//     vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
//         for(string word:words)
//             insert(word);
//         vector<string> res;
//         for(int i=0;i<board.size();i++)
//         {
//             for(int j=0;j<board[0].size();i++)
//             {
//                 dfs(board,i,j,res,root);
//             }
//         }
//         return res;
        
//     }
// };

class Solution {    
    struct node{    //TrieNode
        char c;
        int ends;
        string word;
        node *child[26];
    };
    struct node *getNode(char c)    //get newnode
    {
        node *newnode = new node;
        newnode->c = c;
        newnode->ends = 0;
        newnode->word = "";
        for(int i=0;i<26;++i)
            newnode->child[i] = NULL;
        return newnode;
    }
    node *root = getNode('/');  //root
    
    //Trie INSERT
    void insert(string s)
    {
        node *curr=root;
        int index,i=0;
        while(s[i])
        {
            index = s[i]-'a';
            if(curr->child[index]==NULL)
                curr->child[index] = getNode(s[i]);
            
            curr=curr->child[index];
            i+=1;
        }
        curr->ends += 1;
        curr->word = s;
    }
    
    void solve(vector<vector<char>>& board,int i,int j,int r,int c,vector<string>& ans,node *curr)
    {
        //Base case
        //If the trie doesn't have the current char OR cell is Visited
        int index = board[i][j]-'a';
        if(board[i][j]=='$' || curr->child[index]==NULL)  
            return;
        
        curr = curr->child[index];
        if(curr->ends > 0)
        {
            ans.push_back(curr->word);
            curr->ends -=1;
        }
        
        //Body
        char ch = board[i][j];   //Store current char
        board[i][j] = '$';  //Mark current node visited
        
        if(i>0)     //TOP
            solve(board,i-1,j,r,c,ans,curr);
        if(i<r-1)   //DOWN
            solve(board,i+1,j,r,c,ans,curr);
        if(j>0)     //LEFT
            solve(board,i,j-1,r,c,ans,curr);
        if(j<c-1)   //RIGHT
            solve(board,i,j+1,r,c,ans,curr);
        
        board[i][j] = ch;    //Mark current node as Unvisited by restoring the value
    }
    
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {        
        int r=board.size();
        int c=board[0].size();
        
        //Insert all words in TRIE
        for(int i=0;i<words.size();++i)
            insert(words[i]);
        
        //Now search words
        vector<string> ans;
        for(int i=0;i<r;++i)
        {
            for(int j=0;j<c;++j)
                solve(board,i,j,r,c,ans,root);
        }
        return ans;
    }
};
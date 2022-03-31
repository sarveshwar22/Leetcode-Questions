class Solution {
    
    void dfs(int leftBracket,int rightBracket,string& curr,vector<string>& res)
    {
        
        if(leftBracket==0 && rightBracket==0)
        {
            res.push_back(curr);
            return;
        }
        int c=0;
        if(leftBracket>rightBracket)
            return;
        if(leftBracket>0){
            dfs(leftBracket-1,rightBracket,curr+='(',res);
            curr.pop_back();
        }
        if(rightBracket>0){
            dfs(leftBracket,rightBracket-1,curr+=')',res);
            curr.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string curr="";
        dfs(n,n,curr,res);
        return res;
    }
};
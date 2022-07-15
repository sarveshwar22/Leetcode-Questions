class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>s;
        for(int i=0;i<tokens.size();i++)
        {
            if(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="*"||tokens[i]=="/")
            {
                int x1=(s.top());
                s.pop();
                int x2=(s.top());
                s.pop();
                int ans;
                if(tokens[i]=="+")
                    ans=x1+x2;
                else if(tokens[i]=="-")
                    ans=x2-x1;
                else if(tokens[i]=="*")
                    ans=x1*x2;
                else if(tokens[i]=="/")
                    ans=x2/x1;
                
                s.push(ans);
                
            }
            else
            {
                s.push(stoi(tokens[i]));
            }
        }
        return s.top();
    }
};
class Solution {
public:
    int longestValidParentheses(string s) {
        // stack<int>st;
        // st.push(-1);
        // int ans=0;
        // for(int i=0;i<s.size();i++)
        // {
        //     if(s[i]=='(')
        //     {
        //         st.push(i);
        //     }
        //     else
        //     {
        //         st.pop();
        //         if(!st.empty())
        //         {
        //             ans=max(ans,i-st.top());
        //         }
        //         else
        //         {
        //             st.push(i);
        //         }
        //     }
        // }
        // return ans; 
        
        int ans=0;
        int open=0,close=0;
        for(char c:s)
        {
            if(c=='(')
                open++;
            else
                close++;
            
            if(open==close)
            {
                ans=max(ans,open+close);
            }
            else if(close>open)
            {
                open=close=0;
            }
        }
        open=close=0;
        int n=s.size();
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='(')
                open++;
            else
                close++;
            
            if(open==close)
            {
                ans=max(ans,open+close);
            }
            else if(close<open)
            {
                open=close=0;
            }
        }
        return ans;
    }
};
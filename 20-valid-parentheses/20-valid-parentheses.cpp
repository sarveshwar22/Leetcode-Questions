class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(char c:s)
        {
            if(c==')')
            {
                if(!st.empty() && st.top()=='(')
                {
                    if(!st.empty())
                    st.pop();
                }
                else return false;
            }
            else if(c=='}')
            {
                if(!st.empty() && st.top()=='{')
                {
                    st.pop();
                }
                else return false;
            }
            else if(c==']')
            {
                if(!st.empty() && st.top()=='[')
                {
                    st.pop();
                }
                else return false;
            }
            else 
                st.push(c);
        }
        if(!st.empty())
            return false;
        return true;
    }
};
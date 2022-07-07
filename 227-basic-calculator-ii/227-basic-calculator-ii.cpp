class Solution {
public:
    int calculate(string s) {
        stack<int>st;
        char sign='+';
        long long int res=0,tmp=0;
        for(int i=0;i<s.size();i++)
        {
            if(isdigit(s[i]))
                tmp=tmp*10+s[i]-'0';
            if(!isdigit(s[i]) && !isspace(s[i]) || i==s.size()-1)
            {
                if(sign=='-')
                    st.push(-tmp);
                else if(sign=='+')
                    st.push(tmp);
                else
                {
                    int num;
                    if(sign=='*')
                        num=st.top()*tmp;
                    else
                        num=st.top()/tmp;
                    st.pop();
                    st.push(num);
                    
                }
                sign=s[i];tmp=0;
            }
            
        }
        while(!st.empty())
        {
            res+=st.top();
            st.pop();
        }
        return res;
    }
};
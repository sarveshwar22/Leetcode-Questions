class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size();
        if(n<=1)
            return 0;
        vector<int>dp(n,0);
        int maxAns=0;
        for(int i=1;i<n;i++)
        {
            if(s[i]==')')
            {
                if(s[i-1]=='(')
                {
                    dp[i]=((i-2)>=0?dp[i-2]:0)+2;
                    maxAns=max(maxAns,dp[i]);
                }
                else
                {
                    if((i-1)-dp[i-1]>=0 && s[(i-1)-dp[i-1]]=='(' ){
                        dp[i]=dp[i-1]+2+((i-1-dp[i-1]-1)>=0 ? dp[i-1-dp[i-1]-1]:0);
                        maxAns=max(maxAns,dp[i]);
                    }
                }

            }
        }
        return maxAns;
    }
};
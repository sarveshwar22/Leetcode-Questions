class Solution {
public:
    int numDecodings(string s) {
        if(s[0]=='0')
            return 0;
        int n=s.size();
        vector<int>dp(s.size(),0);
        dp[0]=1;
        for(int i=1;i<n;i++)
        {
            if(s[i]=='0')
            {
                int number=10*(s[i-1]-'0');
                if( number>0 && number<=26)
                {
                    dp[i]=(i!=1)?dp[i-2]:1;
                }
                else
                    return 0;
            }
            else{
            int TwoDigitnumber=(s[i]-'0')+(s[i-1]-'0')*10;
            if(TwoDigitnumber>=10 && TwoDigitnumber<=26)
            {
                dp[i]=(i!=1)?dp[i-2]:1;
            }
            dp[i]+=dp[i-1];
        }
        }
        return dp[n-1];
    }
};
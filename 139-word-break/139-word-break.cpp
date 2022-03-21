class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        set<string> Dict(wordDict.begin(),wordDict.end());
        vector<bool>dp(n+1,false);
        dp[0]=true;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(dp[j] && Dict.find(s.substr(j,i-j))!=Dict.end())
                {
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[n];
    }
};
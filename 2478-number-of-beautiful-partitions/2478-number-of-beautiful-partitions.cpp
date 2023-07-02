class Solution {
    unordered_set<char>prime{'2','3','5','7'};
    int mod = 1e9+7;
    int dp[1001][1001][2];
    int dfs(string &s, int k, int minLength,int i,bool at_start,int ans=0)
    {
        if(i==s.size())
            return k==0;
        if(i>s.size())
            return 0;
        if(k==0)
            return 0;
        if(!prime.count(s[i]) && at_start)
            return 0;
        if(dp[i][k][at_start]!=-1)
        return dp[i][k][at_start];
        if(prime.count(s[i]))
        {
            if(at_start)
            {
                ans=dfs(s,k,minLength,i+minLength-1,false);
            }
            else
            {
                ans=dfs(s,k,minLength,i+1,false);
            }
        }  
        else
        {
            ans=(dfs(s,k-1,minLength,i+1,true)+dfs(s,k,minLength,i+1,false))%mod;
        }
        return dp[i][k][at_start]=ans;
    }
public:
    int beautifulPartitions(string s, int k, int minLength) {
        memset(dp,-1,sizeof dp);
        return dfs(s,k,minLength,0,true);
    }
};
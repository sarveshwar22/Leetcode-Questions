class Solution {
    vector<vector<int>> dp;
    int mod = 1e9+7;
    int memo(int d, int k)
    {
        if(d>k)
            return 0;
        if(d==k)
            return 1;
        if(dp[d][k]!=0)
            return dp[d][k]-1;
        dp[d][k]=(1+memo(abs(d-1),k-1)+memo(d+1,k-1))%mod;
        return dp[d][k]-1;
        
    }
public:
    int numberOfWays(int startPos, int endPos, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        dp=vector<vector<int>>(1005,vector<int>(1001,0));
        return memo(abs(endPos-startPos),k);
        
    }
};
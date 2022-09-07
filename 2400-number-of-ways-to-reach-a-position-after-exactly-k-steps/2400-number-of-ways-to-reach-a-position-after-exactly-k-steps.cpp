class Solution {
    vector<vector<int>> dp;
    int mod = 1e9+7;
    int memo(int d, int k)
    {
        if(d>k)
            return 0;
        if(d==k)
            return 1;
        if(dp[d][k]!=-1)
            return dp[d][k];
        dp[d][k]=(memo(abs(d-1),k-1)+memo(d+1,k-1))%mod;
        return dp[d][k];
        
    }
public:
    int numberOfWays(int startPos, int endPos, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        dp=vector<vector<int>>(1005,vector<int>(1001,-1));
        return memo(abs(endPos-startPos),k);
        
    }
};
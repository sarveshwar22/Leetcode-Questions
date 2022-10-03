class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>dp(n+1,vector<int>(target+1,0));
        dp[0][0]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=target;j++)
            {
                for(int c=1;c<=k;c++)
                {
                    if(j-c>=0)
                        dp[i][j]=(dp[i][j]+dp[i-1][j-c])%(int)(1e9+7);
                }
            }
        }
        return dp[n][target];
    }
};
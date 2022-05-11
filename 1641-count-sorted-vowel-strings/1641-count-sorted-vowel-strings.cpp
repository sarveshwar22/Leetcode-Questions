class Solution {
public:
    int countVowelStrings(int n) {
        vector<vector<int>> dp(n,vector<int>(5,1));
        dp[0][0]=1;
        dp[0][1]=2;
        dp[0][2]=3;
        dp[0][3]=4;
        dp[0][4]=5;
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<5;j++)
            {
                dp[i][j]=dp[i][j-1]+dp[i-1][j];
            }
        }
        return dp[n-1][4];
    }
};
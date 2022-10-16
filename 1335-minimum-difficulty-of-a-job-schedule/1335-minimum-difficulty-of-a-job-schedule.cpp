class Solution {
    int n;
    int dp[302][15];
    int INF = 10000;
    int dfs(int i,int d,vector<int>& jobDifficulty)
    {
        if(i==n && d==0)
            return 0;
        if(i==n || d==0)
            return INF;
        if(n-i<d)
            return INF;
        if(dp[i][d]!=-1)
            return dp[i][d];
        int ans=INF;
        int maxi=-INF;
        for(int j=i;j<n;j++)
        {
            maxi = max(maxi,jobDifficulty[j]);   //max from i to j
            ans = min(ans,maxi+dfs(j+1,d-1,jobDifficulty));  //min of all possible answers
        }
        return dp[i][d]=ans;
    }
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) 
    {
        n=jobDifficulty.size();
        if(n<d)
            return -1;
        memset(dp,-1,sizeof(dp));
        return dfs(0,d,jobDifficulty);
    }
};
class Solution {
public:
    vector<vector<int>> dp;
    vector<vector<int>> relation={{1},{0,2},{0,1,3,4},{2,4},{0}};
    int solve(int n,int v)                        
    {
        if(n==1)
            return 1;
        if(dp[n][v]!=0)
            return dp[n][v];
        for(int &i:relation[v])
            dp[n][v]+=solve(n-1,i),dp[n][v]%=(int)(1e9+7);
        return dp[n][v];
    }
    int countVowelPermutation(int n) 
    {
        int result=0;
        dp.resize(n+1,vector<int>(5,0));
        for(int i=0;i<5;i++)
            result+=solve(n,i),result%=(int)(1e9+7);
        return result;
    }
};
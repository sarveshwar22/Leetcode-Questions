class Solution {
    const int mod=1e9+7;
    vector<vector<int>> next;
    // next= {{1,2,3,4,5,6},{2,3,4,5,6},{1,3,5},{1,2,4,5},{1,3,5},{1,2,3,4,6},{1,5}};
    int dp[10001][7][7]={0};
public:
    int distinctSequences(int n) {
        next= {{1,2,3,4,5,6},{2,3,4,5,6},{1,3,5},{1,2,4,5},{1,3,5},{1,2,3,4,6},{1,5}};
        return distinctSequences(n,0,0);
    }
    int distinctSequences(int n,int prev1,int prev2) {
        if(n==0)
            return 1;
        if(dp[n][prev1][prev2])
            return dp[n][prev1][prev2];
        long long ans=0;
        for(auto x:next[prev1])
        {
            if(x!=prev2)
            {
                ans=(ans+distinctSequences(n-1,x,prev1))%mod;
            }
        }
        return dp[n][prev1][prev2]=ans;
        
    }
};
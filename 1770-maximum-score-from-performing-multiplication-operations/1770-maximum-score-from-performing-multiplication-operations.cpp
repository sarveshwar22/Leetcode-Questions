class Solution {
    int dp[1001][1001];
    int dfs(vector<int>& nums,vector<int>& mult, int i,int l,int r)
    {
        if(i==mult.size())
            return 0;
        if(dp[l][i]!=-1)
        {
            return dp[l][i];
        }
        
        int first = mult[i]*nums[l] +dfs(nums,mult,i+1,l+1,r);
        int last = mult[i]*nums[r] + dfs(nums,mult,i+1,l,r-1);
        return dp[l][i]=max(first,last);
    }
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        memset(dp,-1,sizeof(dp));
        return dfs(nums,multipliers,0,0,nums.size()-1);
    }
};
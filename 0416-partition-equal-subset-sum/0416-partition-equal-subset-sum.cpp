class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum&1)
            return false;
        
        vector<bool> dp(sum/2+1,false);
        dp[0]=true;
        for(int num:nums)
        {
            for(int j=sum/2;j>=num;j--)
            {
                if(dp[j-num])
                    dp[j]=true;
            }
        }
        return dp[sum/2];
    }
};
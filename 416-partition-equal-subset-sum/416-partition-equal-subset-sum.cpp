class Solution {
public:
    vector<int>dp;
    
    bool canPartition(vector<int>& nums) {
        dp = vector<int>(20007,-1);
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if(totalSum & 1) 
            return false;
        return subsetSum(nums, totalSum / 2);
    }
    bool subsetSum(vector<int>& nums, int sum, int i = 0) {
        if(sum == 0) 
            return true;
        if(i >= nums.size() || sum < 0)
            return false; 
        if(dp[sum] != -1) 
            return dp[sum];
        return dp[sum] = subsetSum(nums, sum - nums[i], i + 1) || subsetSum(nums, sum, i + 1);
    }
};
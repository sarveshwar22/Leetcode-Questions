class Solution {
public:
    
    int dp[10001] = {[0 ... 10000] = -1};
    
    bool canPartition(vector<int>& nums) {
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
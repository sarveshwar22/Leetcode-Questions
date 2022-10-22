class Solution {
private:
    int dp[101][2];
    int getMax(vector<int>&nums, int i, bool robFirst){
        if(i >= nums.size() || (i==nums.size()-1 && robFirst)) return 0;
        if(dp[i][robFirst]!=-1) return dp[i][robFirst];
        int rob = 0, notRob = 0; 
        if(i==0) rob = getMax(nums,i+2,1)+nums[i]; 
        else rob = getMax(nums,i+2,robFirst)+nums[i];
        notRob = getMax(nums,i+1,robFirst);
        return dp[i][robFirst] = max(rob, notRob);
    }
public:
    int rob(vector<int>& nums) {
        memset(dp, -1, sizeof dp);
        return getMax(nums, 0, 0);
    }
};
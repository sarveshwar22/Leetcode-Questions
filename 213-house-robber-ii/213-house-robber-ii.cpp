class Solution {
    int helper(vector<int>& nums,int l,int r)
    {
        int pre = 0;
        int cur = 0;
        for(int i=l;i<=r;i++)
        {
            int temp = max(pre+nums[i],cur);
            pre = cur;
            cur = temp;
        }
        return cur;
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return nums[0];
        return max(helper(nums,0,n-2),helper(nums,1,n-1));
    }
};
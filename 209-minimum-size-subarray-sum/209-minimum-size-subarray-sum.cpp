class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0;
        int r=0;
        int sum=0;
        int n=nums.size();
        int length=INT_MAX;
        while(r<n)
        {
            sum+=nums[r++];
            while(sum>=target)
            {
                length=min(r-l,length);
                sum-=nums[l++];
            }
        }
        return length==INT_MAX?0:length;
    }
};
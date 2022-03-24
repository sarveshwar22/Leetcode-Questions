class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        if(nums.size()==1 || nums[0]==0)
            return 0;
        int currEnd=nums[0];
        int maxEnd=nums[0];
        int jumps=1;
        
        for(int i=1;i<n;i++)
        {
            if(i==n-1)
                return jumps;
            maxEnd=max(maxEnd,i+nums[i]);
            if(i==currEnd)
            {
                jumps++;
                currEnd=maxEnd;
            }
        }
        return jumps;
    }
};
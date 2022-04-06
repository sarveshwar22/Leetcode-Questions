class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int currans=0;
        int maxans=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
                currans++;
            else
                currans=0;
            maxans=max(maxans,currans);
        }
        return maxans;
    }
};
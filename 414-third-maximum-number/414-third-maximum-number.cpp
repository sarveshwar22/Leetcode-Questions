class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long int highest=(long long int)INT_MIN-1;
        long long int secondHighest=(long long int)INT_MIN-1;
        long long int thirdHighest=(long long int)INT_MIN-1;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>highest)
                highest = nums[i];
        }
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>secondHighest && nums[i]!=highest)
                secondHighest = nums[i];
        }
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>thirdHighest && nums[i]!=highest && nums[i]!=secondHighest)
                thirdHighest = nums[i];
        }
        
        if(thirdHighest == (long long int)INT_MIN-1)
            return highest;
        return thirdHighest;
    }
};
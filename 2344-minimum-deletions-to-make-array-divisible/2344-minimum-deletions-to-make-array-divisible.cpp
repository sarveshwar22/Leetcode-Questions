class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        sort(nums.begin(),nums.end());
        int i=0;
        for(;i<nums.size();i++)
        {
            if(i!=0)
            {
                if(nums[i]==nums[i-1])
                    continue;
            }
            for(int num:numsDivide)
            {
                if(num%nums[i])
                    goto x;
            }
            break;
            x:;
            
        }
        if(i==nums.size())
            return -1;
        return i;
    }
};
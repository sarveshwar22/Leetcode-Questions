class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int index = abs(nums[i])-1;
            nums[index] = nums[index]>0?-nums[index]:nums[index];
        }
        vector<int> res;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0)
                res.push_back(i+1);
        }
        return res;
    }
};
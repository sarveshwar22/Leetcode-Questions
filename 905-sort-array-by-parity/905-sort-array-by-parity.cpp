class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int l=0;
        int r=nums.size()-1;
        while(l<r)
        {
            if(nums[l]%2==1)
            {
                swap(nums[l],nums[r]);
                r--;
            }
            else if(nums[r]%2==0)
            {
                swap(nums[l],nums[r]);
                l++;
            }
            else
            {
                l++;
                r--;
            }
        }
        return nums;
    }
};
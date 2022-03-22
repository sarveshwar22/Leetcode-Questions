class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int start=0;
        int end=n-1;
        while(start<end)
        {
            if(nums[start]<nums[end])
            {
                return nums[start];
            }
            int mid=(start+end)/2;
            if(nums[start]<=nums[mid])
            {
                start=mid+1;
            }
            else
            {
                end=mid;
            }
        }
        return nums[start];
    }
};
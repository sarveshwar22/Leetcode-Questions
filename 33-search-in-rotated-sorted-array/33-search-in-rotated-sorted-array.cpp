class Solution {
    int search(vector<int>& nums,int target,int start,int end)
    {
        if(start>end)
            return -1;
        int mid=(start+end)/2;
        if(nums[mid]==target)
        {
            return mid;
        }
        if(nums[start]<=nums[mid])
        {
            if(nums[start]<=target && target<=nums[mid])
            {
                return search(nums,target,start,mid-1);
                
            }
            else 
            {
                return search(nums,target,mid+1,end);
            }
        }
        else
        {
            if(nums[mid]<=target && target<=nums[end])
            {
                return search(nums,target,mid+1,end);
            }
            else
            {
                return search(nums,target,start,mid-1);
            }
        }
    }
public:
    int search(vector<int>& nums, int target) {
        return search(nums,target,0,nums.size()-1);
    }
};
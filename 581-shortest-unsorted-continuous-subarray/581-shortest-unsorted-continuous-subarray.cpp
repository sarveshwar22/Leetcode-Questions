class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=n-1;
        while(l+1<n && nums[l]<=nums[l+1])
            l++;
        if(l==n-1)
            return 0;
        while(r-1>=0 && nums[r-1]<=nums[r])
            r--;
        return lower_bound(nums.begin()+r,nums.end(),*max_element(nums.begin(),nums.begin()+r))-upper_bound(nums.begin(),nums.begin()+l,*min_element(nums.begin()+l,nums.end()));
    }
};
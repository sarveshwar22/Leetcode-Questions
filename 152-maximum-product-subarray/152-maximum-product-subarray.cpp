class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        int res=nums[0];
        for(int i=1,maxi=res,mini=res;i<nums.size();i++)
        {
            if(nums[i]<0)
                swap(maxi,mini);
            maxi=max(maxi*nums[i],nums[i]);
            mini=min(mini*nums[i],nums[i]);
            res=max(res,maxi);
        }
        return res;
    }
};
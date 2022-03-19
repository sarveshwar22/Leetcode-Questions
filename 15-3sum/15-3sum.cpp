class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        for(int i=0;i<n;i++)
        {
            int l=i+1,r=n-1;
            while(l<r)
            {
                if(nums[l]+nums[r]>-nums[i])
                    r--;
                else if(nums[l]+nums[r]<-nums[i])
                    l++;
                else
                {
                    res.push_back({nums[l],nums[r],nums[i]}); 
                    l++;
                    r--;
                    while(l<r && nums[l]==nums[l-1])l++;
                    while(l<r && nums[r]==nums[r+1])r--;
                }
            }
            while(i<n-1 && nums[i]==nums[i+1])
                i++;
        }
        return res;
    }
};
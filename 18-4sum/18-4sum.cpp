class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>>res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int left=j+1;
                int right=n-1;
                while(left<right)
                {
                    if(nums[left]+nums[right]==target-nums[i]-nums[j])
                    {
                        res.push_back({nums[i],nums[j],nums[left],nums[right]});
                        int l=nums[left];
                        int r=nums[right];
                        while(left<right && nums[left]==l)
                            left++;
                        while(left<right && nums[right]==r)
                            right--;    
                    }
                    else if(nums[left]+nums[right]>target-nums[i]-nums[j])
                        right--;
                    else
                        left++;
                }
                while(j+1<n && nums[j]==nums[j+1])
                    j++;
                
            }
            while(i+1<n && nums[i]==nums[i+1])
                i++;
        }
        return res;
    }
};
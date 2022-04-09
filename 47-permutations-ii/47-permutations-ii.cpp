class Solution {
    void permute(vector<int> nums,int start,int end,vector<vector<int>>& res)
    {
        if(start==end-1)
        {
            res.push_back(nums);
        }
        else
        {
            for(int i=start;i<end;i++)
            {
                if(i!=start && nums[start]==nums[i])
                    continue;
                swap(nums[start],nums[i]);
                permute(nums,start+1,end,res);
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        permute(nums,0,nums.size(),res);
        return res;
    }
};


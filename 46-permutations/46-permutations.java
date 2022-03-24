class Solution {
    void permute(vector<int>& nums,int pos,vector<vector<int>>&ans)
    {
        if(pos==nums.size()-1)
        {
            ans.push_back(nums);
            return;
        }
        
        for(int i=pos;i<nums.size();i++)
        {
            if(i!=pos)
            {
                swap(nums[i],nums[pos]);
                permute(nums,pos+1,ans);
                swap(nums[i],nums[pos]);
            }
            else
            {
                permute(nums,pos+1,ans);
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        permute(nums,0,ans);
        return ans;
    }
};
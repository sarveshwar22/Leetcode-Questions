class Solution {
    vector<vector<int>> adj;
    int dfs(vector<int>&nums,int i,int parent,int target)
    {
        int val = nums[i];
        for(auto child:adj[i])
        {
            if(child==parent)
            {
                continue;
            }
            val+=dfs(nums,child,i,target);
        }
        if(val==target)
            return 0;
        return val;
    }
public:
    int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
        int n=nums.size();
        adj = vector<vector<int>>(n);
        for(vector<int> &edge:edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        int sum = accumulate(nums.begin(),nums.end(),0);
        for(int p=n;p>=1;p--)
        {
            if(sum%p!=0)
                continue;
            if(dfs(nums,0,-1,sum/p)!=0)
                continue;
            return p-1;
        }
        return 0;
    }
};
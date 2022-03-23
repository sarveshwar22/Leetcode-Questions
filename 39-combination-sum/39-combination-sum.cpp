class Solution {
    void combinationSum(vector<int>& candidates,int start, int target,vector<int>&currans, vector<vector<int>>& ans)
    {
        if(target==0)
        {
            ans.push_back(currans);
        }
        for(int i=start;i<candidates.size() && target>=candidates[i];i++)
        {
            currans.push_back(candidates[i]);
            combinationSum(candidates,i,target-candidates[i],currans,ans);
            currans.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int> currAns;
        sort(candidates.begin(),candidates.end());
        combinationSum(candidates,0,target,currAns,ans);
        return ans;
    }
};
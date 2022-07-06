class Solution {
    vector<vector<int>>ans;
    vector<int> currans;
public:
    void combinationSum(vector<int>& candidates, int target,int i=0) {
        if(target==0)
        {
            ans.push_back(currans);
            return;
        }
        for(int j=i;j<candidates.size();j++)
        {
            if(i!=j && candidates[j]==candidates[j-1])
                continue;
            if(target-candidates[j]<0)
                break;
            currans.push_back(candidates[j]);
            combinationSum(candidates,target-candidates[j],j+1);
            currans.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        combinationSum(candidates,target,0);
        return ans;
    }
};
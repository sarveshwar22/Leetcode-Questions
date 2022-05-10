class Solution {
    vector<vector<int>> ans;
    void helper(int k,int n,vector<int> &combination,int num)
    {
        if(k==0)
        {
            if(accumulate(combination.begin(),combination.end(),0)==n)
            {
                ans.push_back(combination);
            }
            return;
        }
        if(num>9)
        {
            return;
        }
        
        helper(k,n,combination,num+1);
        
        combination.push_back(num);
        helper(k-1,n,combination,num+1);
        combination.pop_back();
        
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> combination;
        helper(k,n,combination,1);
        return ans;
    }
};
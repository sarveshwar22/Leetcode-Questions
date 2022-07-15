class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<bool> visited(nums.size()+1,false);
        for(int num:nums)
        {
            visited[num]=true;
        }
        vector<int> res;
        for(int i=1;i<=nums.size();i++)
        {
            if(!visited[i])
                res.push_back(i);
        }
        return res;
    }
};
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        res.push_back({});
        sort(nums.begin(),nums.end());
        for(int i=0; i<nums.size();){
            int count = 0;
            while(count + i<nums.size() && nums[count+i]==nums[i])  
                count++;
            
            int previousN = res.size();
            for(int k=0; k<previousN; k++)
            {
                vector<int> instance = res[k];
                for(int j=0; j<count; j++)
                {
                    instance.push_back(nums[i]);
                    res.push_back(instance);
                }
            }
            
            i += count;
        }
        return res;
    }
};
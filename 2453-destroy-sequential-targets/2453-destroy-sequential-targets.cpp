class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        vector<int> temp = nums;
        unordered_map<int,int> m;
        for(int& num:temp)
        {
            num%=space;
            m[num]++;
        }
        int max_count = 0;
        for(auto& ele:m)
        {
            max_count=max(max_count,ele.second);
        }
        int res = INT_MAX;
        for(int i=0;i<temp.size();i++)
        {
            if(m[temp[i]]==max_count)
                res=min(res,nums[i]);
        }
        return res;
    }
};
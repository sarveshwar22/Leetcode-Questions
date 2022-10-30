class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n,-1);
        vector<int> s1, s2, tmp;
        for(int i=0;i<n;++i)
        {
            while (!s2.empty() && nums[s2.back()] < nums[i])
            {
                res[s2.back()] = nums[i];
                s2.pop_back();
            }
            while (!s1.empty() && nums[s1.back()] < nums[i])
            {
                tmp.push_back(s1.back());
                s1.pop_back();
            }
            while (!tmp.empty())
            {
                s2.push_back(tmp.back());
                tmp.pop_back();
            }
            s1.push_back(i);
        }
        return res;
    }
};
class Solution {
    vector<int> i(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> res;
        unordered_set<int> s(nums1.begin(),nums1.end());
        for(int num:nums2)
        {
            if(s.count(num))
            {
                res.push_back(num);
                s.erase(num);
            }
        }
        return res;
    }
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()<nums2.size())
            return i(nums2,nums1);
        return i(nums1,nums2);
    }
};
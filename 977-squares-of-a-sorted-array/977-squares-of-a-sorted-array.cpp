class Solution {
    static bool cmp(int a,int b)
    {
        return a*a<b*b;
    }
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res;
        sort(nums.begin(),nums.end(),cmp);
        for(int i=0;i<nums.size();i++)
            res.push_back(nums[i]*nums[i]);
        return res;
    }
};
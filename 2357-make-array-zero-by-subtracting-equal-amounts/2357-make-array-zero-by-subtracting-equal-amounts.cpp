class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        set<int> s(nums.begin(),nums.end());
        int x=0;
        for(auto ele:s)
        {
            if(ele!=0)
                break;
            else
                x++;
        }
        return s.size()-x;
    }
};
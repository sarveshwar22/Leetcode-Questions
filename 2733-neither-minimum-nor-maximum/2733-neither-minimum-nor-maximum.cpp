class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        int maxi = *max_element(nums.begin(),nums.end());
        int mini = *min_element(nums.begin(),nums.end());
        for(int num:nums)
        {
            if(num!=mini && num!=maxi)
                return num;
        }
        return -1;
    }
};
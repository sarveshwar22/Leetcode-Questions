class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long one = (long long)INT_MIN-1;
        long long two = (long long)INT_MIN-1;
        long long three = (long long)INT_MIN-1;
        bool flag = false;
        for(int i = 0; i < nums.size();i++)
        {
            if(nums[i] > one)
            {
                three = two;
                two = one;
                one = nums[i];
            }
            else if(nums[i] > two and nums[i]!= one)
            {
                three = two;
                two = nums[i];
            }
            else if(nums[i] > three and nums[i]!=one and nums[i]!=two)
            {
                three = nums[i];
            }
         }
        if(three == (long long)INT_MIN -1) return one;
        return three;
    }
};
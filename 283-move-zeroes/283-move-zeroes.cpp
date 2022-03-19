class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int r=0;
        for(int l=0;l<nums.size();l++)
        {
            if(nums[l]!=0)
            {
                nums[r++]=nums[l];
            }   
        }
        while(r<nums.size())
            nums[r++]=0;
    }
};
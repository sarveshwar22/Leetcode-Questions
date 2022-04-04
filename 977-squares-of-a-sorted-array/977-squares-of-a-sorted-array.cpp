class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=n-1;
        vector<int>res(n);
        int i=0;
        while(l<=r)
        {
            if(abs(nums[l])>abs(nums[r]))
            {
                res[n-i-1]=nums[l]*nums[l];
                l++;
            }
            else
            {
                res[n-i-1]=nums[r]*nums[r];
                r--;
            }
            i++;
        }
        return res;
    }
};
class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long res=0;
        int n=nums.size();
        double a=nums[n-1];
        long long b;
        for(int i=n-2;i>=0;i--)
        {
            b = ceil(nums[i]/a); 
            res += (b-1);
            b = nums[i]/b;
            a = b;
        }
        return res;
    }
};
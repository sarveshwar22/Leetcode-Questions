class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans=0;
        int n=nums.size();
        int i=0;
        for(i=0;i<k;i++)
        {
            ans+=nums[i];
        }
        double res=ans;
        while(i<n)
        {
            ans+=nums[i]-nums[i-k];
            res=max(ans,res);
            i++;
        }
        
        return (double)res/k;
        
    }
};
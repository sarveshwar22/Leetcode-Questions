class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // int l=0;
        // int r=0;
        // int sum=0;
        // int n=nums.size();
        // int length=INT_MAX;
        // while(r<n)
        // {
        //     sum+=nums[r++];
        //     while(sum>=target)
        //     {
        //         length=min(r-l,length);
        //         sum-=nums[l++];
        //     }
        // }
        // return length==INT_MAX?0:length;
        
        int n=nums.size();
        vector<int> csum(n+1,0);
        int res=INT_MAX;
        for(int i=1;i<=n;i++)
        {
            csum[i]=csum[i-1]+nums[i-1];
        }
        for(int i=n;i>=0 && csum[i]>=target;i--)
        {
            int j=upper_bound(csum.begin(),csum.end(),csum[i]-target)-csum.begin();
            res=min(res,i-j+1);
        }
        return res==INT_MAX?0:res;
    }
};
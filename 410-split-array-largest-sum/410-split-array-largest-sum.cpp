class Solution {
    bool isPossible(vector<int>& nums,int m,int sum)
    {
        int csum=0;
        int cnt=0;
        for(int i=0;i<nums.size();i++)
        {
            if(csum+nums[i]<=sum)
            {
                csum+=nums[i];
            }
            else
            {
                csum=nums[i];
                cnt++;
            }
            if(cnt>=m)
                return false;
        }
        return true;
       
    }
public:
    int splitArray(vector<int>& nums, int m) {
        int n=nums.size();
        int left=*max_element(nums.begin(),nums.end()); 
        int right=accumulate(nums.begin(),nums.end(),0);
        int ans=-1;
        while(left<=right)
        {
            int mid=(left+right)/2;
            if(isPossible(nums,m,mid))
            {
                right=mid-1;
                ans=mid;
            }
            else
            {
                left=mid+1;
            }
        }
        return ans;
    }
};
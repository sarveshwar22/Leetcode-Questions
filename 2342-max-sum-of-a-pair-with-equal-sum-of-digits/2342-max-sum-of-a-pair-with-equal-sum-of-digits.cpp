class Solution {
    int sumOfDigits(int n)
    {
        int ans=0;
        while(n)
        {
            ans+=n%10;
            n/=10;
        }
        return ans;
            
    }
public:
    int maximumSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        unordered_map<int,vector<int>> m;
        for(int i=0;i<nums.size();i++)
        {
            m[sumOfDigits(nums[i])].push_back(i);
        }
        int ans=-1;
        for(auto ele:m)
        {
            if(ele.second.size()>=2)
                ans=max(ans,nums[*(ele.second.end()-1)]+nums[*(ele.second.end()-2)]);
                
        }
        if(ans==-1)
            return -1;
        return ans;
    }
};
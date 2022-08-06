class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n=nums.size();
        unordered_map<long long ,long long> m;
        
        for(int i=0;i<n;i++){
            nums[i]-=i;
            m[nums[i]]++;
        }
        long long ans=0;
        for(auto& ele:m)
        {
            if(ele.second>1)
            ans+=((long long)(ele.second)*(ele.second-1))/2;
        }
        
        
        return ((long long)n*(n-1))/2 - ans;
    }
};
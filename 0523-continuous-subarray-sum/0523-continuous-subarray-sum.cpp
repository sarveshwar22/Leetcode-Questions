class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int prefixSum = 0;
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++)
        {
            prefixSum+=nums[i];
            prefixSum%=k;
            if(prefixSum==0 && i!=0)
                return true;
            if(m.find(prefixSum)!=m.end())
            {
                if(i-m[prefixSum]>=2)
                    return true;
            }
            else
                m[prefixSum]=i;
        }
        return false;
        
    }
};
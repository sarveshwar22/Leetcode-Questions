class Solution {
    
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        vector<int> cnt(30,0);
        long long res=0;
        for(int num:unordered_set(nums.begin(),nums.end()))
            cnt[__builtin_popcount(num)]++;
        
        for(int i=1;i<30;i++)
        {
            for(int j=1;j<30;j++)
            {
                if(i+j>=k)
                    res+=cnt[i]*cnt[j];
            }
        }
        return res;
    }
};
class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        ans=0;
        prefSum=0;
        d={0:1};
        for num in nums:
            prefSum+=num;
            if (prefSum-k) in d:
                ans+=d[prefSum-k];
                
            if (prefSum) not in d:
                d[prefSum]=1;
            else:
                d[prefSum]+=1;
        return ans;
        
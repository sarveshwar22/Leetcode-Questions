class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        p=1;
        n=len(nums);
        res=[];
        for i in range(0,n):
            res.append(p);
            p*=nums[i];
        p=1;
        for i in range(n-1,-1,-1):
            res[i]*=p;
            p*=nums[i];
        return res;
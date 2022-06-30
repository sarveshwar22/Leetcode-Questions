class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int median=0;
        if(n%2)
            median = nums[n/2];
        else
            median = round((nums[n/2]+nums[n/2-1])/2.0);
        cout<<median<<endl;
        int res=0;
        for(int i=0;i<n;i++)
            res+=abs(nums[i]-median);
        return res;
    }
};
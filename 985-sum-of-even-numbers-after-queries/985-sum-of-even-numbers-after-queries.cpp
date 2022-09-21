class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum = accumulate(nums.begin(),nums.end(),0,[](int s,int num){
            return s+(num%2==0?num:0);
        });
        vector<int> res;
        for(auto q:queries)
        {
            if(nums[q[1]]%2==0)
            {
                sum-=nums[q[1]];
            }
            nums[q[1]]+=q[0];
            if(nums[q[1]]%2==0)
            {
                sum+=nums[q[1]];
            }
            res.push_back(sum);
        }
        return res;
    }
};
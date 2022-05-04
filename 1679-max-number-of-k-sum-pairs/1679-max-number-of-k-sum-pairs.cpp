class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(m[nums[i]]>0)
            {
                cnt++;
                m[nums[i]]--;
            }
            else
                m[k-nums[i]]++;
        }
        return cnt;
    }
};
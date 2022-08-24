class Solution {
public:
    long long kSum(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<long long, long long>> pq; //{sum,index}
        long long maxsum = 0;
        for (auto &x : nums)
            (x >= 0) ? maxsum += x : x *= -1;
 
        sort(nums.begin(), nums.end());
        pq.push({maxsum - nums[0], 0});
        vector<long long> ans;
        ans.push_back(maxsum);
 
        while (ans.size() < k)
        {
            auto [curr, i] = pq.top();
            pq.pop();
            ans.push_back(curr);
            if (i + 1 < n)
            {
                pq.push({curr - nums[i + 1], i + 1});
                pq.push({curr - nums[i + 1] + nums[i], i + 1});
            }
        }
        return ans[k - 1];
    }
};
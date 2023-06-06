class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(),nums.end());
        int t = k;
        long long res = 0;
        while(t--)
        {
            double top = pq.top();
            res+=top;
            pq.pop();
            pq.push(ceil(top/3));
        }
        return res;
    }
};
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int m = nums.size(), i = 0, j = m - 1, ans = 0;
        sort(nums.begin(), nums.end());
        while (i < j) {
            int sum = nums[i] + nums[j];
            if (sum == k) {
                if (nums[i] == nums[j]) {
                    int cnt = j - i + 1;
                    ans += cnt / 2;
                    break;
                } else {
                    int cnti = 1, cntj = 1;
                    ++i, --j;
                    while (i <= j && nums[i] == nums[i - 1]) {
                        ++cnti;
                        ++i;
                    }
                    while (i <= j && nums[j] == nums[j + 1]) {
                        ++cntj;
                        --j;
                    }
                    ans += min(cnti, cntj);
                }
            } else if (sum > k) {
                --j;
            } else {
                ++i;
            }
        }
        return ans;
    }
};
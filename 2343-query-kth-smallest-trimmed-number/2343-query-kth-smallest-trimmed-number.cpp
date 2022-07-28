class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), q = queries.size();
        vector<pair<string, int>> arr(n);
        
        for(int i = 0; i < n; i++) {
            arr[i] = {nums[i], i};
        }
        
        vector<int> ans(q);
        
        for(int i = 0; i < q; i++) {
            vector<pair<string, int>> temp = arr;
            for(pair<string, int>& p : temp) {
                p.first = p.first.substr(p.first.size() - queries[i][1]);
            }
            sort(temp.begin(), temp.end());
            ans[i] = temp[queries[i][0] - 1].second;
        }
        
        return ans;
    }
};
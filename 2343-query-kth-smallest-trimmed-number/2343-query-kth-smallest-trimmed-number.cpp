class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> answer;
        vector<vector<int>> mem(110, vector<int>());
        vector<int> v, temp;
        for(int i = 0; i < nums.size(); i++) v.push_back(i);
        vector<vector<int>> b(10, vector<int>());
        for (int d = (int)nums[0].length() - 1; d >= 0; d--) {
            for (int p = 0; p < v.size(); p++) {
                b[nums[v[p]][d] - '0'].push_back(v[p]);
            }
            for (int di = 0; di <= 9; di++) {
                for (int p = 0; p < b[di].size(); p++) {
                    temp.push_back(b[di][p]);
                }
                b[di].clear();
            }
            v = temp;
            temp.clear();
            mem[d] = v;
        }
        for (int i = 0; i < queries.size(); i++) {
            int l = (int)nums[0].length();
            answer.push_back(mem[l - queries[i][1]][queries[i][0] - 1]);
        }
        return answer;
    }
};
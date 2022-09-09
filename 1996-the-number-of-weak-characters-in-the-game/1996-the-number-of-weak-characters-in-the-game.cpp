class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& ps) {
    int max_d[100002] = {}, res = 0;
    for (auto &p : ps)
        max_d[p[0]] = max(max_d[p[0]], p[1]);
    for (int i = 100000; i > 0; --i)
        max_d[i - 1] = max(max_d[i - 1], max_d[i]);
    for (auto &p : ps)
        res += max_d[p[0] + 1] > p[1];
    return res;
}
};
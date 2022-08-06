class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
    unordered_map<int, long long> m;
    long long curr_day = 0;
    for (int& x: tasks) {
        curr_day += 1;
        if (m.count(x) && curr_day - m[x] <= space)
            curr_day += space - (curr_day - m[x]) + 1;
        m[x] = curr_day;
    }
    return curr_day;
}
};
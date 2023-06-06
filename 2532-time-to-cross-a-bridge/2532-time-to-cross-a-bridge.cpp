class Solution {
public:
    typedef pair<int, int> pii;
    int findCrossingTime(int n, int k, vector<vector<int>>& time) {
        // After sorting, the order of the indexes is the order of selection
        stable_sort(time.begin(), time.end(), [](auto& x, auto& y) -> bool {
            return x[0] + x[2] < y[0] + y[2];
        });
        priority_queue<int> lwait, rwait;
        for (int i = 0; i < k; ++i) lwait.push(i);
        // Maintain the finish time and index
        priority_queue<pii, vector<pii>, greater<pii>> lwork, rwork;
        int t = 0;
        while (n || rwait.size() || rwork.size()) {
            // Before t, these workers have finished their work
            // Collect them and insert into waitlist
            while (lwork.size() && lwork.top().first <= t) {
                lwait.push(lwork.top().second);
                lwork.pop();
            }
            while (rwork.size() && rwork.top().first <= t) {
                rwait.push(rwork.top().second);
                rwork.pop();
            }

            if (rwait.size() > 0) {
                // Choose the rightside workers at first
                int c = rwait.top();
                rwait.pop();
                // Restart to wait after cross and work
                lwork.push(pii(t + time[c][2] + time[c][3], c));
                // Bridge return to idle after worker crossed
                t += time[c][2];
            }
            else {
                // Nobody waiting in rightside, choose leftside workers
                if (n == 0) {
                    // No need to schedule leftside worker
                    // Advance directly to the next worker to complete
                    t = rwork.top().first; 
                }
                else {
                    if (lwait.size() > 0) {
                        // There are workers waiting in leftside 
                        int c = lwait.top();
                        lwait.pop();
                        // Restart to wait after cross and work
                        rwork.push(pii(t + time[c][0] + time[c][1], c));
                        // Bridge return to idle after worker crossed
                        t += time[c][0];
                        n--;
                    }
                    else {
                        // Choose the earlier complete time
                        int u = lwork.size() ? lwork.top().first : INT_MAX;
                        int v = rwork.size() ? rwork.top().first : INT_MAX;
                        t = min(u, v);
                    }
                }
            }
        }
        return t;
    }
};